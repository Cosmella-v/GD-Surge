#include <Surge/modify/GJShopLayer.hpp>
#include <DialogCallback.hpp>

using namespace geode::prelude;

bool MyGJShopLayer::init(ShopType p0) {
	if (!GJShopLayer::init(ShopType{5}))
		return false;
    auto musicPath = (Mod::get()->getSaveDir() / "songs" / "RandomSong03.mp3").string();
    log::debug("Trying to play: {}", musicPath);
	FMODAudioEngine::sharedEngine()->playMusic(musicPath, true, 0.1f, 0);
	auto extraMenu = CCMenu::create();
	extraMenu->setPosition({0, 0});
	this->addChild(extraMenu);
	auto particle = static_cast<CCParticleSystemQuad *>(getChildren()->objectAtIndex(7));
	particle->setStartColor({193, 122, 5, 255});
	particle->setEndColor({255, 122, 0, 0});

	auto bg = this->getChildByType<CCSprite*>(0);
	if (bg) {
		auto bgFrame = CCSpriteFrameCache::get()->spriteFrameByName("GDS_shopBG.png"_spr);
		if (bgFrame) {
			bg->setDisplayFrame(bgFrame);
		} else {
			log::debug("Sprite frame 'GDS_shopBG.png' not found.");
		}
	}

	auto desk = this->getChildByType<CCSprite*>(3);
	if (desk) {
		auto deskFrame = CCSpriteFrameCache::get()->spriteFrameByName("GDS_shopDesk.png"_spr);
		if (deskFrame) {
			desk->setDisplayFrame(deskFrame);
		} else {
			log::debug("Sprite frame 'GDS_shopDesk.png' not found.");
		}
	}

    auto oldShopkeeper = this->getChildByType<AnimatedShopKeeper*>(0);
    if (oldShopkeeper) {
        auto newShopkeeper = AnimatedShopKeeper::create(ShopType{1});
        newShopkeeper->setPosition(oldShopkeeper->getPosition());
        newShopkeeper->setScale(oldShopkeeper->getScale());
        newShopkeeper->setRotation(oldShopkeeper->getRotation());
        newShopkeeper->setAnchorPoint(oldShopkeeper->getAnchorPoint());
        this->addChild(newShopkeeper);
        oldShopkeeper->removeFromParent();
    }

    auto shopSign = this->getChildByType<CCSprite*>(1);
    if (shopSign) {
        auto shopSignFrame = CCSpriteFrameCache::get()->spriteFrameByName("GDS_shopSign.png"_spr);
        if (shopSignFrame) {
            shopSign->setDisplayFrame(shopSignFrame);
        } else {
            log::debug("Sprite frame 'GDS_shopSign.png' not found.");
        }
    }

	this->runAction(
        cocos2d::CCSequence::create(
            cocos2d::CCDelayTime::create(1.5f),
            cocos2d::CCCallFunc::create(this, callfunc_selector(MyGJShopLayer::showEntryDialog)),
            nullptr
        )
    ); 

	return true;
}

void MyGJShopLayer::onBack(CCObject* sender) {
    auto scene = GJGarageLayer::scene();
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->replaceScene(transition);
	FMODAudioEngine::sharedEngine()->playMusic("menuLoop.mp3", true, 0.1f, 0);
}

void MyGJShopLayer::showEntryDialog() {
    CCArray* objects = CCArray::create();
	objects->addObject(DialogObject::create("Scratch", 
		fmt::format("Oh... uh... <d030>Hello <co>{}</c>!", GameManager::sharedState()->m_playerName), 
		8, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("Scratch", 
		"I'm here because <co>The Shopkeeper</c> asked me to take care of his shop for a while.", 
		9, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("The Shopkeeper", 
		"<s100>HEY!</s> What are <cr>you</c> doing here?!", 
		30, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("Scratch", 
		"Uhm... I'm just here to <cg>buy</c> something.", 
		26, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("The Shopkeeper", 
		"Oh, okay. I've got something to deal with.<d030> You lot better not <cr>mess around</c>!", 
		5, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("Scratch", 
		"Don't worry! We won't do anything <cg>bad</c>!", 
		10, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("Scratch", 
		fmt::format("Alright, so, <co>{}</c>... <d030>don't tell anyone, but I'm actually here to <cr>steal</c> some stuff from <co>The Shopkeeper</c>.", GameManager::sharedState()->m_playerName), 
		13, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("Scratch",
		"Wanna join me?", 
		13, 1.0f, false, cocos2d::ccWHITE));

	objects->addObject(DialogObject::create("Scratch", 
		"No? <d040>You scared or something?<d030> Nevermind... I'll just <co>do it myself</c>.", 
		13, 1.0f, false, cocos2d::ccWHITE));

    auto dialog = DialogLayer::createWithObjects(objects, 2);
    dialog->addToMainScene();
    dialog->animateInRandomSide();

    std::function<void()> secretCallback = [&]() {
        Mod::get()->setSavedValue<bool>("shop-yap", true);
    };

    auto* del = new DialogCallback();
    dialog->addChild(del);
    del->autorelease();
    del->m_callback = secretCallback;
    dialog->m_delegate = del;
}