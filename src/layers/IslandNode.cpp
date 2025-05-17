#include <Surge/layers/IslandNode.h>

using namespace geode::prelude;

namespace more {

IslandNode* IslandNode::create(
    int index,
    IslandSelectLayer* islandSelectLayer
) {
    IslandNode* ret = new IslandNode();

    if (ret && ret->init(index, islandSelectLayer)) {
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }

    return ret;
}

bool IslandNode::init(
    int index,
    IslandSelectLayer* islandSelectLayer
) {
    if (!CCNode::init()) {
        return false;
    }

    m_index = index;

  /*  std::cout << index << std::endl;*/
    m_islandSelectLayer = islandSelectLayer;
   

    return true;
}

CCSprite* IslandNode::createIsland() {
    CCString* path = CCString::createWithFormat(
        "island_%02d.png"_spr,
        m_index
    );

    CCSprite* sprite = CCSprite::createWithSpriteFrameName(
        path->getCString()
    );

    return sprite;
}

} // namespace more