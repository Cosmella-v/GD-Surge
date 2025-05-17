#include <Surge/layers/IslandLevel.hpp>

using namespace geode::prelude;

bool IslandLevel::setup(std::string const& value) {
    this->setID("IslandLevel"_spr);
    this->setTitle(value);

    // auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
    // m_mainLayer->addChildAtPosition(label, Anchor::Top, ccp(0, -15.f));

    return true;
}

IslandLevel* IslandLevel::create(std::string const& text) {
    auto ret = new IslandLevel();
    if (ret && ret->initAnchored(300.f, 260.f, text)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

cocos2d::CCScene* IslandLevel::scene(std::string const& text) {
    auto scene = cocos2d::CCScene::create();
    auto popup = IslandLevel::create(text);
    if (popup)
        scene->addChild(popup);
    return scene;
}
