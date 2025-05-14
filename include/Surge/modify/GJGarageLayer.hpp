#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>

class $modify(MyGJGarageLayer, GJGarageLayer) {
public:
    $override
    void showUnlockPopup(int p0, UnlockType p1);
};