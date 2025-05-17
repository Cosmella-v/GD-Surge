#include <Surge/modify/LevelSelectLayer.hpp>

using namespace geode::prelude;

bool MyLevelSelectLayer::init(int pageID) {
    if (!LevelSelectLayer::init(pageID))
        return false;

    if (!m_scrollLayer || !m_scrollLayer->m_dynamicObjects || !m_scrollLayer->m_dots)
        return false;

    int levelCount = 6;

    auto GSM = GameStatsManager::sharedState();
    auto GM = GameManager::sharedState();

    m_scrollLayer->m_dynamicObjects->removeAllObjects();

    auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);
    for (CCSprite* dot : dotsArray) {
        if (dot) dot->removeFromParent();
    }
    m_scrollLayer->m_dots->removeAllObjects();

    for (int i = 1; i <= levelCount; i++) {
        auto level = GameLevelManager::get()->getMainLevel(i, true);
        if (level) {
            m_scrollLayer->m_dynamicObjects->addObject(level);
        }
    }

    auto islandsLevel = GJGameLevel::create();
    islandsLevel->m_levelID = -3;
    islandsLevel->m_levelName = "The Islands";

    auto comingSoon = GJGameLevel::create();
    comingSoon->m_levelID = -1;
    comingSoon->m_levelName = "The Shattering...";

    m_scrollLayer->m_dynamicObjects->addObject(islandsLevel);
    m_scrollLayer->m_dynamicObjects->addObject(comingSoon);

    auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
    if (batchNode)
        m_scrollLayer->addChild(batchNode, 5);

    int objectCount = m_scrollLayer->m_dynamicObjects->count();
    for (int i = 0; i < objectCount; i++) {
        auto sprite = CCSprite::create("smallDot.png");
        if (sprite && batchNode) {
            batchNode->addChild(sprite);
            m_scrollLayer->m_dots->addObject(sprite);
        }
    }

    m_scrollLayer->updateDots(0.f);
    m_scrollLayer->updatePages();

    if (objectCount == 0 || !m_scrollLayer->m_pages || m_scrollLayer->m_pages->count() == 0)
        return true;

    int safePageID = pageID % objectCount;
    int pageCount = m_scrollLayer->m_pages->count();
    auto pageObject = m_scrollLayer->m_pages->objectAtIndex(safePageID % pageCount);
    auto levelObject = m_scrollLayer->m_dynamicObjects->objectAtIndex(safePageID);

    if (pageObject && levelObject)
        this->updatePageWithObject(pageObject, levelObject);

    m_scrollLayer->repositionPagesLooped();

    return true;
}

ccColor3B MyLevelSelectLayer::colorForPage(int pageID) {
    if (!m_scrollLayer || !m_scrollLayer->m_dynamicObjects)
        return { 255, 255, 255 }; // fallback color

    int count = m_scrollLayer->m_dynamicObjects->count();
    if (count == 0)
        return { 255, 255, 255 }; // fallback

    int page = (count + (pageID % count)) % count;

    auto GM = GameManager::sharedState();

    int colIDs[8] = {
        55,
        7,
        93,
        9,
        5,
        27,
        34,
        (AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04") &&
         Mod::get()->getSettingValue<bool>("shattered-code")) ? 15 : 10
    };

    if (colIDs[page % 8] == 94)
        return { 37, 44, 52 };

    return GM->colorForIdx(colIDs[page % 8]);
}
