#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer.hpp>

using namespace geode::prelude;

class $modify(MySecretLayer, SecretLayer) {
    $override
    void onSubmit(CCObject* sender);
    bool init();

    static int lastIndex;
    static std::vector<std::string> messages;

    struct VaultCode {
        std::string code;
        std::function<CCArray*()> riddle;
        std::function<bool()> condition;
        std::function<const char*()> successText;
        std::function<void()> onSuccess;
    };
    static std::vector<VaultCode> vaultCodes;
    static std::unordered_map<std::string, int> riddleProgress;

    struct Fields {
        bool isRiddle = false;
        int normalMessages = 0;
        int currentRiddleIndex = 0;
        int selectedRiddleIndex = -1;
    };
};
