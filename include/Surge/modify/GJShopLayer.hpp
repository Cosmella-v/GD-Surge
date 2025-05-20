#include <Geode/Geode.hpp>
#include <Geode/modify/GJShopLayer.hpp>

class $modify(MyGJShopLayer, GJShopLayer) {
    bool init(ShopType p0);
    void onBack(CCObject* sender);
    void showEntryDialog();
};