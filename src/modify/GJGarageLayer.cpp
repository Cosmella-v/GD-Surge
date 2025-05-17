#include <Surge/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

bool init() {
    auto menu = this->getChildByID("top-left-menu");
    menu->getChildByID("shop-button")->setVisible(false);
}

void MyGJGarageLayer::showUnlockPopup(int p0, UnlockType p1) {
    ItemInfoPopup::create(p0, p1)->show();
}