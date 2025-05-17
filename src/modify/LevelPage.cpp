#include "Geode/binding/FLAlertLayer.hpp"
#include <Surge/modify/LevelPage.hpp>

using namespace geode::prelude;

void MyLevelPage::onInfo(CCObject* sender) {
    if(m_level->m_levelID.value() == -1) {
        if (AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04")) {
            return FLAlertLayer::create(nullptr, "It was a secret...", "<cr>You shattered</c> what was meant to endure.<d050> <cg>No silence</c> remains,<d050> only <co>ashes</c> of a hidden world.\n\n'Tis to be released anon.", "OK", nullptr, 360)->show();            
        } else {
            return FLAlertLayer::create(nullptr, "It's a secret...", "<cl>Something</c> lies beneath the <cg>surface</c>... a <co>fracture</c> waiting to <cj>happen</c>.", "OK", nullptr, 360)->show();
        }
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

        auto label = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("coming-soon-label"));

        switch (level->m_levelID) {
            case -1:
                if (label) {
                    bool hasAch = AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04");
                    label->setString(hasAch ? "Coming Never..." : "Coming Soon!");
                    label->setAnchorPoint({0.5f, 0.5f});
                    label->setPositionX(layer->getContentSize().width / 2);
                }
                break;

            case -3:
                if (!this->getChildByID("islands-menu"_spr)) {
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
                    menu->setPosition({0, 0});
                    menu->setID("islands-menu"_spr);
                    this->addChild(menu);
                }
                break;

            default:
                break;
        }

        if (level->m_levelID != -3) {
            if (auto menu = this->getChildByID("islands-menu"_spr)) {
                menu->removeFromParent();
            }
        }

        m_isBusy = level->m_levelID < 0;
        if (label) {
            label->setVisible(level->m_levelID == -1);
        }
    });
}

void MyLevelPage::onIslands(CCObject*) {
    FLAlertLayer::create(
        "The Islands",
        "This <cg>feature</c> is a <cb>work in progress</c> and is not yet available. Sorry for the inconvenience.",
        "OK"
    )->show();
}