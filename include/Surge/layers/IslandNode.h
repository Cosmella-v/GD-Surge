#pragma once

#include <Geode/Geode.hpp>
#include "IslandSelectLayer.h"

using namespace geode::prelude;

class IslandNode : public CCNode {
public:
    static IslandNode* create(
        int index,
        IslandSelectLayer* islandSelectLayer
    );
    
    bool init(
        int index,
        IslandSelectLayer* islandSelectlayer
    );

    CCSprite* createIsland();

    int m_index;
    IslandSelectLayer* m_islandSelectLayer;
};