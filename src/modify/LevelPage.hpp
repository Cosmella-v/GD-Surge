#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelPage.hpp>

class $modify(MyLevelPage, LevelPage) {
public:
    void updateDynamicPage(GJGameLevel* level);
};
