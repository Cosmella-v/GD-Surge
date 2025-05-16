#include <Surge/modify/MenuLayer.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/loader/Event.hpp>

float speed = 1.0f;
float delaySetting = 0.0f;
float addtlDuration = 0.0f;

bool stopLooping = false;
bool jumpedAlready = false;

bool MyMenuLayer::init() {
    if (!MenuLayer::init()) {
        return false;
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

	static bool downloadStarted = false;
    if (!downloadStarted) {
        downloadStarted = true;

        static EventListener<web::WebTask> s_listener;
        auto musicDownloadURL = "https://raw.githubusercontent.com/OmgRod/GD-Surge/refs/heads/master/music.zip";

        web::WebRequest request;
        auto task = request.get(musicDownloadURL);
        s_listener.setFilter(task);

        s_listener.bind([=](web::WebTask::Event* e) {
            if (!e) {
                log::error("Event is null");
                return;
            }

            if (e->isCancelled()) {
                FLAlertLayer::create("Error", "Download was cancelled.", "OK")->show();
                return;
            }

            if (web::WebResponse* res = e->getValue()) {
                if (!res->ok()) {
                    FLAlertLayer::create("Error", "Failed to download music.zip (bad response).", "OK")->show();
                    return;
                }

                auto data = res->data();
                auto mod = Mod::get();
                if (!mod) {
                    log::error("Mod instance is null");
                    return;
                }

                auto saveDir = mod->getSaveDir();
                auto zipPath = saveDir / "music.zip";

                if (!geode::utils::file::writeBinary(zipPath, data)) {
                    FLAlertLayer::create("Error", "Failed to save music.zip to disk.", "OK")->show();
                    return;
                }

                auto unzip = geode::utils::file::Unzip::create(zipPath);
                if (unzip.isErr()) {
                    FLAlertLayer::create("Error", "Failed to unzip music.zip.", "OK")->show();
                    return;
                }

                auto& archive = unzip.unwrap();
                auto result = archive.extractAllTo(saveDir);
                if (!result.isOk()) {
                    FLAlertLayer::create("Error", "Failed to extract music files.", "OK")->show();
                    return;
                }

                log::info("music.zip downloaded and extracted successfully.");
            }
            else if (web::WebProgress* progress = e->getProgress()) {
                log::info("Download progress: {:.1f}%", progress->downloadProgress().value_or(0.0f) * 100.f);
            }
            else {
                log::warn("Unknown web::WebTask::Event state");
            }
        });
    }

    return true;
}
