#include "GameStatsManager.hpp"

using namespace geode::prelude;

bool MyGameStatsManager::isItemUnlocked(UnlockType p0, int p1) {
    if (GameStatsManager::isItemUnlocked(p0, p1))
            return true;

    if (p0 == UnlockType::GJItem && p1 >= 1 && p1 <= 4) {
        return true;
    }

    return false;
}