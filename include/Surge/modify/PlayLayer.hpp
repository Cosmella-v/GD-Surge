#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    $override
    void levelComplete();
    // void onQuit();
    void showHint();
};
