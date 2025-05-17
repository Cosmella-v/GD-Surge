#pragma once

#include <Geode/Bindings.hpp>
#include "IslandSelectLayer.h"

namespace more {

class IslandNode : public cocos2d::CCNode {
public:
    static IslandNode* create(
        int index,
        IslandSelectLayer* islandSelectLayer
    );
    
    bool init(
        int index,
        IslandSelectLayer* islandSelectlayer
    );

    cocos2d::CCSprite* createIsland();

    int m_index;
    IslandSelectLayer* m_islandSelectLayer;
};

} // namespace more