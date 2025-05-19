#include <Geode/Geode.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    auto GSM = GameStatsManager::sharedState();
    GSM->m_usernameForAccountID.insert(
        std::make_pair(19081577, "MobMasterMind")
    );
    GSM->m_accountIDForIcon.insert(
        std::make_pair(std::make_pair(485, UnlockType::Cube), 19081577)
    );
}
