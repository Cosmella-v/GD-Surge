#pragma once

#include "Geode/binding/WorldSelectLayer.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#if !defined(GEODE_IS_ANDROID) && !defined(GEODE_IS_IOS)

class WorldSelectLayerR : public CCLayer {
public:
    // Creation
    static WorldSelectLayerR* create(int page);
    static CCScene* scene(int page);

    // Lifecycle
    virtual void onExit() override;
    virtual void keyBackClicked() override;
    virtual ~WorldSelectLayerR();

    // Initialization
    bool init(int page);
    void setupWorlds();

    // Navigation
    void goToPage(int page, bool animated);
    void updateArrows();
    void unblockButtons();
    void animateInActiveIsland();
    void showCompleteDialog();

    // Scroll callbacks
    void scrollLayerMoved();
    void scrollLayerMoved(float* offset);
    void scrollLayerScrolledToPage(BoomScrollLayer* layer, int page);
    void scrollLayerWillScrollToPage(BoomScrollLayer* layer, int page);

    // Button callbacks
    void onBack(CCObject* sender);
    void onNext(CCObject* sender);
    void onPrev(CCObject* sender);
    void onGarage(CCObject* sender);
    void onFreeLevels(CCObject* sender);

    // Colors
    ccColor3B colorForPage(int page);
    ccColor3B getColorValue(int fromPage, int toPage, float percent);

    // Ads
    void tryShowAd();
};

#endif
