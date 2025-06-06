#include <Surge/modify/LevelSelectLayer.hpp>

using namespace geode::prelude;

bool MyLevelSelectLayer::init(int pageID) {
    if(!LevelSelectLayer::init(pageID))
        return false;

    int levelCount = 6;
    
    auto GSM = GameStatsManager::sharedState();
    auto GM = GameManager::sharedState();

    if (!m_scrollLayer) {
        log::error("m_scrollLayer is null");
        return false;
    }

    if (m_scrollLayer->m_dynamicObjects) {
        m_scrollLayer->m_dynamicObjects->removeAllObjects();
    } else {
        log::error("m_scrollLayer->m_dynamicObjects is null");
        return false;
    }

    if (m_scrollLayer->m_dots) {
        auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);
        for(CCSprite* dot : dotsArray) {
            if (dot) dot->removeFromParent();
        }
        m_scrollLayer->m_dots->removeAllObjects();
    } else {
        log::error("m_scrollLayer->m_dots is null");
        return false;
    }

    auto glm = GameLevelManager::get();
    if (!glm) {
        log::error("GameLevelManager::get() returned null");
        return false;
    }

    for(int i = 1; i <= levelCount; i++) {
        auto level = glm->getMainLevel(i, true);
        if (level)
            m_scrollLayer->m_dynamicObjects->addObject(level);
        else
            log::error("getMainLevel({}) returned null", i);
    }

    auto islandsLevel = GJGameLevel::create();
    if (!islandsLevel) {
        log::error("Failed to create islandsLevel");
        return false;
    }
    islandsLevel->m_levelID = -3;
    islandsLevel->m_levelName = "The Islands";

    auto comingSoon = GJGameLevel::create();
    if (!comingSoon) {
        log::error("Failed to create comingSoon");
        return false;
    }
    comingSoon->m_levelID = -1;
    comingSoon->m_levelName = "The Shattering...";

    m_scrollLayer->m_dynamicObjects->addObject(islandsLevel);
    m_scrollLayer->m_dynamicObjects->addObject(comingSoon);

    auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
    if (!batchNode) {
        log::error("Failed to create CCSpriteBatchNode");
        return false;
    }
    m_scrollLayer->addChild(batchNode, 5);

    int dynCount = m_scrollLayer->m_dynamicObjects->count();
    for(int i = 0; i < dynCount; i++) {
        auto sprite = CCSprite::create("smallDot.png");
        if (!sprite) {
            log::error("Failed to create smallDot sprite at index {}", i);
            continue;
        }
        batchNode->addChild(sprite);
        m_scrollLayer->m_dots->addObject(sprite);
    }

    m_scrollLayer->updateDots(0.f);
    m_scrollLayer->updatePages();

    if (dynCount == 0) {
        log::error("No dynamic objects in m_scrollLayer");
        return false;
    }

    if (pageID < 0 || pageID >= dynCount)
        pageID = 0;

    if (!m_scrollLayer->m_pages) {
        log::error("m_scrollLayer->m_pages is null");
        return false;
    }

    int pagesCount = m_scrollLayer->m_pages->count();
    if (pagesCount == 0) {
        log::error("No pages in m_scrollLayer");
        return false;
    }

    if (pageID % 3 >= pagesCount)
        pageID = 0;

    auto pageObj = m_scrollLayer->m_pages->objectAtIndex(pageID % 3);
    auto dynObj = m_scrollLayer->m_dynamicObjects->objectAtIndex(pageID);

    if (!pageObj) {
        log::error("Page object at index {} is null", pageID % 3);
        return false;
    }
    if (!dynObj) {
        log::error("Dynamic object at index {} is null", pageID);
        return false;
    }

    this->updatePageWithObject(pageObj, dynObj);

    if (this->m_scrollLayer)
        this->m_scrollLayer->repositionPagesLooped();
    else
        log::error("this->m_scrollLayer is null");

    return true;
}

ccColor3B MyLevelSelectLayer::colorForPage(int pageID) {
    if (!m_scrollLayer || !m_scrollLayer->m_dynamicObjects) {
        log::error("m_scrollLayer or m_dynamicObjects is null");
        return {255, 255, 255};
    }
    int count = m_scrollLayer->m_dynamicObjects->count();
    if (count == 0) {
        log::error("No dynamic objects for colorForPage");
        return {255, 255, 255};
    }
    int page = (count + (pageID % count)) % count;

    auto GM = GameManager::sharedState();
    if (!GM) {
        log::error("GameManager::sharedState() is null");
        return {255, 255, 255};
    }

    int colIDs[8] = { 
        55,
        7,
        93,
        9,
        5,
        27,
        34,
        10 // 15 = black
    };

    if (colIDs[page % 8] == 94)
        return { 37, 44, 52 };    

    return GM->colorForIdx(colIDs[page % 8]);
}