#include <DialogCallback.hpp>
#include <Surge/modify/OptionsLayer.hpp>

using namespace geode::prelude;

void MyOptionsLayer::onAccount(CCObject* sender) {
    FLAlertLayer::create("Accounts", "This feature is currently <cr>unavailable</c> due to the possibility of getting <cy>leaderboard banned</c> and to prevent <ca>cheating</c>. Sorry for the inconvenience.", "OK")->show();
}

void MyOptionsLayer::onSecretVault(CCObject* sender) {
    if (Mod::get()->getSavedValue<bool>("vault-unlocked")) {
        auto scene = CCTransitionFade::create(0.5f, SecretLayer::scene());
        CCDirector::sharedDirector()->pushScene(scene);
    } else {
        CCArray* objects = CCArray::create();
        objects->addObject(DialogObject::create("The Guard", "zZzZZZzZzZzZZzZzzzZZzZzZz", 1, 1.0f, false, ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "You need...", 1, 1.0f, false, ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "ZzZzzzzZZZZZzZZzzZZZZzZ", 1, 1.0f, false, ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "I like coins..", 1, 1.0f, false, ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "ZzZZZzzzZzZZZzZzZz thank you!", 1, 1.0f, false, ccWHITE));
        objects->addObject(DialogObject::create("The Guard", "come in<d025>.<d025>.<d025>.", 1, 1.0f, true, ccWHITE));

        auto dialog = DialogLayer::createWithObjects(objects, 1);
        dialog->addToMainScene();
        dialog->animateInRandomSide();

        std::function<void()> secretCallback = [&]() {
            // auto layer = this->getChildByID("main-layer");
            // auto btn = layer->getChildByID("vault-menu")->getChildByID("vault-button");
            // auto lock = btn->getChildByType<CCSprite*>(0);
            // lock->setTexture(CCTextureCache::sharedTextureCache()->addImage("GJ_lock_001.png", true));

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

void MyOptionsLayer::customSetup() {
    OptionsLayer::customSetup();

    auto layer = this->getChildByID("main-layer");
    if (!layer) {
        log::warn("main-layer not found!");
        return;
    }

    auto menu = layer->getChildByID("vault-menu");
    if (!menu) {
        log::warn("vault-menu not found!");
        return;
    }

    CCMenuItemSpriteExtra* oldBtn = typeinfo_cast<CCMenuItemSpriteExtra*>(this->getChildByIDRecursive("vault-button"));
    if (!oldBtn) {
        log::warn("vault-button not found!");
        return;
    }

    auto newBtn = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_lock_open_001.png"),
        this,
        menu_selector(MyOptionsLayer::onSecretVault)
    );
    if (!newBtn) {
        log::warn("Failed to create new vault button!");
        return;
    }

    if (Mod::get()->getSavedValue<bool>("vault-unlocked")) {
        oldBtn->m_pfnSelector = nullptr;

        newBtn->setPosition(oldBtn->getPosition());
        newBtn->setScale(oldBtn->getScale());
        newBtn->setAnchorPoint(oldBtn->getAnchorPoint());

        oldBtn->setVisible(false);
        menu->addChild(newBtn);

        log::warn("Vault button successfully replaced!");
    } else {
        if (auto sprite = oldBtn->getChildByType<CCSprite*>(0)) {
            if (auto coin = sprite->getChildByType<CCSprite*>(0)) coin->setVisible(false);
            if (auto text = sprite->getChildByType<CCLabelBMFont*>(0)) {
                text->setString("??");
                text->setPositionX(11.5f);
            }
        }
    }
}