#include <Geode/Geode.hpp>

using namespace geode::prelude;

class BasementLayer : public CCLayer {
public:
    bool init();
    static CCScene* scene();
    static BasementLayer* create();
    void keyBackClicked();
    void backWrapper(CCObject* sender);
};