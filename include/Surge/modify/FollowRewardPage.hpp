#include <Geode/Geode.hpp>
#include <Geode/modify/FollowRewardPage.hpp>

using namespace geode::prelude;

class $modify(MyFollowRewardPage, FollowRewardPage) {
public:
    bool init();
    void FLAlert_Clicked(FLAlertLayer* alert, bool confirmed);
    void onSpecialItem(CCObject* sender);
};