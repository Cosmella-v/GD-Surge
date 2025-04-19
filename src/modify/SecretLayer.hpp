#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer.hpp>

using namespace geode::prelude;

class $modify(MySecretLayer, SecretLayer) {
    $override
    void onSubmit(CCObject* sender);
    bool init();

    // Static members
    static int lastIndex;
    static std::vector<std::string> messages;

    // Vault codes with conditions and riddles
    struct VaultCode {
        std::string code;
        std::function<CCArray*()> riddle;
        std::function<bool()> condition;
        const char* successText;
        std::function <void()> onSuccess;
    };
    static std::vector<VaultCode> vaultCodes;
    static std::unordered_map<std::string, int> riddleProgress;
};
