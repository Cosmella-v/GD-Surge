#include <Surge/modify/LevelSelectLayer.hpp>

using namespace geode::prelude;

bool MyLevelSelectLayer::init(int pageID) {
    if(!LevelSelectLayer::init(pageID))
        return false;

    int levelCount = 6;
    
    auto GSM = GameStatsManager::sharedState();
    auto GM = GameManager::sharedState();

    m_scrollLayer->m_dynamicObjects->removeAllObjects();

    auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);

    for(CCSprite* dot : dotsArray) {
        dot->removeFromParent();
    }

    m_scrollLayer->m_dots->removeAllObjects();

    for(int i = 1; i <= levelCount; i++) {
        m_scrollLayer->m_dynamicObjects->addObject(GameLevelManager::get()->getMainLevel(i, true));
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
    m_scrollLayer->addChild(batchNode, 5);

    for(int i = 0; i < m_scrollLayer->m_dynamicObjects->count(); i++) {
        auto sprite = CCSprite::create("smallDot.png");
        batchNode->addChild(sprite);
        m_scrollLayer->m_dots->addObject(sprite);
    }

    m_scrollLayer->updateDots(0.f);
    m_scrollLayer->updatePages();
    if (pageID < 0 || pageID >= m_scrollLayer->m_dynamicObjects->count())
        pageID = 0;

    if (pageID % 3 >= m_scrollLayer->m_pages->count())
        pageID = 0;

    this->updatePageWithObject(
        m_scrollLayer->m_pages->objectAtIndex(pageID % 3),
        m_scrollLayer->m_dynamicObjects->objectAtIndex(pageID)
    );
    this->m_scrollLayer->repositionPagesLooped();

    return true;
}

ccColor3B MyLevelSelectLayer::colorForPage(int pageID) {
    int count = m_scrollLayer->m_dynamicObjects->count();
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
        (AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04") && Mod::get()->getSettingValue<bool>("shattered-code")) ? 15 : 10
    };
    
    if (colIDs[page % 8] == 94)
        return { 37, 44, 52 };    

    return GM->colorForIdx(colIDs[page % 8]);
}