#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer.hpp>

class $modify(MySecretLayer, SecretLayer) {
    $override
    void onSubmit(CCObject* sender);
    bool init();
};