#include <Surge/modify/GameStatsManager.hpp>

using namespace geode::prelude;

bool MyGameStatsManager::isItemUnlocked(UnlockType p0, int p1) {
    if (GameStatsManager::isItemUnlocked(p0, p1))
            return true;

    // if (p0 == UnlockType::GJItem && p1 >= 1 && p1 <= 4) {
    //     return true;
    // }

    return false;
}

void MyGameStatsManager::checkCoinAchievement(GJGameLevel* level) {
    auto GM = GameManager::sharedState();

    int coinPercent = (getCollectedCoinsForLevel(level) / 3.f) * 100.f;
    auto achievementID = fmt::format("geometry.ach.surge.levelcoin{:02}", level->m_levelID.value());

    if(level->m_levelType == GJLevelType::Local) {
        GM->reportAchievementWithID(achievementID.c_str(), coinPercent, false);
    }
}

void MyGameStatsManager::createStoreItems() {
    auto newShop = static_cast<ShopType>(5);
    if (!m_allStoreItems)
    {
        m_allStoreItems = CCDictionary::create();
        m_allStoreItems->retain();

        m_storeItems = CCDictionary::create();
        m_storeItems->retain();

        m_storeItemArray = CCArray::create();
        m_storeItemArray->retain();

        //  REFERENCE / REFERENCIA
        //  - Place in shop
        //  - ID
        //  - UnlockType
        //  - Price
        //  - Shop

        // total orbs (main lvls + secret lvl) = 1325

        addStoreItem(1, 496, 1, 50, newShop); // 50
        addStoreItem(2, 497, 1, 75, newShop); // 125
        addStoreItem(3, 498, 1, 100, newShop); // 225
        addStoreItem(4, 499, 1, 100, newShop); // 325

        addStoreItem(5, 500, 1, 100, newShop); // 425
        addStoreItem(6, 178, 4, 50, newShop); // 475
        addStoreItem(7, 179, 4, 75, newShop); // 550
        addStoreItem(8, 180, 4, 100, newShop); // 650
        addStoreItem(9, 127, 5, 50, newShop); // 700
        addStoreItem(10, 128, 5, 75, newShop); // 775
        addStoreItem(11, 129, 5, 100, newShop); // 875
        addStoreItem(12, 130, 5, 100, newShop); // 975
        addStoreItem(13, 152, 6, 50, newShop); // 1025
        addStoreItem(14, 153, 6, 75, newShop); // 1100
        addStoreItem(15, 154,6, 100, newShop); // 1200
        addStoreItem(16, 155, 6, 100, newShop); // 1300

        addStoreItem(17, 18, 12, 50, newShop); // ANIMACION
        addStoreItem(18, 19, 12, 50, newShop); // ANIMACION
        addStoreItem(19, 20, 12, 50, newShop); // ANIMACION
    }
}