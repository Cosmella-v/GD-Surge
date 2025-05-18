#pragma once
#include <Geode/Bindings.hpp>
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class IslandLevel : public geode::Popup<std::string const&, GJGameLevel*, CCMenuItemSpriteExtra*> {

protected:
    bool init(std::string const& title, GJGameLevel* level, CCMenuItemSpriteExtra* button);

public:
    static IslandLevel* create(std::string const& title, GJGameLevel* level, CCMenuItemSpriteExtra* button);
    static CCScene* scene(std::string const& title, GJGameLevel* level, CCMenuItemSpriteExtra* button);
    bool setup(std::string const& title, GJGameLevel* level, CCMenuItemSpriteExtra* button);

private:
    int m_level;
};

