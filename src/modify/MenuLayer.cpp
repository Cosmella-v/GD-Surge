#include <Surge/modify/MenuLayer.hpp>

float speed = 1.0f;
float delaySetting = 0.0f;
float addtlDuration = 0.0f;

bool stopLooping = false;
bool jumpedAlready = false;

bool MyMenuLayer::init() {
	if (!MenuLayer::init()) {
		return false;
	}
	auto logo = this->getChildByID("main-title");
	auto spriteLogo = typeinfo_cast<CCSprite*>(logo);
	if (spriteLogo && !(Loader::get()->getLoadedMod("ninxout.redash"))) {
		CCSprite* surgeLogo = CCSprite::createWithSpriteFrameName("surgeLogo_001.png"_spr);
		surgeLogo->setID("surge-logo");
		CCRect logoBounds = spriteLogo->boundingBox();
		surgeLogo->setAnchorPoint({1.0f, 1.0f});
		surgeLogo->setPosition(ccp(logoBounds.getMaxX() - 2.f, logoBounds.getMinY() - 1.5f));
		this->addChild(surgeLogo);

		std::string nodeChosenByYAMM = "this-mod-doesnt-assign-node-ids-to-anything-lmfao"_spr;

		auto fodsAnimMod = Loader::get()->getLoadedMod("raydeeux_hjfod.fodsmenuanimations");

		if (fodsAnimMod && fodsAnimMod->getSettingValue<bool>("enabled") && 
			(!(!surgeLogo->getID().empty() && surgeLogo->getID() == nodeChosenByYAMM))) {
			
			float animSpeed = std::clamp(speed, 0.01f, 16.0f);
			float animDelay = std::clamp(delaySetting, 0.0f, 10.0f);
			float animDuration = std::clamp(addtlDuration, 0.0f, 2.0f);

			CCDelayTime* delay = CCDelayTime::create((0.25f / animSpeed) + animDelay);
			CCEaseBackOut* eboScale = CCEaseBackOut::create(CCScaleTo::create((2.0f / animSpeed) + animDuration, 1.f));
			CCSequence* titleSequence = CCSequence::create(delay, eboScale, nullptr);

			surgeLogo->setScale(0.f);
			surgeLogo->runAction(titleSequence);
		}
	}
	return true;
}
