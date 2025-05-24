#include <Surge/modify/FollowRewardPage.hpp>
#include <Utils.hpp>

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

void MyFollowRewardPage::FLAlert_Clicked(FLAlertLayer* alert, bool confirmed) {
    if (!confirmed)
        return;

    int buttonIdx = alert->getTag() - 1;
    auto gm = GameManager::sharedState();
    auto gsm = GameStatsManager::sharedState();

    switch (buttonIdx) {
        case 0:
            GDSFollowLinks::onYouTube();
            gm->reportAchievementWithID("geometry.ach.youtube", 100, false);
            gsm->unlockSpecialChest("22");
            gm->setUGV("22", true);
            break;
        case 1:
            GDSFollowLinks::onTwitter();
            gm->reportAchievementWithID("geometry.ach.twitter", 100, false);
            gsm->unlockSpecialChest("24");
            gm->setUGV("24", true);
            break;
        case 2:
            GDSFollowLinks::onFacebook();
            gm->reportAchievementWithID("geometry.ach.facebook", 100, false);
            gsm->unlockSpecialChest("23");
            gm->setUGV("23", true);
            break;
        case 3:
            GDSFollowLinks::onTwitch();
            gm->reportAchievementWithID("geometry.ach.twitch", 100, false);
            gsm->unlockSpecialChest("26");
            gm->setUGV("26", true);
            break;
        case 4:
            GDSFollowLinks::onDiscord();
            gm->reportAchievementWithID("geometry.ach.discord", 100, false);
            gsm->unlockSpecialChest("27");
            gm->setUGV("27", true);
            break;
        case 5:
            GDSFollowLinks::onReddit();
            gm->reportAchievementWithID("geometry.ach.reddit", 100, false);
            gsm->unlockSpecialChest("32");
            gm->setUGV("32", true);
            break;
        default:
            break;
    }
}