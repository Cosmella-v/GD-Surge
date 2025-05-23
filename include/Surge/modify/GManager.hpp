#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/GManager.hpp>

class $modify(MyGManager, GManager) {
public:
    $override
    void setup();
};