#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>

class $modify(MyGameManager, GameManager) {
    // gd::string sheetNameForIcon(int iconID, int iconType);
    cocos2d::CCTexture2D* loadIcon(int iconID, int iconType, int _idk);

    $override
    void dataLoaded(DS_Dictionary*);
};