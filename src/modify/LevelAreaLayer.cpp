#include <Surge/modify/LevelAreaLayer.hpp>
#include <Surge/layers/IslandSelectLayer.hpp>

bool MyLevelAreaLayer::init() {
    if (!LevelAreaLayer::init()) return false;

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto menu = CCMenu::create();
    menu->setPosition({ winSize.width / 4 * 3, 0.f });
    menu->setContentSize({ winSize.width / 4, winSize.height });

    auto button = CCMenuItemSpriteExtra::create(
        CircleButtonSprite::create(CCSprite::createWithSpriteFrameName("worldIsland_01.png"_spr), CircleBaseColor::Green, CircleBaseSize::Medium),
        this,
        menu_selector(MyLevelAreaLayer::onIslands)
    );

    menu->addChild(button);
    this->addChild(menu);

    return true;
}

void MyLevelAreaLayer::onIslands(CCObject* sender) {
    auto scene = CCTransitionFade::create(0.5f, IslandSelectLayer::scene(0));
    CCDirector::sharedDirector()->pushScene(scene);
}