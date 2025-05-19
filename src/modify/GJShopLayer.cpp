#include <Surge/modify/GJShopLayer.hpp>

using namespace geode::prelude;

bool MyGJShopLayer::init(ShopType p0) {
	if (!GJShopLayer::init(ShopType{6}))
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
        bg->setDisplayFrame(CCSpriteFrameCache::get()->spriteFrameByName("GDS_shopBG.png"_spr));
    }

    auto desk = this->getChildByType<CCSprite*>(2);
    if (desk) {
        desk->setDisplayFrame(CCSpriteFrameCache::get()->spriteFrameByName("GDS_shopDesk.png"_spr));
    }
	return true;
}

void MyGJShopLayer::onBack(CCObject* sender) {
    auto scene = GJGarageLayer::scene();
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->replaceScene(transition);
	FMODAudioEngine::sharedEngine()->playMusic("menuLoop.mp3", true, 0.1f, 0);
}