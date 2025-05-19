#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;
class IslandSelectLayer : public CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate {
public:
    GJGroundLayer* m_ground;
    CCSprite* m_background;
    CCArray* m_mainLevels;
    CCArray* m_levelPages;
    BoomScrollLayer* m_scrollLayer;
	float m_fWindowWidth;
    int m_level;
	GJGameLevel* level;
public:
	ccColor3B colorForPage(int);
	ccColor3B getColorValue(int, int, float);
	bool init(int page);
	void onClose(CCObject*);
	void onPrev(CCObject*);
	void onNext(CCObject*);
	void onDownload(CCObject*);
	void onSoundtracks(CCObject*);
	void onBack(CCObject*);
	void keyBackClicked() override;
	void onIslandLevel(CCObject* sender);
	void runParticle();
	void scrollLayerMoved(CCPoint) override;
	CCNode* createSideArt();
	void keyDown(int);
	void updateColors();
	static IslandSelectLayer* create(int page);
	static CCScene* scene(int page);
	void updatePageWithObject(CCObject* page, CCObject* object) override;
	
};