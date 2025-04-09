#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/OptionsLayer.hpp>

class $modify(MyOptionsLayer, OptionsLayer) {
public:
    $override
    void onAccount(CCObject* sender);
    void onSecretVault(CCObject* sender);
};