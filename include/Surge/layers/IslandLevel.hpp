#pragma once
#include <Geode/Bindings.hpp>
#include <Geode/Geode.hpp>
class IslandLevel : public geode::Popup<std::string const&> {

protected:
    bool init(std::string const& value);

public:
    static IslandLevel* create(std::string const& text);
    static cocos2d::CCScene* scene(std::string const& text);
    bool setup(std::string const& value);

private:
    int m_level;
};

