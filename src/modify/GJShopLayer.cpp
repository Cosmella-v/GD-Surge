#include <Surge/modify/GJShopLayer.hpp>

using namespace geode::prelude;

bool MyGJShopLayer::init(ShopType p0) {
	if (!GJShopLayer::init(ShopType{5}))
		return false;
    auto musicPath = (Mod::get()->getSaveDir() / "songs" / "RandomSong03.mp3").string();
    log::debug("Trying to play: {}", musicPath);
	FMODAudioEngine::sharedEngine()->playMusic(musicPath, true, 0.1f, 0);
	auto extraMenu = CCMenu::create();
	extraMenu->setPosition({0, 0});
	auto infoButton = InfoAlertButton::create("Warning", "Be aware to check your <cy>Icon kit</c>, icons you already unlocked might show here as not bought.", 1);
	infoButton->setPosition({30, 30});
	extraMenu->addChild(infoButton);
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
        auto newShopkeeper = AnimatedShopKeeper::create(ShopType{2});
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

	return true;
}

void MyGJShopLayer::onBack(CCObject* sender) {
    auto scene = GJGarageLayer::scene();
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->replaceScene(transition);
	FMODAudioEngine::sharedEngine()->playMusic("menuLoop.mp3", true, 0.1f, 0);
}