#include <Surge/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

bool MyGJGarageLayer::init() {
    if (!GJGarageLayer::init())
        return false;
    
    auto menu = this->getChildByID("top-left-menu");
    menu->getChildByID("shop-button")->setVisible(false);

    return true;
}

void MyGJGarageLayer::showUnlockPopup(int p0, UnlockType p1) {
    ItemInfoPopup::create(p0, p1)->show();
}