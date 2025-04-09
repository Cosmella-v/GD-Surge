#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

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
};