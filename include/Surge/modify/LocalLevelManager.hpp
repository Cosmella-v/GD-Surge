#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LocalLevelManager.hpp>

class $modify(MyLocalLevelManager, LocalLevelManager) {
public:
    $override
    gd::string getMainLevelString(int id);
};