#include <Geode/Geode.hpp>
#include <Geode/modify/LevelAreaLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelAreaLayer, LevelAreaLayer) {
public:
    bool init();
    void onIslands(CCObject* selector);
};