#include <Surge/layers/CreditsLayer.hpp>

void CreditsLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

bool CreditsLayer::init() {
    if (!CCLayer::init()) return false;

    setKeypadEnabled(true);

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto menu = CCMenu::create();
    menu->setPosition({ 0.f, 0.f });
    menu->setAnchorPoint({ 0.f, 0.f });
    this->addChild(menu);

    auto background = CCSprite::create("GJ_gradientBG.png");
    background->setColor(ccc3(0, 102, 255));
    background->setScaleX(winSize.width / background->getContentSize().width);
    background->setScaleY(winSize.height / background->getContentSize().height);
    background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    background->setID("background");
    this->addChild(background, -1);

    auto backButton = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(CreditsLayer::backWrapper)
    );
    backButton->setPosition({ 25, winSize.height - 25 });
    menu->addChild(backButton);

    return true;
}

CreditsLayer* CreditsLayer::create() {
    auto layer = new CreditsLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

CCScene* CreditsLayer::scene() {
    auto scene = CCScene::create();
    auto layer = CreditsLayer::create();
    scene->addChild(layer);
    return scene;
}

void CreditsLayer::backWrapper(CCObject* sender) {
    keyBackClicked();
}