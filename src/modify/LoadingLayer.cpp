#include <Surge/modify/LoadingLayer.hpp>

using namespace geode::prelude;

bool MyLoadingLayer::init(bool fromReload) {
    if (!LoadingLayer::init(fromReload))
        return false;

    auto GM = GameManager::sharedState();
    auto SFC = CCSpriteFrameCache::get();
    auto searchPathRoot = dirs::getModRuntimeDir() / Mod::get()->getID() / "resources";

    CCFileUtils::sharedFileUtils()->addSearchPath(searchPathRoot.string().c_str());
    SFC->addSpriteFramesWithFile("TitleSheet.plist"_spr);

    auto version = CCLabelBMFont::create(fmt::format("{}", Mod::get()->getVersion().toVString(true)).c_str(), "goldFont.fnt");
    version->setPosition({5, 5});
    version->setAnchorPoint({0, 0});
    version->setScale(0.5f);
    this->addChild(version);

    auto director = CCDirector::get();
    auto winSize = director->getWinSize();

    auto mainTitle = getChildByType<CCSprite>(1);
    mainTitle->setPositionY(mainTitle->getPositionY() + 5.f);
    if (!mainTitle)
        return true;

    CCSprite* surgeLogo = CCSprite::createWithSpriteFrameName("surgeLogo_001.png"_spr);
    if (!surgeLogo) {
        log::warn("Sprite frame 'surgeLogo_001.png' not found in cache.");
        return true;
    }

    CCRect logoBounds = mainTitle->boundingBox();
    surgeLogo->setAnchorPoint({1.0f, 1.0f});
    surgeLogo->setPosition(ccp(logoBounds.getMaxX() - 2.f, logoBounds.getMinY() - 1.5f));

    this->addChild(surgeLogo);

    auto robtopLogo = static_cast<CCSprite *>(this->getChildByID("robtop-logo"));
    if (robtopLogo)
    {
        auto teamLogo = CCSprite::createWithSpriteFrameName("omgrodLogo_01.png"_spr);
        robtopLogo->setDisplayFrame(teamLogo->displayFrame());
    };

    return true;
}
