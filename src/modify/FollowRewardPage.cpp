#include "Geode/ui/Popup.hpp"
#include <Surge/modify/FollowRewardPage.hpp>
#include <Utils.hpp>

using namespace geode::prelude;

bool MyFollowRewardPage::init() {
    if (!FollowRewardPage::init())
        return false;

    if (auto layer = this->getChildByType<CCLayer*>(0)) {
        if (auto title = layer->getChildByType<CCLabelBMFont*>(0)) {
            title->setString("Follow OmgRod!");
        }
    }

    return true;
}

void MyFollowRewardPage::onSpecialItem(CCObject* sender) {
    auto item = dynamic_cast<CCMenuItemSpriteExtra*>(sender);
    if (!item) return;

    auto gm = GameManager::sharedState();
    auto gsm = GameStatsManager::sharedState();

    m_fields->m_specialID = sender->getTag();

    std::string chestTypeStr;
    std::string serviceName;
    std::string unlockMessage;
    std::string actionButtonText;

    if (m_fields->m_specialID <= 0 || m_fields->m_specialID > 6) {
        return;
    }

    GameManager* gameMgr = GameManager::sharedState();

    bool isUnlocked = false;
    switch (m_fields->m_specialID) {
        case 1:
            chestTypeStr = "YouTube";
            serviceName = "YouTube";
            unlockMessage = "Subscribe to OmgRod on <cr>YouTube</c> to unlock this chest!";
            actionButtonText = "Sub!";
            isUnlocked = gameMgr->getUGV("22") != 0;
            break;

        case 2:
            chestTypeStr = "Twitter";
            serviceName = "Twitter";
            unlockMessage = "Follow OmgRod on <cj>Twitter</c> to unlock this chest!";
            actionButtonText = "Follow!";
            isUnlocked = gameMgr->getUGV("24") != 0;
            break;

        case 3:
            chestTypeStr = "Facebook";
            serviceName = "Facebook";
            unlockMessage = "Like OmgRod on <cb>Facebook</c> to unlock this chest!";
            actionButtonText = "Like!";
            isUnlocked = gameMgr->getUGV("23") != 0;
            break;

        case 4:
            chestTypeStr = "Twitch";
            serviceName = "Twitch";
            unlockMessage = "Follow OmgRod on <ca>Twitch</c> to unlock this chest!";
            actionButtonText = "Follow!";
            isUnlocked = gameMgr->getUGV("26") != 0;
            break;

        case 5:
            chestTypeStr = "Discord";
            serviceName = "Discord";
            unlockMessage = "Join OmgRod on <ca>Discord</c> to unlock this chest!";
            actionButtonText = "Join!";
            isUnlocked = gameMgr->getUGV("27") != 0;
            break;

        case 6:
            chestTypeStr = "Reddit";
            serviceName = "Reddit";
            unlockMessage = "Join OmgRod on <cr>Reddit</c> to unlock this chest!";
            actionButtonText = "Join!";
            isUnlocked = gameMgr->getUGV("32") != 0;
            break;
    }

    if (!isUnlocked) {
        createQuickPopup(
            chestTypeStr.c_str(),
            unlockMessage,
            "Cancel",
            actionButtonText.c_str(),
            360.f,
            [&](auto layer, bool btn2) {
                if (btn2) {
                    this->onSpecialItemConfirm();
                }
            }
        );

        if (isUnlocked) {
            switchToOpenedState(item);
        }
    } else {
        GameStatsManager* statsMgr = GameStatsManager::sharedState();

        GJRewardItem* reward = statsMgr->unlockSpecialChest(chestTypeStr);

        if (reward != nullptr) {
            switchToOpenedState(item);

            RewardUnlockLayer* rewardLayer = RewardUnlockLayer::create(reward->m_uID, typeinfo_cast<RewardsPage*>(this->getParent()));
            this->addChild(rewardLayer, 100);
            rewardLayer->showCollectReward(reward);
        }
    }
}

void MyFollowRewardPage::onSpecialItemConfirm() {
    auto gm = GameManager::sharedState();
    auto gsm = GameStatsManager::sharedState();

    switch (m_fields->m_specialID) {
        case 1:
            GDSFollowLinks::onYouTube();
            gm->reportAchievementWithID("geometry.ach.youtube", 100, false);
            gsm->unlockSpecialChest("22");
            gm->setUGV("22", true);
            break;
        case 2:
            GDSFollowLinks::onTwitter();
            gm->reportAchievementWithID("geometry.ach.twitter", 100, false);
            gsm->unlockSpecialChest("24");
            gm->setUGV("24", true);
            break;
        case 3:
            GDSFollowLinks::onFacebook();
            gm->reportAchievementWithID("geometry.ach.facebook", 100, false);
            gsm->unlockSpecialChest("23");
            gm->setUGV("23", true);
            break;
        case 4:
            GDSFollowLinks::onTwitch();
            gm->reportAchievementWithID("geometry.ach.twitch", 100, false);
            gsm->unlockSpecialChest("26");
            gm->setUGV("26", true);
            break;
        case 5:
            GDSFollowLinks::onDiscord();
            gm->reportAchievementWithID("geometry.ach.discord", 100, false);
            gsm->unlockSpecialChest("27");
            gm->setUGV("27", true);
            break;
        case 6:
            GDSFollowLinks::onReddit();
            gm->reportAchievementWithID("geometry.ach.reddit", 100, false);
            gsm->unlockSpecialChest("32");
            gm->setUGV("32", true);
            break;
    }
}