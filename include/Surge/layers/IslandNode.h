#pragma once

#include <Geode/Geode.hpp>
#include "GDSIslandSelectLayer.h"

using namespace geode::prelude;

class IslandNode : public CCNode {
public:
    static IslandNode* create(
        int index,
        GDSIslandSelectLayer* islandSelectLayer
    );
    
    bool init(
        int index,
        GDSIslandSelectLayer* islandSelectlayer
    );

    CCSprite* createIsland();

    int m_index;
    GDSIslandSelectLayer* m_islandSelectLayer;
};