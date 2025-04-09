#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>

class $modify(MyGameStatsManager, GameStatsManager) {
    bool isItemUnlocked(UnlockType p0, int p1);
};