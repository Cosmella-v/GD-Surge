#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/AchievementManager.hpp>

class $modify(MyAchievementManager, AchievementManager) {
public:
    $override
    void addManualAchievements();
};