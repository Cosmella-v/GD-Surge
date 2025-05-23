#include <Geode/Geode.hpp>

using namespace geode::prelude;

std::vector<std::pair<int, std::string>> creditsTable = {
    {19081577, "MobMasterMind"}
};

void insertIcons(GameStatsManager* GSM, UnlockType type, int start, int end, int accountID) {
    for (int i = start; i <= end; ++i) {
        GSM->m_accountIDForIcon.insert({{i, type}, accountID});
    }
}

$on_mod(Loaded) {
    auto GSM = GameStatsManager::sharedState();
    for (const auto& [accountID, username] : creditsTable) {
        GSM->m_usernameForAccountID.insert({accountID, username});
    }

    insertIcons(GSM, UnlockType::Cube, 485, 500, 19081577);
    insertIcons(GSM, UnlockType::Ship, 170, 180, 19081577);
    insertIcons(GSM, UnlockType::Ball, 119, 130, 19081577);
    insertIcons(GSM, UnlockType::Bird, 150, 151, 19081577);
    insertIcons(GSM, UnlockType::Dart, 97, 104, 19081577);
    insertIcons(GSM, UnlockType::Robot, 69, 71, 19081577);
    insertIcons(GSM, UnlockType::Spider, 70, 70, 19081577);
    insertIcons(GSM, UnlockType::Swing, 44, 47, 19081577);
}