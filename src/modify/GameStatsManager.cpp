#include <Surge/modify/GameStatsManager.hpp>

using namespace geode::prelude;

bool MyGameStatsManager::isItemUnlocked(UnlockType p0, int p1) {
    if (GameStatsManager::isItemUnlocked(p0, p1))
            return true;

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
    if (!m_allStoreItems) {
        m_allStoreItems = CCDictionary::create();
        m_allStoreItems->retain();

        m_storeItems = CCDictionary::create();
        m_storeItems->retain();

        m_storeItemArray = CCArray::create();
        m_storeItemArray->retain();

        //  REFERENCE
        //  - Place in shop
        //  - ID
        //  - UnlockType
        //  - Price
        //  - Shop

        //  - 1 = Cube
        //  - 2 = Col1
        //  - 3 = Col2
        //  - 4 = Ship
        //  - 5 = Ball
        //  - 6 = UFO
        //  - 7 = Wave
        //  - 8 = Robot
        //  - 9 = Spider
        //  - 10 = Streak
        //  - 11 = Death effect
        //  - 12 = Item
        //  - 13 = Swing
        //  - 14 = Jetpack
        //  - 15 = Ship fire

        // total orbs (main lvls + secret lvl) = 1325

        addStoreItem(1, 152, 6, 100, newShop);
        addStoreItem(2, 177, 4, 100, newShop);
        addStoreItem(3, 105, 7, 100, newShop);
        addStoreItem(4, 124, 5, 100, newShop);
        addStoreItem(5, 179, 4, 100, newShop);
        addStoreItem(6, 73, 8, 100, newShop);
        addStoreItem(7, 72, 9, 100, newShop);
        addStoreItem(8, 46, 13, 100, newShop);
        addStoreItem(9, 18, 12, 250, newShop);
        addStoreItem(10, 102, 7, 100, newShop);
        addStoreItem(11, 487, 1, 100, newShop);
        addStoreItem(12, 176, 4, 100, newShop);
        addStoreItem(13, 125, 5, 100, newShop);
        addStoreItem(14, 154, 6, 100, newShop);
        addStoreItem(15, 103, 7, 100, newShop);
        addStoreItem(16, 178, 4, 100, newShop);
        addStoreItem(17, 489, 1, 100, newShop);
        addStoreItem(18, 47, 13, 100, newShop);
        addStoreItem(19, 49, 13, 100, newShop);
        addStoreItem(20, 19, 12, 250, newShop);
        addStoreItem(21, 75, 8, 100, newShop);
        addStoreItem(22, 74, 9, 100, newShop);
        addStoreItem(23, 155, 6, 100, newShop);
        addStoreItem(24, 74, 8, 100, newShop);
        addStoreItem(25, 153, 6, 100, newShop);
        addStoreItem(26, 75, 9, 100, newShop);
        addStoreItem(27, 48, 13, 100, newShop);
        addStoreItem(28, 20, 12, 250, newShop);
        addStoreItem(29, 488, 1, 100, newShop);
        addStoreItem(30, 122, 5, 100, newShop);
        addStoreItem(31, 151, 6, 100, newShop);
        addStoreItem(32, 123, 5, 100, newShop);
        addStoreItem(33, 180, 4, 100, newShop);
        addStoreItem(34, 490, 1, 100, newShop);
        addStoreItem(35, 104, 7, 100, newShop);
        addStoreItem(36, 72, 8, 100, newShop);
        addStoreItem(37, 73, 9, 100, newShop);
        addStoreItem(38, 71, 9, 100, newShop);
        addStoreItem(39, 50, 13, 100, newShop);
    }
}