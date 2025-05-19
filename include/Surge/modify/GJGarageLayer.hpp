#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>

class $modify(MyGJGarageLayer, GJGarageLayer) {
public:
    $override
    bool init();
    void showUnlockPopup(int p0, UnlockType p1);
    void onShop(CCObject* sender);
};