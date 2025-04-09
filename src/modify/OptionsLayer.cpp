#include <Geode/Geode.hpp>
#include <DialogCallback.hpp>
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
        CCArray* objects = CCArray::create();
        objects->addObject(DialogObject::create("The Guard", "zZzZZZzZzZzZZzZzzzZZzZzZz", 1, 1.0f, false, cocos2d::ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "You need...", 1, 1.0f, false, cocos2d::ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "ZzZzzzzZZZZZzZZzzZZZZzZ", 1, 1.0f, false, cocos2d::ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "I like coins..", 1, 1.0f, false, cocos2d::ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "ZzZZZzzzZzZZZzZzZz thank you!", 1, 1.0f, false, cocos2d::ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "come in<d025>.<d025>.<d025>.", 1, 1.0f, true, cocos2d::ccWHITE));

        auto dialog = DialogLayer::createWithObjects(objects, 1);
        dialog->addToMainScene();
        dialog->animateInRandomSide();

        std::function<void()> secretCallback = [=]() {
            Mod::get()->setSavedValue<bool>("vault-unlocked", true);
			auto scene = CCTransitionFade::create(0.5f, SecretLayer::scene());
            CCDirector::sharedDirector()->pushScene(scene);
		};

		auto* del = new DialogCallback();
		dialog->addChild(del);
		del->autorelease();
		del->m_callback = secretCallback;
		dialog->m_delegate = del;
    }
}