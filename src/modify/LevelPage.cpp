#include <Surge/modify/LevelPage.hpp>

void MyLevelPage::onInfo(CCObject* sender) {
    if(m_level->m_levelID.value() == -1) {
        if (AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04")) {
            return FLAlertLayer::create(nullptr, "It was a secret...", "<cr>You shattered</c> what was meant to endure.<d050> <cg>No silence</c> remains,<d050> only <co>ashes</c> of a hidden world.", "OK", nullptr, 360)->show();            
        } else {
            return FLAlertLayer::create(nullptr, "It's a secret...", "<cl>Something</c> lies beneath the <cg>surface</c>... a <co>fracture</c> waiting to <cj>happen</c>.", "OK", nullptr, 360)->show();
        }
    }
    LevelPage::onInfo(sender);
}

bool MyLevelPage::init(GJGameLevel* level) {
    if (!LevelPage::init(level)) {
        return false;
    }

    // if (level->m_levelID.value() == -1) {
    //     // something here..?
    // }

    return true;
}