#include <Surge/layers/BasementLayer.hpp>

void BasementLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

bool BasementLayer::init() {
    if (!CCLayer::init()) return false;

    setKeypadEnabled(true);

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto menu = CCMenu::create();
    menu->setPosition({ 0.f, 0.f });
    menu->setAnchorPoint({ 0.f, 0.f });
    this->addChild(menu);

    auto background = CCSprite::create("GJ_gradientBG.png");
    background->setColor(ccc3(50, 0, 75));
    background->setScaleX(winSize.width / background->getContentSize().width);
    background->setScaleY(winSize.height / background->getContentSize().height);
    background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    background->setID("background");
    this->addChild(background, -1);

    auto backButton = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(BasementLayer::backWrapper)
    );
    backButton->setPosition({ 25, winSize.height - 25 });
    menu->addChild(backButton);

    

    return true;
}

BasementLayer* BasementLayer::create() {
    auto layer = new BasementLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

CCScene* BasementLayer::scene() {
    auto scene = CCScene::create();
    auto layer = BasementLayer::create();
    scene->addChild(layer);
    return scene;
}

void BasementLayer::backWrapper(CCObject* sender) {
    keyBackClicked();
}