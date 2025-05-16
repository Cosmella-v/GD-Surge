#include <Surge/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

void MyGJGarageLayer::showUnlockPopup(int p0, UnlockType p1) {
    ItemInfoPopup::create(p0, p1)->show();
}