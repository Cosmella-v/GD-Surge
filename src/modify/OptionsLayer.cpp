#include <Geode/Geode.hpp>
#include <DialogAPI/Main.hpp>
#include "OptionsLayer.hpp"

using namespace geode::prelude;

void MyOptionsLayer::onAccount(CCObject* sender) {
    FLAlertLayer::create("Geometry Dash: Surge", "This feature is currently <cr>unavailable</c> due to the possibility of getting <cy>leaderboard banned</c>. Sorry for the inconvenience.", "OK")->show();
}

void MyOptionsLayer::onSecretVault(CCObject* sender) {
    if (Mod::get()->getSavedValue<bool>("vault-unlocked")) {
        auto scene = CCTransitionFade::create(0.5f, SecretLayer::scene());
        CCDirector::sharedDirector()->pushScene(scene);
    } else {
        auto firstDialog = DialogApi::create("The Guard", "zZzZZZzZzZzZZzZzzzZZzZzZz", 1, 1.0f, false, cocos2d::ccWHITE, [=]() {
            auto secondDialog = DialogApi::create("The Guard", "You need...", 1, 1.0f, false, cocos2d::ccWHITE, [=]() {
                auto thirdDialog = DialogApi::create("The Guard", "ZzZzzzzZZZZZzZZzzZZZZzZ", 1, 1.0f, false, cocos2d::ccWHITE, [=]() {
                    auto fourthDialog = DialogApi::create("The Guard", "I like coins..", 1, 1.0f, false, cocos2d::ccWHITE, [=]() {
                        auto fifthDialog = DialogApi::create("The Guard", "ZzZZZzzzZzZZZzZzZz thank you!", 1, 1.0f, false, cocos2d::ccWHITE, [=]() {
                            auto sixthDialog = DialogApi::create("The Guard", "come in<d025>.<d025>.<d025>.", 1, 1.0f, true, cocos2d::ccWHITE, [=] {
                                Mod::get()->setSavedValue<bool>("vault-unlocked", true);
                                auto scene = CCTransitionFade::create(0.5f, SecretLayer::scene());
                                CCDirector::sharedDirector()->pushScene(scene);
                            });
                            auto sixthLayer = DialogLayer::create(sixthDialog, 1);
                            cocos2d::CCDirector::sharedDirector()->getRunningScene()->addChild(sixthLayer, 999);
                        });
                        auto fifthLayer = DialogLayer::create(fifthDialog, 1);
                        cocos2d::CCDirector::sharedDirector()->getRunningScene()->addChild(fifthLayer, 999);
                    });
                    auto fourthLayer = DialogLayer::create(fourthDialog, 1);
                    cocos2d::CCDirector::sharedDirector()->getRunningScene()->addChild(fourthLayer, 999);
                });
                auto finalLayer = DialogLayer::create(thirdDialog, 1);
                cocos2d::CCDirector::sharedDirector()->getRunningScene()->addChild(finalLayer, 999);
            });
    
            auto secondLayer = DialogLayer::create(secondDialog, 1);
            cocos2d::CCDirector::sharedDirector()->getRunningScene()->addChild(secondLayer, 999);
        });
        
        auto dialog = DialogLayer::create(firstDialog, 1);
        cocos2d::CCDirector::sharedDirector()->getRunningScene()->addChild(dialog, 999);
    }
}