#include <Surge/modify/LoadingLayer.hpp>

using namespace geode::prelude;

bool MyLoadingLayer::init(bool fromReload) {
    if (!LoadingLayer::init(fromReload))
        return false;

    // auto director = CCDirector::get();
    // auto winSize = director->getWinSize();
    // auto GM = GameManager::sharedState();

    // auto mainTitle = getChildByType<CCSprite>(1);
    // if (!mainTitle)
    //     return true;

    // CCSprite* surgeLogo = CCSprite::createWithSpriteFrameName("surgeLogo_001.png"_spr);
    // if (!surgeLogo) {
    //     log::warn("Sprite frame 'surgeLogo_001.png' not found in cache.");
    //     return true;
    // }

    // CCRect logoBounds = mainTitle->boundingBox();
    // surgeLogo->setAnchorPoint({1.0f, 1.0f});
    // surgeLogo->setPosition(ccp(logoBounds.getMaxX() - 2.f, logoBounds.getMinY() - 1.5f));

    // this->addChild(surgeLogo);

    return true;
}
