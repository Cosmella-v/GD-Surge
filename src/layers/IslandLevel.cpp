#include <Surge/layers/IslandLevel.hpp>
#include <Surge/layers/IslandSelectLayer.h>

using namespace geode::prelude;

bool IslandLevel::setup(std::string const& title, GJGameLevel* level, CCMenuItemSpriteExtra* button) {
    this->setID("IslandLevel"_spr);
    this->setTitle(title);

    auto GLM = GameLevelManager::sharedState();

    auto BG = (CCScale9Sprite*)m_mainLayer->getChildren()->objectAtIndex(0);
    auto m_buttonMenu = CCMenu::create();
    auto corner1 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();
    corner1->setPosition(BG->getPosition());
    corner1->setRotation(180);
    m_mainLayer->addChild(corner1);

    auto corner2 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner2->setPosition(BG->getPosition());
    corner2->setRotation(90);
    m_mainLayer->addChild(corner2);

    auto corner3 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner3->setPosition(BG->getPosition());
    corner3->setRotation(270);
    m_mainLayer->addChild(corner3);

    auto corner4 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner4->setPosition(BG->getPosition());
    
    corner1->setPositionX(corner1->getPositionX() + 125.45);
    corner1->setPositionY(corner1->getPositionY() + 105.1);
    
    corner2->setPositionX(corner2->getPositionX() - 125.45);
    corner2->setPositionY(corner2->getPositionY() + 105.1);
    
    corner3->setPositionX(corner3->getPositionX() + 125.45);
    corner3->setPositionY(corner3->getPositionY() - 105.1);
    
    corner4->setPositionX(corner4->getPositionX() - 125.45);
    corner4->setPositionY(corner4->getPositionY() - 105.1);

    cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
    cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
    CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(IslandSelectLayer::onInfo));

    infoBtn->setTag(button->getTag());
    infoMenu->addChild(infoBtn);
    infoMenu->setPosition(BG->getPosition());
    infoMenu->setPositionX(infoMenu->getPositionX() + 146.5);
    infoMenu->setPositionY(infoMenu->getPositionY() + 126.1);
    info->setTag(button->getTag());
    infoMenu->setTag(button->getTag());
    m_mainLayer->addChild(infoMenu, 2);
    m_mainLayer->addChild(corner4);

    m_mainLayer->addChild(m_buttonMenu);

    if (button->getTag() == 30) {
        level = GLM->getMainLevel(2001, true);
		level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2001);
    }
    if (button->getTag() == 31) {
        level = GLM->getMainLevel(2002, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2002);
    }
    if (button->getTag() == 32) {
        level = GLM->getMainLevel(2003, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2003);
    }
    if (button->getTag() == 33) {
        level = GLM->getMainLevel(2004, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2004);
      
    }
    if (button->getTag() == 34) {
        level = GLM->getMainLevel(2005, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2005);
      
    }
    if (button->getTag() == 35) {
        level = GLM->getMainLevel(2006, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2006);
       
    }
    if (button->getTag() == 36) {
        level = GLM->getMainLevel(2007, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2007);
       
    }
    if (button->getTag() == 37) {
        level = GLM->getMainLevel(2008, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2008);
    }
    if (button->getTag() == 38) {
        level = GLM->getMainLevel(2009, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2009);
    }
    if (button->getTag() == 39) {
        level = GLM->getMainLevel(2010, true);
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2010);
    }

    auto playBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png"), this, menu_selector(IslandSelectLayer::onPlay));
    
    m_buttonMenu->addChild(playBtn);
    m_buttonMenu->setPositionX(BG->getPositionX());
    m_buttonMenu->setPositionY(BG->getPositionY()+35);
    Mod::get()->setSavedValue("islandpopuptag", button->getTag());

    //Normal mode progress bar
    int per = 100;
    std::vector<int> normalPer(per, 0);

    std::vector<int> completePer(level->m_normalPercent, 100);

    auto levelVector = normalPer;
    auto completedVector = completePer;

    //progress bar
    auto bar = CCSprite::create("GJ_progressBar_001.png");
    bar->setScale(0.7f);
    bar->setPosition(BG->getPosition());
    bar->setPositionX(bar->getPositionX());
    bar->setPositionY(bar->getPositionY() - 153.5);
    bar->setColor({ 0, 0, 0 });
    bar->setOpacity(125);
    bar->setZOrder(1);
    bar->setID("progress-bar-normal"_spr);

    m_mainLayer->addChild(bar);

    float size = (float)completedVector.size() / (float)levelVector.size();

    auto status = CCLabelBMFont::create(fmt::format("{}%", completedVector.size(), levelVector.size()).c_str(), "bigFont.fnt");
    status->setPosition({ bar->getPosition() });
    status->limitLabelWidth(170, .7f, .3f);
    status->setScale(0.4f);
    status->setZOrder(2);
    status->setID("status"_spr);
    status->setPositionY(status->getPositionY() + 108);
    m_mainLayer->addChild(status);


    auto normal = CCLabelBMFont::create("Normal Mode", "bigFont.fnt");
    normal->setPosition(status->getPosition());
    normal->setID("normal"_spr);

    normal->setPositionY(normal->getPositionY() + 20);
    normal->setScale(0.4f);
    m_mainLayer->addChild(normal);

    auto progress = CCSprite::create("GJ_progressBar_001.png");
    progress->setColor({ 0,255,0 });
    progress->setScaleX(0.985f);
    progress->setScaleY(0.860f);
    progress->setOpacity(255);
    bar->addChild(progress);
    bar->setPositionY(bar->getPositionY() + 108);
    progress->setAnchorPoint({ 0.f,0.5f });
    progress->setPosition({ 2.5f, 10.f });
    progress->setID("progress-bar-internal"_spr);

    CCRect progressRect = progress->getTextureRect();
    progressRect.size.width *= size;
    progress->setTextureRect(progressRect);

    //practice progress bar

    int pper = 100;
    std::vector<int> pnormalPer(pper, 0);

    std::vector<int> pcompletePer(level->m_practicePercent, 100);

    auto plevelVector = pnormalPer;
    auto pcompletedVector = pcompletePer;

    //progress bar
    auto pbar = CCSprite::create("GJ_progressBar_001.png");
    pbar->setScale(0.7f);
    pbar->setPosition(BG->getPosition());

    pbar->setPositionX(pbar->getPositionX());
    pbar->setPositionY(pbar->getPositionY() - 150.5);
    pbar->setColor({ 0, 0, 0 });
    pbar->setOpacity(125);
    pbar->setZOrder(1);
    pbar->setID("progress-bar"_spr);

    m_mainLayer->addChild(pbar);

    float psize = (float)pcompletedVector.size() / (float)plevelVector.size();

    auto pstatus = CCLabelBMFont::create(fmt::format("{}%", pcompletedVector.size(), plevelVector.size()).c_str(), "bigFont.fnt");
    pstatus->setPosition({ pbar->getPosition() });
    pstatus->limitLabelWidth(170, .7f, .3f);
    pstatus->setScale(0.4f);
    pstatus->setZOrder(2);
    pstatus->setID("practice status"_spr);
    pstatus->setPositionY(pstatus->getPositionY() + 58);
    m_mainLayer->addChild(pstatus);


    auto practice = CCLabelBMFont::create("Practice Mode", "bigFont.fnt");
    practice->setPosition(pstatus->getPosition());
    practice->setID("practice"_spr);

    practice->setPositionY(practice->getPositionY() + 20);
    practice->setScale(0.4f);
    m_mainLayer->addChild(practice);

    auto pprogress = CCSprite::create("GJ_progressBar_001.png");
    pprogress->setColor({ 0,255,255 });
    pprogress->setScaleX(0.985f);
    pprogress->setScaleY(0.860f);
    pprogress->setOpacity(255);
    pbar->addChild(pprogress);
    pbar->setPositionY(pbar->getPositionY() + 58);
    pprogress->setAnchorPoint({ 0.f,0.5f });
    pprogress->setPosition({ 2.5f, 10.f });
    pprogress->setID("progress-bar-internal"_spr);

    CCRect pprogressRect = pprogress->getTextureRect();
    pprogressRect.size.width *= psize;
    pprogress->setTextureRect(pprogressRect);

    IslandSelectLayer selectLayer;

    selectLayer.createStars(level, m_mainLayer);

    return true;
}

IslandLevel* IslandLevel::create(std::string const& title, GJGameLevel* level, CCMenuItemSpriteExtra* button) {
    auto ret = new IslandLevel();
    if (ret && ret->initAnchored(300.f, 260.f, title, level, button)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

cocos2d::CCScene* IslandLevel::scene(std::string const& title, GJGameLevel* level, CCMenuItemSpriteExtra* button) {
    auto scene = cocos2d::CCScene::create();
    auto popup = IslandLevel::create(title, level, button);
    if (popup)
        scene->addChild(popup);
    return scene;
}
