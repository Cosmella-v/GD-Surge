#include <Surge/layers/IslandSelectLayer.h>
#include <Surge/modify/LevelPage.hpp>

using namespace geode::prelude;

void MyLevelPage::onInfo(CCObject* sender) {
    if (m_level->m_levelID.value() == -1) {
        if (AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04")) {
            return FLAlertLayer::create(
                nullptr,
                "It was a secret...",
                "<cr>You shattered</c> what was meant to endure. <cg>No silence</c> remains, only <co>ashes</c> of a hidden world.\n\n'Tis to be released anon.",
                "OK", nullptr, 360
            )->show();
        } else {
            return FLAlertLayer::create(
                nullptr,
                "It's a secret...",
                "<cl>Something</c> lies beneath the <cg>surface</c>... a <co>fracture</c> waiting to <cj>happen</c>.",
                "OK", nullptr, 360
            )->show();
        }
    } else if (m_level->m_levelID.value() == -3) {
        return FLAlertLayer::create(
            "The Islands",
            "<cb>The Islands</c> are not what they seem. Silence walks there, not sound. <co>Heed this warning</c>: Those who seek them <cj>rarely</c> speak again.",
            "OK"
        )->show();
    }
    LevelPage::onInfo(sender);
}

void MyLevelPage::updateDynamicPage(GJGameLevel* level) {
    LevelPage::updateDynamicPage(level);

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    queueInMainThread([this, level, winSize]() {
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        if (!scene) return;

        auto layer = scene->getChildByType<LevelSelectLayer*>(0);
        if (!layer) return;

        auto label = typeinfo_cast<CCLabelBMFont*>(getChildByID("coming-soon-label"));
        bool hasAch = AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04");

        if (label) {
            label->setVisible(m_level->m_levelID == -1 && !hasAch);
        }

        if (auto oldNode = getChildByID("coming-never-node")) {
            oldNode->removeFromParent();
        }

        switch (level->m_levelID) {
            case -1: {
                if (hasAch && Mod::get()->getSettingValue<bool>("shattered-code") && label) {
                    auto comingNeverNode = CCMenu::create();
                    comingNeverNode->setID("coming-never-node");
                    comingNeverNode->setPosition(label->getPosition());

                    auto bg = createLayerBG();
                    bg->setZOrder(-1);
                    bg->setColor({ 0, 0, 0 });
                    bg->setScaleX(winSize.width / bg->getContentSize().width);
                    bg->setScaleY(winSize.height / bg->getContentSize().height);
                    bg->setPosition(-comingNeverNode->getPosition());
                    comingNeverNode->addChild(bg);

                    auto comingText = CCLabelBMFont::create("Coming", "bigFont.fnt");
                    comingText->setPosition({ -winSize.width * 0.3f, 0.f });

                    auto neverText = CCLabelBMFont::create("Never...", "bigFont.fnt");
                    neverText->setPosition({ winSize.width * 0.3f, -winSize.height * 0.2f });
                    neverText->setRotation(65.f);

                    auto zigzag1 = CCSprite::createWithSpriteFrameName("GDS_zigzag.png"_spr);
                    float scale1 = winSize.height / zigzag1->getContentSize().height;
                    zigzag1->setScale(scale1);
                    float zigzag1X = comingText->getPositionX() + (zigzag1->getContentSize().width * scale1) / 2.f;
                    zigzag1->setPosition({ zigzag1X + 60.f, 0.f });

                    auto zigzag2 = CCSprite::createWithSpriteFrameName("GDS_zigzag.png"_spr);
                    float scale2 = winSize.height / zigzag2->getContentSize().height;
                    zigzag2->setScale(scale2);
                    zigzag2->setFlipY(true);
                    float zigzag2X = neverText->getPositionX() - (zigzag2->getContentSize().width * scale2) / 2.f;
                    zigzag2->setPosition({ zigzag2X - 40.f, 0.f });

                    auto diffFace = CCSprite::createWithSpriteFrameName("difficulty_00_btn_001.png");
                    diffFace->setPosition({ 0, 0 });

                    auto star = CCSprite::createWithSpriteFrameName("star_small01_001.png");
                    star->setPosition({ -5.f, -30.f });

                    auto starCount = CCCounterLabel::create(3, "bigFont.fnt", FormatterType::Integer);
                    starCount->setScale(0.4);
                    starCount->setAnchorPoint({ 0.f, 0.5f });
                    starCount->setPosition({ 2.5f, -30.f });

                    auto playBtn2Spr = CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png");
                    auto playBtn = CCMenuItemSpriteExtra::create(
                        playBtn2Spr,
                        this,
                        menu_selector(LevelPage::onPlay)
                    );
                    playBtn->setTag(1);
                    playBtn->setPosition({ 0.f, -75.f });
                    
                    this->addChild(playBtn);

                    comingNeverNode->addChild(diffFace);
                    comingNeverNode->addChild(star);
                    comingNeverNode->addChild(starCount);
                    comingNeverNode->addChild(playBtn);
                    comingNeverNode->addChild(comingText);
                    comingNeverNode->addChild(neverText);
                    comingNeverNode->addChild(zigzag1);
                    comingNeverNode->addChild(zigzag2);

                    addChild(comingNeverNode);
                }
                break;
            }

            case -3: {
                if (!getChildByID("islands-menu"_spr)) {
                    auto logo = CCSprite::createWithSpriteFrameName("islandsLogo.png"_spr);
                    logo->setScale(0.75f);

                    auto logoBtn = CCMenuItemSpriteExtra::create(
                        logo,
                        this,
                        menu_selector(MyLevelPage::onIslands)
                    );
                    logoBtn->setPosition({ winSize.width / 2.f, winSize.height * 2.f / 3.f });

                    auto menu = CCMenu::create();
                    menu->addChild(logoBtn);
                    menu->setPosition({ 0, 0 });
                    menu->setID("islands-menu"_spr);
                    addChild(menu);
                }
                break;
            }

            default:
                break;
        }

        if (level->m_levelID != -3) {
            if (auto menu = getChildByID("islands-menu"_spr)) {
                menu->removeFromParent();
            }
        }

        m_isBusy = (level->m_levelID < 0 && (level->m_levelID != -3 || level->m_levelID != -1));
    });
}

void MyLevelPage::onIslands(CCObject*) {
    auto scene = IslandSelectLayer::scene(0);
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}

void MyLevelPage::onPlay(CCObject* sender) {
    if (m_level->m_levelID == -3) {
        onIslands(sender);
        return;
    } else if (m_level->m_levelID == -1) {
        auto level = LevelTools::getLevel(m_level->m_levelID, false);
        auto scene = PlayLayer::scene(level, false, false);
        auto transition = CCTransitionFade::create(0.5f, scene);
        CCDirector::sharedDirector()->pushScene(transition);
    }

    LevelPage::onPlay(sender);
}