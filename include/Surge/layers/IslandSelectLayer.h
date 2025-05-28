#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;
class IslandSelectLayer : public CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate {
private:
	float minDuration = 0.05f;
    float speedupFactor = 1.1f;
    std::shared_ptr<float> duration;
    cocos2d::CCNode* m_spinNode;
public:
    GJGroundLayer* m_ground;
    CCSprite* m_background;
    CCArray* m_mainLevels;
    CCArray* m_levelPages;
    BoomScrollLayer* m_scrollLayer;
	float m_fWindowWidth;
    int m_level;
	GJGameLevel* level;
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
	void spinCycle() {
        if (*duration < minDuration) return;

        auto rotate = cocos2d::CCRotateBy::create(*duration, 360.0f);
        auto callback = cocos2d::CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::spinCycleCallback));

        m_spinNode->runAction(cocos2d::CCSequence::create(rotate, callback, nullptr));
    }

    void spinCycleCallback() {
        *duration /= speedupFactor;

        if (*duration >= minDuration) {
            spinCycle();
        }
    }
};