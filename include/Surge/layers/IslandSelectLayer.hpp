#include <Geode/Geode.hpp>
#include <Surge/layers/WorldSelectLayer.h>

using namespace geode::prelude;

class IslandSelectLayer : public ownWorldSelectLayer {
public:
    bool init(int page);
};