#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		// auto menu = this->getChildByID("bottom-menu");

		// auto cameraBtn = CircleButtonSprite::create(
		// 	CCNode::create(),
		// 	CircleBaseColor::Green,
		// 	CircleBaseSize::MediumAlt
		// );

		// auto chatButton = CCMenuItemSpriteExtra::create(
		// 	cameraBtn,
		// 	this,
		// 	menu_selector(MyMenuLayer::onButtonClick)
		// );

		// chatButton->setID("stream-button");

		// menu->addChild(chatButton);
		// menu->updateLayout();

		auto logo = this->getChildByID("main-title");

		auto spriteLogo = typeinfo_cast<CCSprite*>(logo);
		if (spriteLogo) {
			CCSprite* surgeLogo = CCSprite::createWithSpriteFrameName("surgeLogo_001.png"_spr);
			surgeLogo->setID("surge-logo");

			CCRect logoBounds = spriteLogo->boundingBox();
			surgeLogo->setAnchorPoint({1.0f, 1.0f});
			surgeLogo->setPosition(ccp(logoBounds.getMaxX() - 2.f, logoBounds.getMinY() - 1.5f));

			this->addChild(surgeLogo);
		}

		return true;
	}

	// void onButtonClick(CCObject* sender) {
	// 	auto gm = GameManager::sharedState();

	// 	gm->reportAchievementWithID("geometry.testach", 100, false);
	// 	log::debug("did smth..?");
	// }
};