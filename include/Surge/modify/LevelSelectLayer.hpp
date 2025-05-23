#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>

class $modify(MyLevelSelectLayer, LevelSelectLayer) {
public:
    $override
    bool init(int pageID);

    $override
    cocos2d::ccColor3B colorForPage(int pageID);
};