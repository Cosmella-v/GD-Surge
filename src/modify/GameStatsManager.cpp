#include <Surge/modify/GameStatsManager.hpp>

using namespace geode::prelude;

bool MyGameStatsManager::isItemUnlocked(UnlockType p0, int p1) {
    if (GameStatsManager::isItemUnlocked(p0, p1))
            return true;

    // if (p0 == UnlockType::GJItem && p1 >= 1 && p1 <= 4) {
    //     return true;
    // }

    return false;
}

void MyGameStatsManager::checkCoinAchievement(GJGameLevel* level) {
    auto GM = GameManager::sharedState();

    int coinPercent = (getCollectedCoinsForLevel(level) / 3.f) * 100.f;
    auto achievementID = fmt::format("geometry.ach.surge.levelcoin{:02}", level->m_levelID.value());

    if(level->m_levelType == GJLevelType::Local) {
        GM->reportAchievementWithID(achievementID.c_str(), coinPercent, false);
    }
}