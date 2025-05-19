#include <Geode/Geode.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    GameStatsManager::sharedState()->m_accountIDForIcon.insert(std::make_pair({485, UnlockType::Cube}, 16));
}