#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelSelectLayer, LevelSelectLayer) {
public:
    $override
    bool init(int pageID);

    $override
    ccColor3B colorForPage(int pageID);
};