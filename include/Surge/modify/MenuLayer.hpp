#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init();
	void onCreator(CCObject* sender);

	void onStartupPopup(float dt);

	void onTwitch(CCObject* sender);
	void onYouTube(CCObject* sender);
	void onTwitter(CCObject* sender);
	void onDiscord(CCObject* sender);
	void onFacebook(CCObject* sender);
	void onRobTop(CCObject* sender);

	// void onMoreGames(CCObject* sender);
};