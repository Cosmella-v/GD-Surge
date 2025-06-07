#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelSelectLayer, LevelSelectLayer) {
public:
    $override
    bool init(int pageID);

    $override
    #ifndef GEODE_IS_IOS
    ccColor3B colorForPage(int pageID);
    #endif
};