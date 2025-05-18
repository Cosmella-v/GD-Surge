#include <Surge/modify/MenuLayer.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/loader/Event.hpp>

float speed = 1.0f;
float delaySetting = 0.0f;
float addtlDuration = 0.0f;

bool stopLooping = false;
bool jumpedAlready = false;

bool downloadStarted = false;

bool startup = false;

bool MyMenuLayer::init() {
    if (!MenuLayer::init()) {
        return false;
    }

    auto socialMenu = this->getChildByID("social-media-menu");
    if (socialMenu) {
        auto button = socialMenu->getChildByID("robtop-logo-button");
        if (button) {
            auto sprite = button->getChildByType<CCSprite*>(0);
            if (sprite) {
                sprite->setDisplayFrame(CCSpriteFrameCache::get()->spriteFrameByName("omgrodLogo_01.png"_spr));
                sprite->setScale(0.55f);
            }
        }
    }

    auto logo = this->getChildByID("main-title");
    auto spriteLogo = typeinfo_cast<CCSprite*>(logo);
    if (spriteLogo && !(Loader::get()->getLoadedMod("ninxout.redash"))) {
        CCSprite* surgeLogo = CCSprite::createWithSpriteFrameName("surgeLogo_001.png"_spr);
        surgeLogo->setID("surge-logo");
        CCRect logoBounds = spriteLogo->boundingBox();
        surgeLogo->setAnchorPoint({1.0f, 1.0f});
        surgeLogo->setPosition(ccp(logoBounds.getMaxX() - 2.f, logoBounds.getMinY() - 1.5f));
        this->addChild(surgeLogo);

        std::string nodeChosenByYAMM = "this-mod-doesnt-assign-node-ids-to-anything-lmfao"_spr;

        auto fodsAnimMod = Loader::get()->getLoadedMod("raydeeux_hjfod.fodsmenuanimations");

        if (fodsAnimMod && fodsAnimMod->getSettingValue<bool>("enabled") &&
            (!(!surgeLogo->getID().empty() && surgeLogo->getID() == nodeChosenByYAMM))) {

            float animSpeed = std::clamp(speed, 0.01f, 16.0f);
            float animDelay = std::clamp(delaySetting, 0.0f, 10.0f);
            float animDuration = std::clamp(addtlDuration, 0.0f, 2.0f);

            CCDelayTime* delay = CCDelayTime::create((0.25f / animSpeed) + animDelay);
            CCEaseBackOut* eboScale = CCEaseBackOut::create(CCScaleTo::create((2.0f / animSpeed) + animDuration, 1.f));
            CCSequence* titleSequence = CCSequence::create(delay, eboScale, nullptr);

            surgeLogo->setScale(0.f);
            surgeLogo->runAction(titleSequence);
        }
    }

    if (!Mod::get()->getSettingValue<bool>("disable-warning-popup") && !startup) {
        this->scheduleOnce(SEL_SCHEDULE(&MyMenuLayer::onStartupPopup), 0.1f);
    }

    if (!downloadStarted) {
        downloadStarted = true;

        static EventListener<web::WebTask> s_listener;
        auto musicDownloadURL = "https://raw.githubusercontent.com/OmgRod/GD-Surge/master/music.zip";

        web::WebRequest request;
        auto task = request.get(musicDownloadURL);
        s_listener.setFilter(task);
        s_listener.bind([&](web::WebTask::Event* e) {
            if (!e || e->isCancelled()) {
                geode::Notification::create("Download was cancelled", NotificationIcon::Error)->show();
                return;
            }

            if (web::WebResponse* res = e->getValue()) {
                if (!res->ok()) {
                    geode::Notification::create("Failed to download music.zip.", NotificationIcon::Error)->show();
                    return;
                }

                auto data = res->data();
                auto mod = Mod::get();
                if (!mod) {
                    log::error("Mod instance is null");
                    return;
                }

                auto zipPath = mod->getSaveDir() / "music.zip";
                std::error_code ec;

                if (!geode::utils::file::writeBinary(zipPath, data, ec)) {
                    log::error("Failed to write music.zip to disk: {}", ec.message());
                    geode::Notification::create("Failed to save music.zip to disk.", NotificationIcon::Error)->show();
                    return;
                }

                auto unzip = geode::utils::file::Unzip::create(zipPath);
                if (unzip.isErr()) {
                    log::error("Unzip creation failed: {}", unzip.unwrapErr());
                    geode::Notification::create("Failed to unzip music.zip.", NotificationIcon::Error)->show();
                    return;
                }

                auto& archive = unzip.unwrap();
                if (!archive.extractAllTo(mod->getSaveDir(), ec).isOk()) {
                    log::error("Extraction failed: {}", ec.message());
                    geode::Notification::create("Failed to extract music files.", NotificationIcon::Error)->show();
                    return;
                }

                log::info("music.zip downloaded and extracted successfully.");
                geode::Notification::create("Music successfully downloaded!", NotificationIcon::Success)->show();

                queueInMainThread([=]() {
                    std::error_code removeEc;
                    if (!std::filesystem::remove(zipPath, removeEc)) {
                        log::warn("Failed to remove music.zip: {}", removeEc.message());
                    }
                });
            }
        });
    }

    startup = true;

    return true;
}

void MyMenuLayer::onCreator(CCObject* sender) {
    #ifdef GITHUB_ACTIONS
    FLAlertLayer::create("Creator", "This feature is <cr>disabled</c>. To <cg>enable</c> it, please disable this mod. Sorry for the inconvenience.", "OK")->show();
    #else
    MenuLayer::onCreator(sender);
    #endif
}

void MyMenuLayer::onStartupPopup(float dt) {
    auto mod = Mod::get();
    auto tag = mod->getVersion().getTag();
    bool isAlpha = mod->getVersion().toVString(true).find("alpha") != std::string::npos;

    std::string message;
    if (isAlpha) {
        message =
            "1. This mod is currently in <co>alpha</c>. Bugs and instability are expected. "
            "Please report any issues on our <cy>[GitHub issue tracker](https://github.com/OmgRod/GD-Surge/issues)</c>.\n\n"
            "2. Surge uses a separate save file, so your original data is safe. "
            "However, we recommend backing up your original save just in case. "
            "To restore your original save, simply disable this mod.\n\n"
            "You may disable this popup in the mod settings.\n\n"
            "Thank you for trying Surge!";
    } else {
        message =
            "Surge uses a separate save file, so your original data is safe. "
            "However, we recommend backing up your original save just in case. "
            "To restore your original save, simply disable this mod.\n\n"
            "You may disable this popup in the mod settings.\n\n"
            "Thank you for trying Surge!";
    }
    MDPopup::create("Warning", message, "OK")->show();
}

void MyMenuLayer::onTwitch(CCObject* sender) {
    CCApplication::sharedApplication()->openURL("https://www.twitch.tv/omgrod1000");
}

void MyMenuLayer::onTwitter(CCObject* sender) {
    CCApplication::sharedApplication()->openURL("https://x.com/0mgrod");
}

void MyMenuLayer::onDiscord(CCObject* sender) {
    CCApplication::sharedApplication()->openURL("https://discord.gg/vK3DuqJwyW");
}

void MyMenuLayer::onFacebook(CCObject* sender) {
    FLAlertLayer::create("nope", "i'm not a boomer", "OK")->show();
}

void MyMenuLayer::onRobTop(CCObject* sender) {
    CCApplication::sharedApplication()->openURL("https://omgrod.me");
}

void MyMenuLayer::onYouTube(CCObject* sender) {
    CCApplication::sharedApplication()->openURL("https://www.youtube.com/@OmgRodYT");
}