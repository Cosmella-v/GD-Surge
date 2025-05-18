#include <Geode/Geode.hpp>
#include <Surge/layers/IslandSelectLayer.h>
#include <Surge/layers/IslandNode.h>
#include <Surge/layers/IslandLevel.hpp>

using namespace geode::prelude;

ccColor3B colors2s[] = {
    {255, 0, 0},
    {0, 255, 0},
    {0, 0, 255}
};
int numColors2s = sizeof(colors2s) / sizeof(colors2s[0]);
int currentColorIndex2s = 0;

IslandSelectLayer* IslandSelectLayer::create(int page) {
    auto ret = new IslandSelectLayer();
    if (ret && ret->init(page)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};

CCScene* IslandSelectLayer::scene(int page) {
    auto layer = IslandSelectLayer::create(page);
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}

bool IslandSelectLayer::init(int page) {
    if (!CCLayer::init()) return false;

    setKeypadEnabled(true);
    setTouchEnabled(true);
    setKeyboardEnabled(true);

    this->setID("IslandSelectLayer"_spr);
    setKeypadEnabled(true);
    auto node = more::IslandNode::create(1,this);
    auto node2 = more::IslandNode::create(1, this);
    auto node3 = more::IslandNode::create(1, this);

    auto GM = GameManager::sharedState();
    auto GLM = GameLevelManager::sharedState();
   
    CCString* path = CCString::createWithFormat(
        "island_%02d.png"_spr,
        1
    );

    CCSprite* sprite = CCSprite::createWithSpriteFrameName(
        path->getCString()
    );

    CCString* path2 = CCString::createWithFormat(
        "island_%02d.png"_spr,
        2
    );

    CCSprite* sprite2 = CCSprite::createWithSpriteFrameName(
        path2->getCString()
    );


    CCString* path3 = CCString::createWithFormat(
        "island_%02d.png"_spr,
        3
    );

    CCSprite* sprite3 = CCSprite::createWithSpriteFrameName(
        path->getCString()
    );

    CCSprite* backSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backSpr, this, menu_selector(IslandSelectLayer::onClose));

    CCMenu* backMenu = CCMenu::create();
    backMenu->addChild(backBtn);
    addChild(backMenu, 1);

    backMenu->setPosition(ccp(CCDirector::sharedDirector()->getScreenLeft() + 25.f, CCDirector::sharedDirector()->getScreenTop() - 22.f));

    CCSprite* Dashlands = CCSprite::createWithSpriteFrameName("islandLabel_01_001.png"_spr);

    CCSprite* ToxicFactory = CCSprite::createWithSpriteFrameName("islandLabel_02_001.png"_spr);

    auto ComingSoon = CCLabelBMFont::create("Coming Soon","bigFont.fnt");

    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();

    m_fWindowWidth = winSize.width;

    CCMenu* dashlandsmenu = CCMenu::create();


    CCSprite* unkspr = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr1 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr2 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr3 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr4 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr5 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);

    CCSprite* unkspr6 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr7 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unksp8 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr9 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);
    CCSprite* unkspr10 = CCSprite::createWithSpriteFrameName("islandLevelBtn_001.png"_spr);

    //locked sprites
    CCSprite* level2 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level3 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level4 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level5 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level6 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level7 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level8 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level9 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);
    CCSprite* level10 = CCSprite::createWithSpriteFrameName("islandLevelBtn_locked_001.png"_spr);


    //pointers animation 1
    CCSprite* point1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* point2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* point3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* point4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* point5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 2
    CCSprite* Bpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Bpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Bpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Bpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Bpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 3
    CCSprite* Mpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Mpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Mpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Mpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Mpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 4
    CCSprite* Ypoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Ypoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Ypoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Ypoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Ypoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 5
    CCSprite* Fpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Fpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Fpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Fpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Fpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 6
    CCSprite* SPpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* SPpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* SPpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* SPpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* SPpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 7
    CCSprite* Spoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Spoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Spoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Spoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Spoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 8
    CCSprite* Epoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Epoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Epoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Epoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Epoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Epoint6 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Epoint7 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Epoint8 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 9
    CCSprite* Rpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Rpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Rpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Rpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* Rpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    //pointers animation 10
    CCSprite* MDOpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* MDOpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* MDOpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* MDOpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
    CCSprite* MDOpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

    dashlandsmenu->addChild(point1);
    dashlandsmenu->addChild(point2);
    dashlandsmenu->addChild(point3);
    dashlandsmenu->addChild(point4);
    dashlandsmenu->addChild(point5);

    dashlandsmenu->addChild(Bpoint1);
    dashlandsmenu->addChild(Bpoint2);
    dashlandsmenu->addChild(Bpoint3);
    dashlandsmenu->addChild(Bpoint4);
    dashlandsmenu->addChild(Bpoint5);

    dashlandsmenu->addChild(Mpoint1);
    dashlandsmenu->addChild(Mpoint2);
    dashlandsmenu->addChild(Mpoint3);
    dashlandsmenu->addChild(Mpoint4);
    dashlandsmenu->addChild(Mpoint5);

    dashlandsmenu->addChild(Ypoint1);
    dashlandsmenu->addChild(Ypoint2);
    dashlandsmenu->addChild(Ypoint3);
    dashlandsmenu->addChild(Ypoint4);
    dashlandsmenu->addChild(Ypoint5);

    CCMenuItemSpriteExtra* level1Btn = CCMenuItemSpriteExtra::create(unkspr, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level1Btn->setTag(30);
    level1Btn->setPosition(-189, -15);

    //LEVEL 1 POINTS
    //point 1
    point1->setPosition(level1Btn->getPosition());
    point1->setPositionX(point1->getPositionX()+20);
    point1->setPositionY(-20);
    point1->setScale(0.5);
    point1->setScaleX(1);
    //point 2
    point2->setPosition(level1Btn->getPosition());
    point2->setPositionX(point2->getPositionX()+32);
    point2->setPositionY(-25);
    point2->setScale(0.5);
    point2->setScaleX(1);
    //point 3
    point3->setPosition(level1Btn->getPosition());
    point3->setPositionX(point3->getPositionX()+50);
    point3->setPositionY(-22);
    point3->setScale(0.5);
    point3->setScaleX(1);
    //point 4
    point4->setPosition(level1Btn->getPosition());
    point4->setPositionX(point4->getPositionX()+77);
    point4->setPositionY(-22.5);
    point4->setScale(0.5);
    point4->setScaleX(1);
    //point 5
    point5->setPosition(level1Btn->getPosition());
    point5->setPositionX(point5->getPositionX()+89.7);
    point5->setPositionY(-26);
    point5->setScale(0.5);
    point5->setScaleX(1);
    CCMenuItemSpriteExtra* level2Btn = CCMenuItemSpriteExtra::create(unkspr1, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level2Btn->setTag(31);
    level2Btn->setPosition(-80, -30);
    level2Btn->setVisible(false);
    level2->setPosition({ -80, -30 });

    //LEVEL 2 POINTS
    //point 1
    Bpoint1->setPosition(level2Btn->getPosition());
    Bpoint1->setPositionX(Bpoint1->getPositionX() + 7);
    Bpoint1->setPositionY(-22);
    Bpoint1->setScale(0.5);
    Bpoint1->setScaleX(1);
    //point 2
    Bpoint2->setPosition(level2Btn->getPosition());
    Bpoint2->setPositionX(Bpoint2->getPositionX() + 13);
    Bpoint2->setPositionY(-15);
    Bpoint2->setScale(0.5);
    Bpoint2->setScaleX(1);
    //point 3
    Bpoint3->setPosition(level2Btn->getPosition());
    Bpoint3->setPositionX(Bpoint3->getPositionX() + 23);
    Bpoint3->setPositionY(-7);
    Bpoint3->setScale(0.5);
    Bpoint3->setScaleX(1);
    //point 4
    Bpoint4->setPosition(level2Btn->getPosition());
    Bpoint4->setPositionX(Bpoint4->getPositionX() + 40);
    Bpoint4->setPositionY(2.5);
    Bpoint4->setScale(0.5);
    Bpoint4->setScaleX(1);
    //point 5
    Bpoint5->setPosition(level2Btn->getPosition());
    Bpoint5->setPositionX(Bpoint5->getPositionX() + 52);
    Bpoint5->setPositionY(5);
    Bpoint5->setScale(0.5);
    Bpoint5->setScaleX(1);

    CCMenuItemSpriteExtra* level3Btn = CCMenuItemSpriteExtra::create(unkspr2, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level3Btn->setTag(32);
    level3Btn->setPosition(-10, 10);
    level3Btn->setVisible(false);
    level3->setPosition({ -10, 10 });

    //LEVEL 3 POINTS
    //point 1
    Mpoint1->setPosition(level3Btn->getPosition());
    Mpoint1->setPositionX(Mpoint1->getPositionX() + 13);
    Mpoint1->setPositionY(2);
    Mpoint1->setScale(0.5);
    Mpoint1->setScaleX(1);
    //point 2
    Mpoint2->setPosition(level3Btn->getPosition());
    Mpoint2->setPositionX(Mpoint2->getPositionX() + 17);
    Mpoint2->setPositionY(-11);
    Mpoint2->setScale(0.5);
    Mpoint2->setScaleX(1);
    //point 3
    Mpoint3->setPosition(level3Btn->getPosition());
    Mpoint3->setPositionX(Mpoint3->getPositionX() + 19);
    Mpoint3->setPositionY(-20);
    Mpoint3->setScale(0.5);
    Mpoint3->setScaleX(1);
    //point 4
    Mpoint4->setPosition(level3Btn->getPosition());
    Mpoint4->setPositionX(Mpoint4->getPositionX() + 25);
    Mpoint4->setPositionY(-26);
    Mpoint4->setScale(0.5);
    Mpoint4->setScaleX(1);
    //point 5
    Mpoint5->setPosition(level3Btn->getPosition());
    Mpoint5->setPositionX(Mpoint5->getPositionX() + 42);
    Mpoint5->setPositionY(-28);
    Mpoint5->setScale(0.5);
    Mpoint5->setScaleX(1);

    auto scaleAction = CCScaleTo::create(0.5,1, 0.5);
    auto scaleAction2 = CCScaleTo::create(0.5, 1);

    auto scaleWithBounce = CCEaseBounceOut::create(scaleAction);
    auto scaleWithBounce2 = CCEaseBounceOut::create(scaleAction2);

    auto wlevel1 = GLM->getMainLevel(2001, false);


    auto wlevel2 = GLM->getMainLevel(2002, false);


    auto wlevel3 = GLM->getMainLevel(2003, false);


    auto wlevel4 = GLM->getMainLevel(2004, false);


    auto wlevel5 = GLM->getMainLevel(2005, false);


    auto wlevel6 = GLM->getMainLevel(2006, false);


    auto wlevel7 = GLM->getMainLevel(2007, false);


    auto wlevel8 = GLM->getMainLevel(2008, false);


    auto wlevel9 = GLM->getMainLevel(2009, false);


    auto wlevel10 = GLM->getMainLevel(2010, false);

    auto level1complete = Mod::get()->getSavedValue<int>("islandlevel1complete");

    auto level2complete = Mod::get()->getSavedValue<int>("islandlevel2complete");

    auto level3complete = Mod::get()->getSavedValue<int>("islandlevel3complete");

    auto level4complete = Mod::get()->getSavedValue<int>("islandlevel4complete");

    auto level5complete = Mod::get()->getSavedValue<int>("islandlevel5complete");

    auto level6complete = Mod::get()->getSavedValue<int>("islandlevel6complete");

    auto level7complete = Mod::get()->getSavedValue<int>("islandlevel7complete");

    auto level8complete = Mod::get()->getSavedValue<int>("islandlevel8complete");

    auto level9complete = Mod::get()->getSavedValue<int>("islandlevel9complete");
    
    auto level10complete = Mod::get()->getSavedValue<int>("islandlevel10complete");


    //level 1 to level 2 animation
    if (wlevel1->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel1complete", 0);
    }
    if (wlevel1->m_normalPercent == 100 && wlevel2->m_normalPercent == 0 && level1complete == 0)
    {
        point1->setScaleY(1.2);
        point2->setScaleY(1.2);
        point3->setScaleY(1.2);
        point4->setScaleY(1.2);
        point5->setScaleY(1.2);

        point1->setScaleX(2);
        point2->setScaleX(2);
        point3->setScaleX(2);
        point4->setScaleX(2);
        point5->setScaleX(2);
        //opacty
        point1->setOpacity(0);
        point2->setOpacity(0);
        point3->setOpacity(0);
        point4->setOpacity(0);
        point5->setOpacity(0);
        level2Btn->setOpacity(0);
    
        point1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        point2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        point3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        point4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        point5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        
        level2Btn->setScale(1.5);
        level2Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 1);
        level2Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.8),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));

        Mod::get()->setSavedValue("islandlevel1complete", 1);
    }
    else
    {
        if (wlevel1->m_normalPercent == 100)
        {
            level2Btn->setVisible(true);
        }
        else
        {
            point1->setOpacity(0);
            point2->setOpacity(0);
            point3->setOpacity(0);
            point4->setOpacity(0);
            point5->setOpacity(0);
        }
       
    }

    if (wlevel2->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel2complete", 0);
    }
    if (wlevel2->m_normalPercent == 100 && wlevel3->m_normalPercent == 0 && level2complete == 0)
    {
        //level 2 to level 3 animation
        Bpoint1->setScaleY(1.2);
        Bpoint2->setScaleY(1.2);
        Bpoint3->setScaleY(1.2);
        Bpoint4->setScaleY(1.2);
        Bpoint5->setScaleY(1.2);

        Bpoint1->setScaleX(2);
        Bpoint2->setScaleX(2);
        Bpoint3->setScaleX(2);
        Bpoint4->setScaleX(2);
        Bpoint5->setScaleX(2);
        //opacty
        Bpoint1->setOpacity(0);
        Bpoint2->setOpacity(0);
        Bpoint3->setOpacity(0);
        Bpoint4->setOpacity(0);
        Bpoint5->setOpacity(0);
        level3Btn->setOpacity(0);

        Bpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Bpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Bpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Bpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Bpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

        level3Btn->setScale(1.5);
        level3Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 2);
        level3Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.8),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));
        Mod::get()->setSavedValue("islandlevel2complete", 1);
    }
    else
    {
        if (wlevel2->m_normalPercent == 100)
        {
            level3Btn->setVisible(true);
        }
        else
        {
            Bpoint1->setOpacity(0);
            Bpoint2->setOpacity(0);
            Bpoint3->setOpacity(0);
            Bpoint4->setOpacity(0);
            Bpoint5->setOpacity(0);
        }
    }
    /*dashlandsmenu->addChild(particles, 2);*/
    // Establecer la escala inicial como 0 para que est�n invisibles
    
    CCMenuItemSpriteExtra* level4Btn = CCMenuItemSpriteExtra::create(unkspr3, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level4Btn->setTag(33);
    level4Btn->setPosition(50, -25);
    level4Btn->setVisible(false);
    level4->setPosition({ 50, -25 });

    //LEVEL 4 POINTS
    //point 1
    Ypoint1->setPosition(level4Btn->getPosition());
    Ypoint1->setPositionX(Ypoint1->getPositionX() + 20);
    Ypoint1->setPositionY(-24);
    Ypoint1->setScale(0.5);
    Ypoint1->setScaleX(1);
    //point 2
    Ypoint2->setPosition(level4Btn->getPosition());
    Ypoint2->setPositionX(Ypoint2->getPositionX() + 36);
    Ypoint2->setScale(0.5);
    Ypoint2->setScaleX(1);
    //point 3
    Ypoint3->setPosition(level4Btn->getPosition());
    Ypoint3->setPositionX(Ypoint3->getPositionX() + 51);
    Ypoint3->setPositionY(-22.5);
    Ypoint3->setScale(0.5);
    Ypoint3->setScaleX(1);
    //point 4
    Ypoint4->setPosition(level4Btn->getPosition());
    Ypoint4->setPositionX(Ypoint4->getPositionX() + 72);
    Ypoint4->setPositionY(-25.5);
    Ypoint4->setScale(0.5);
    Ypoint4->setScaleX(1);
    //point 5
    Ypoint5->setPosition(level4Btn->getPosition());
    Ypoint5->setPositionX(Ypoint5->getPositionX() + 88);
    Ypoint5->setPositionY(-20.5);
    Ypoint5->setScale(0.5);
    Ypoint5->setScaleX(1);


    if (wlevel3->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel3complete", 0);
    }
    //level 3 to level 4 animation
    if (wlevel3->m_normalPercent == 100 && wlevel4->m_normalPercent == 0 && level3complete == 0)
    {
        Mpoint1->setScaleY(1.2);
        Mpoint2->setScaleY(1.2);
        Mpoint3->setScaleY(1.2);
        Mpoint4->setScaleY(1.2);
        Mpoint5->setScaleY(1.2);

        Mpoint1->setScaleX(2);
        Mpoint2->setScaleX(2);
        Mpoint3->setScaleX(2);
        Mpoint4->setScaleX(2);
        Mpoint5->setScaleX(2);
        //opacty
        Mpoint1->setOpacity(0);
        Mpoint2->setOpacity(0);
        Mpoint3->setOpacity(0);
        Mpoint4->setOpacity(0);
        Mpoint5->setOpacity(0);
        level4Btn->setOpacity(0);

        Mpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Mpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Mpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Mpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Mpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

        level4Btn->setScale(1.5);
        level4Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 3);
        level4Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.8),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));
        Mod::get()->setSavedValue("islandlevel3complete", 1);
    }
    else
    {
        if (wlevel3->m_normalPercent == 100)
        {
            level4Btn->setVisible(true);
        }
        else
        {
            Mpoint1->setOpacity(0);
            Mpoint2->setOpacity(0);
            Mpoint3->setOpacity(0);
            Mpoint4->setOpacity(0);
            Mpoint5->setOpacity(0);
        }
    }
    

    CCMenuItemSpriteExtra* level5Btn = CCMenuItemSpriteExtra::create(unkspr4, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level5Btn->setTag(34);
    level5Btn->setPosition(155, -10);
    level5Btn->setVisible(false);
    level5->setPosition({ 155, -10 });


    if (wlevel4->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel4complete", 0);
    }
    //level 4 to level 5 animation
    if (wlevel4->m_normalPercent == 100 && wlevel5->m_normalPercent == 0 && level4complete == 0)
    {
        Ypoint1->setScaleY(1.2);
        Ypoint2->setScaleY(1.2);
        Ypoint3->setScaleY(1.2);
        Ypoint4->setScaleY(1.2);
        Ypoint5->setScaleY(1.2);

        Ypoint1->setScaleX(2);
        Ypoint2->setScaleX(2);
        Ypoint3->setScaleX(2);
        Ypoint4->setScaleX(2);
        Ypoint5->setScaleX(2);
        //opacty
        Ypoint1->setOpacity(0);
        Ypoint2->setOpacity(0);
        Ypoint3->setOpacity(0);
        Ypoint4->setOpacity(0);
        Ypoint5->setOpacity(0);
        level5Btn->setOpacity(0);

        Ypoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Ypoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Ypoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Ypoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Ypoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

        level5Btn->setScale(1.5);
        level5Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 4);
        level5Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.8),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));
        Mod::get()->setSavedValue("islandlevel4complete", 1);
    }
    else
    {
        if (wlevel4->m_normalPercent == 100)
        {
            level5Btn->setVisible(true);
        }
        else
        {
            Ypoint1->setOpacity(0);
            Ypoint2->setOpacity(0);
            Ypoint3->setOpacity(0);
            Ypoint4->setOpacity(0);
            Ypoint5->setOpacity(0);
        }
    }

    auto ToxicFactoryMenu = CCMenu::create();
    CCMenuItemSpriteExtra* level6Btn = CCMenuItemSpriteExtra::create(unkspr5, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level6Btn->setTag(35);
    level6Btn->setPosition(-175, -12);
    level6Btn->setVisible(false);
    level6->setPosition(level6Btn->getPosition());

    //LEVEL 6 POINTS
    // point 1
    SPpoint1->setPosition(level6Btn->getPosition());
    SPpoint1->setPositionX(SPpoint1->getPositionX() + 20);
    SPpoint1->setPositionY(-16);
    SPpoint1->setScale(0.5);
    SPpoint1->setScaleX(1);
    //point 2
    SPpoint2->setPosition(level6Btn->getPosition());
    SPpoint2->setPositionX(SPpoint2->getPositionX() + 38);
    SPpoint2->setPositionY(-16.5);
    SPpoint2->setScale(0.5);
    SPpoint2->setScaleX(1);
    //point 3
    SPpoint3->setPosition(level6Btn->getPosition());
    SPpoint3->setPositionX(SPpoint3->getPositionX() + 55);
    SPpoint3->setPositionY(-11);
    SPpoint3->setScale(0.5);
    SPpoint3->setScaleX(1);
    //point 4
    SPpoint4->setPosition(level6Btn->getPosition());
    SPpoint4->setPositionX(SPpoint4->getPositionX() + 72);
    SPpoint4->setPositionY(-12);
    SPpoint4->setScale(0.5);
    SPpoint4->setScaleX(1);
    //point 5
    SPpoint5->setPosition(level6Btn->getPosition());
    SPpoint5->setPositionX(SPpoint5->getPositionX() + 85);
    SPpoint5->setPositionY(-19.5);
    SPpoint5->setScale(0.5);
    SPpoint5->setScaleX(1);


    ToxicFactoryMenu->addChild(SPpoint1,2);
    ToxicFactoryMenu->addChild(SPpoint2, 2);
    ToxicFactoryMenu->addChild(SPpoint3, 2);
    ToxicFactoryMenu->addChild(SPpoint4, 2);
    ToxicFactoryMenu->addChild(SPpoint5, 2);


    CCMenuItemSpriteExtra* level7Btn = CCMenuItemSpriteExtra::create(unkspr6, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level7Btn->setTag(36);
    level7Btn->setPosition(-73, -28);
    level7Btn->setVisible(false);
    level7->setPosition(level7Btn->getPosition());

    //LEVEL 7 POINTS
    // point 1
    Spoint1->setPosition(level7Btn->getPosition());
    Spoint1->setPositionX(Spoint1->getPositionX() + 10);
    Spoint1->setPositionY(-8);
    Spoint1->setScale(0.5);
    Spoint1->setScaleX(1);
    //point 2
    Spoint2->setPosition(level7Btn->getPosition());
    Spoint2->setPositionX(Spoint2->getPositionX() + 15);
    Spoint2->setPositionY(0);
    Spoint2->setScale(0.5);
    Spoint2->setScaleX(1);
    //point 3
    Spoint3->setPosition(level7Btn->getPosition());
    Spoint3->setPositionX(Spoint3->getPositionX() + 30);
    Spoint3->setPositionY(7);
    Spoint3->setScale(0.5);
    Spoint3->setScaleX(1);
    //point 4
    Spoint4->setPosition(level7Btn->getPosition());
    Spoint4->setPositionX(Spoint4->getPositionX() + 44);
    Spoint4->setPositionY(9.5);
    Spoint4->setScale(0.5);
    Spoint4->setScaleX(1);

    ToxicFactoryMenu->addChild(Spoint1, 2);
    ToxicFactoryMenu->addChild(Spoint2, 2);
    ToxicFactoryMenu->addChild(Spoint3, 2);
    ToxicFactoryMenu->addChild(Spoint4, 2);

    if (wlevel6->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel6complete", 0);
    }
    if (wlevel6->m_normalPercent == 100 && wlevel7->m_normalPercent == 0 && level6complete == 0)
    {
        SPpoint1->setScaleY(1.2);
        SPpoint2->setScaleY(1.2);
        SPpoint3->setScaleY(1.2);
        SPpoint4->setScaleY(1.2);
        SPpoint5->setScaleY(1.2);

        SPpoint1->setScaleX(2);
        SPpoint2->setScaleX(2);
        SPpoint3->setScaleX(2);
        SPpoint4->setScaleX(2);
        SPpoint5->setScaleX(2);
        //opacty
        SPpoint1->setOpacity(0);
        SPpoint2->setOpacity(0);
        SPpoint3->setOpacity(0);
        SPpoint4->setOpacity(0);
        SPpoint5->setOpacity(0);
        level7Btn->setOpacity(0);

        SPpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        SPpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        SPpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        SPpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        SPpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

        level7Btn->setScale(1.5);
        level7Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 6);
        level7Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.8),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));
        Mod::get()->setSavedValue("islandlevel6complete", 1);
    }
    else
    {
        if (wlevel6->m_normalPercent == 100)
        {
            level7Btn->setVisible(true);
        }
        else
        {
            SPpoint1->setOpacity(0);
            SPpoint2->setOpacity(0);
            SPpoint3->setOpacity(0);
            SPpoint4->setOpacity(0);
            SPpoint5->setOpacity(0);
        }
    }

    
    CCMenuItemSpriteExtra* level8Btn = CCMenuItemSpriteExtra::create(unkspr7, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level8Btn->setTag(37);
    level8Btn->setPosition(-10, 15);
    level8Btn->setVisible(false);
    level8->setPosition(level8Btn->getPosition());

    //LEVEL 8 POINTS
    //point 1
    Epoint1->setPosition(level8Btn->getPosition());
    Epoint1->setPositionX(Epoint1->getPositionX() + 10);
    Epoint1->setPositionY(3);
    Epoint1->setScale(0.5);
    Epoint1->setScaleX(1);
    //point 2
    Epoint2->setPosition(level8Btn->getPosition());
    Epoint2->setPositionX(Epoint2->getPositionX());
    Epoint2->setPositionY(-7);
    Epoint2->setScale(0.5);
    Epoint2->setScaleX(1);
    //point 3
    Epoint3->setPosition(level8Btn->getPosition());
    Epoint3->setPositionX(Epoint3->getPositionX() - 10);
    Epoint3->setPositionY(-11);
    Epoint3->setScale(0.5);
    Epoint3->setScaleX(1);
    //point 4
    Epoint4->setPosition(level8Btn->getPosition());
    Epoint4->setPositionX(Epoint4->getPositionX() - 15 );
    Epoint4->setPositionY(-20);
    Epoint4->setScale(0.5);
    Epoint4->setScaleX(1);
    //point 5
    Epoint5->setPosition(level8Btn->getPosition());
    Epoint5->setPositionX(Epoint5->getPositionX() - 5);
    Epoint5->setPositionY(-32);
    Epoint5->setScale(0.5);
    Epoint5->setScaleX(1);
    //point 6
    Epoint6->setPosition(level8Btn->getPosition());
    Epoint6->setPositionX(Epoint6->getPositionX() + 17);
    Epoint6->setPositionY(-36.5);
    Epoint6->setScale(0.5);
    Epoint6->setScaleX(1);
    //point 7
    Epoint7->setPosition(level8Btn->getPosition());
    Epoint7->setPositionX(Epoint7->getPositionX() + 41);
    Epoint7->setPositionY(-40);
    Epoint7->setScale(0.5);
    Epoint7->setScaleX(1);
    //point 8
    Epoint8->setPosition(level8Btn->getPosition());
    Epoint8->setPositionX(Epoint8->getPositionX() + 63);
    Epoint8->setPositionY(-40.5);
    Epoint8->setScale(0.5);
    Epoint8->setScaleX(1);


    ToxicFactoryMenu->addChild(Epoint1, 2);
    ToxicFactoryMenu->addChild(Epoint2, 2);
    ToxicFactoryMenu->addChild(Epoint3, 2);
    ToxicFactoryMenu->addChild(Epoint4, 2);
    ToxicFactoryMenu->addChild(Epoint5, 2);
    ToxicFactoryMenu->addChild(Epoint6, 2);
    ToxicFactoryMenu->addChild(Epoint7, 2);
    ToxicFactoryMenu->addChild(Epoint8, 2);
    if (wlevel7->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel7complete", 0);
    }
    ////level 7 to level 8 animation
    if (wlevel7->m_normalPercent == 100 && wlevel8->m_normalPercent == 0 && level7complete == 0)
    {
        Spoint1->setScaleY(1.2);
        Spoint2->setScaleY(1.2);
        Spoint3->setScaleY(1.2);
        Spoint4->setScaleY(1.2);
    

        Spoint1->setScaleX(2);
        Spoint2->setScaleX(2);
        Spoint3->setScaleX(2);
        Spoint4->setScaleX(2);

        //opacty
        Spoint1->setOpacity(0);
        Spoint2->setOpacity(0);
        Spoint3->setOpacity(0);
        Spoint4->setOpacity(0);

        level8Btn->setOpacity(0);

        Spoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Spoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Spoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Spoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
      

        level8Btn->setScale(1.5);
        level8Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 7);
        level8Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.5),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));
        Mod::get()->setSavedValue("islandlevel7complete", 1);
    }
    else
    {
        if (wlevel7->m_normalPercent == 100)
        {
            level8Btn->setVisible(true);
        }
        else
        {
            Spoint1->setOpacity(0);
            Spoint2->setOpacity(0);
            Spoint3->setOpacity(0);
            Spoint4->setOpacity(0);
            Spoint5->setOpacity(0);
        }
    }

    
    CCMenuItemSpriteExtra* level9Btn = CCMenuItemSpriteExtra::create(unksp8, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level9Btn->setTag(38);
    level9Btn->setPosition(80, -38);
    level9Btn->setVisible(false);
    level9->setPosition(level9Btn->getPosition());

    //LEVEL 9 POINTS
    //point 1
    Rpoint1->setPosition(level9Btn->getPosition());
    Rpoint1->setPositionX(Rpoint1->getPositionX() + 16);
    Rpoint1->setPositionY(-34);
    Rpoint1->setScale(0.5);
    Rpoint1->setScaleX(1);
    //point 2
    Rpoint2->setPosition(level9Btn->getPosition());
    Rpoint2->setPositionX(Rpoint2->getPositionX() + 25);
    Rpoint2->setPositionY(-27);
    Rpoint2->setScale(0.5);
    Rpoint2->setScaleX(1);
    //point 3
    Rpoint3->setPosition(level9Btn->getPosition());
    Rpoint3->setPositionX(Rpoint3->getPositionX() + 34);
    Rpoint3->setPositionY(-20.5);
    Rpoint3->setScale(0.5);
    Rpoint3->setScaleX(1);
    //point 4
    Rpoint4->setPosition(level9Btn->getPosition());
    Rpoint4->setPositionX(Rpoint4->getPositionX() + 45);
    Rpoint4->setPositionY(-16);
    Rpoint4->setScale(0.5);
    Rpoint4->setScaleX(1);
    //point 5
    Rpoint5->setPosition(level9Btn->getPosition());
    Rpoint5->setPositionX(Rpoint5->getPositionX() + 67);
    Rpoint5->setPositionY(-12);
    Rpoint5->setScale(0.5);
    Rpoint5->setScaleX(1);


    ToxicFactoryMenu->addChild(Rpoint1, 2);
    ToxicFactoryMenu->addChild(Rpoint2, 2);
    ToxicFactoryMenu->addChild(Rpoint3, 2);
    ToxicFactoryMenu->addChild(Rpoint4, 2);
    ToxicFactoryMenu->addChild(Rpoint5, 2);

    if (wlevel8->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel8complete", 0);
    }
    //level 8 to level 9 animation
    if (wlevel8->m_normalPercent == 100 && wlevel9->m_normalPercent == 0 && level8complete == 0)
    {
        Epoint1->setScaleY(1.2);
        Epoint2->setScaleY(1.2);
        Epoint3->setScaleY(1.2);
        Epoint4->setScaleY(1.2);
        Epoint5->setScaleY(1.2);
        Epoint6->setScaleY(1.2);
        Epoint7->setScaleY(1.2);
        Epoint8->setScaleY(1.2);

        Epoint1->setScaleX(2);
        Epoint2->setScaleX(2);
        Epoint3->setScaleX(2);
        Epoint4->setScaleX(2);
        Epoint5->setScaleX(2);
        Epoint6->setScaleX(2);
        Epoint7->setScaleX(2);
        Epoint8->setScaleX(2);
        //opacty
        Epoint1->setOpacity(0);
        Epoint2->setOpacity(0);
        Epoint3->setOpacity(0);
        Epoint4->setOpacity(0);
        Epoint5->setOpacity(0);
        Epoint6->setOpacity(0);
        Epoint7->setOpacity(0);
        Epoint8->setOpacity(0);
      

        level9Btn->setOpacity(0);

        Epoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Epoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Epoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Epoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Epoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Epoint6->runAction(CCSequence::create(CCDelayTime::create(1.8), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Epoint7->runAction(CCSequence::create(CCDelayTime::create(2.1), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Epoint8->runAction(CCSequence::create(CCDelayTime::create(2.4), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

        level9Btn->setScale(1.5);
        level9Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 8);
        level9Btn->runAction(CCSequence::create(
            CCDelayTime::create(2.7),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));
        Mod::get()->setSavedValue("islandlevel8complete", 1);
    }
    else
    {
        if (wlevel8->m_normalPercent == 100)
        {
            level9Btn->setVisible(true);
        }
        else
        {
            Epoint1->setOpacity(0);
            Epoint2->setOpacity(0);
            Epoint3->setOpacity(0);
            Epoint4->setOpacity(0);
            Epoint5->setOpacity(0);
            Epoint6->setOpacity(0);
            Epoint7->setOpacity(0);
            Epoint8->setOpacity(0);
        }
    }

    CCMenuItemSpriteExtra* level10Btn = CCMenuItemSpriteExtra::create(unkspr9, this, menu_selector(IslandSelectLayer::onIslandLevel));

    level10Btn->setTag(39);
    level10Btn->setPosition(170, -10);

    level10Btn->setVisible(false);
    level10->setPosition(level10Btn->getPosition());

    if (wlevel9->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel9complete", 0);
    }
    ////level 9 to level 10 animation
    if (wlevel9->m_normalPercent == 100 && wlevel10->m_normalPercent == 0 && level9complete == 0)
    {
        Rpoint1->setScaleY(1.2);
        Rpoint2->setScaleY(1.2);
        Rpoint3->setScaleY(1.2);
        Rpoint4->setScaleY(1.2);
        Rpoint5->setScaleY(1.2);

        Rpoint1->setScaleX(2);
        Rpoint2->setScaleX(2);
        Rpoint3->setScaleX(2);
        Rpoint4->setScaleX(2);
        Rpoint5->setScaleX(2);

        //opacty
        Rpoint1->setOpacity(0);
        Rpoint2->setOpacity(0);
        Rpoint3->setOpacity(0);
        Rpoint4->setOpacity(0);
        Rpoint5->setOpacity(0);

        level10Btn->setOpacity(0);

        Rpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Rpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Rpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Rpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        Rpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

        level10Btn->setScale(1.5);
        level10Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 9);
        level10Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.8),
            CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));
        Mod::get()->setSavedValue("islandlevel9complete", 1);
    }
    else
    {
        if (wlevel9->m_normalPercent == 100)
        {
            level10Btn->setVisible(true);
        }
        else
        {
            Rpoint1->setOpacity(0);
            Rpoint2->setOpacity(0);
            Rpoint3->setOpacity(0);
            Rpoint4->setOpacity(0);
            Rpoint5->setOpacity(0);
        }
    }

    if (wlevel10->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("islandlevel10complete", 0);
    }
    //final dialogue
    if (wlevel10->m_normalPercent == 100 && level10complete == 0)
    {
        CCArray* arr = CCArray::create();
        int colour = 2; //gjsquare thingy

        auto dialog1 = DialogObject::create("The Keymaster", "Well, well, well...<d020> I see you have <cg>completed</c> the <cl>first two</c> islands.", 2 /*dialog icon*/, 1, false, { 255,255,255 });

        auto dialog2 = DialogObject::create("The Keymaster", "Not bad,<d030> not bad at all.\n<d030>I have <co>unlocked</c> <cg>online levels</c> for you.", 2 /*dialog icon*/, 1, false, { 255,255,255 });

        auto dialog3 = DialogObject::create("The Keymaster", "Or maybe, if you were in <cy>Geometry Dash Island game</c>, LOL.", 2 /*dialog icon*/, 1, false, { 255,255,255 });

        auto dialog4 = DialogObject::create("The Keymaster", "<cl>Let's see what more you can do<d010>.<d010>.<d010>.</c>", 2 /*dialog icon*/, 1, false, { 255,255,255 });
        arr->addObject(dialog1);

        arr->addObject(dialog2);

        arr->addObject(dialog3);

        arr->addObject(dialog4);




        auto dl = DialogLayer::createDialogLayer(nullptr, arr, colour);
        dl->animateInRandomSide();
        dl->setZOrder(2);

        this->addChild(dl, 3);
        Mod::get()->setSavedValue("islandlevel10complete", 1);
    }
    else
    {
        if (wlevel10->m_normalPercent == 100)
        {
            level10Btn->setVisible(true);
        }
      
    }
    ToxicFactoryMenu->addChild(level6Btn,2);
    ToxicFactoryMenu->addChild(level7Btn, 2);
    ToxicFactoryMenu->addChild(level8Btn,2);
    ToxicFactoryMenu->addChild(level9Btn, 2);
    ToxicFactoryMenu->addChild(level10Btn,2);

    ToxicFactoryMenu->addChild(level6);
    ToxicFactoryMenu->addChild(level7);
    ToxicFactoryMenu->addChild(level8);
    ToxicFactoryMenu->addChild(level9);
    ToxicFactoryMenu->addChild(level10);

    
    
    //LEVEL 5 POINTS
    //point 1
    MDOpoint1->setPosition(level5Btn->getPosition());
    MDOpoint1->setPositionX(MDOpoint1->getPositionX() + 20);
    MDOpoint1->setPositionY(-20);
    MDOpoint1->setScale(0.5);
    MDOpoint1->setScaleX(1);
    //point 2
    MDOpoint2->setPosition(level5Btn->getPosition());
    MDOpoint2->setPositionX(MDOpoint2->getPositionX() + 32);
    MDOpoint2->setPositionY(-25);
    MDOpoint2->setScale(0.5);
    MDOpoint2->setScaleX(1);
    //point 3
    MDOpoint3->setPosition(level5Btn->getPosition());
    MDOpoint3->setPositionX(MDOpoint3->getPositionX() + 50);
    MDOpoint3->setPositionY(-22);
    MDOpoint3->setScale(0.5);
    MDOpoint3->setScaleX(1);
    //point 4
    MDOpoint4->setPosition(level5Btn->getPosition());
    MDOpoint4->setPositionX(MDOpoint4->getPositionX() + 77);
    MDOpoint4->setPositionY(-22.5);
    MDOpoint4->setScale(0.5);
    MDOpoint4->setScaleX(1);
    //point 5
    MDOpoint5->setPosition(level5Btn->getPosition());
    MDOpoint5->setPositionX(MDOpoint5->getPositionX() + 89.7);
    MDOpoint5->setPositionY(-26);
    MDOpoint5->setScale(0.5);
    MDOpoint5->setScaleX(1);

    dashlandsmenu->setPosition(winSize / 2);
    dashlandsmenu->setPositionY(dashlandsmenu->getPositionY());
    //button levels
    dashlandsmenu->addChild(level1Btn);
    dashlandsmenu->addChild(level2Btn,1);
    dashlandsmenu->addChild(level3Btn,1);
    dashlandsmenu->addChild(level4Btn,1);
    dashlandsmenu->addChild(level5Btn,1);

    //skull - locked levels
    dashlandsmenu->addChild(level2);
    dashlandsmenu->addChild(level3);
    dashlandsmenu->addChild(level4);
    dashlandsmenu->addChild(level5);
    dashlandsmenu->setZOrder(1);
    /*node->addChild(dashlandsmenu);*/
    node->addChild(sprite);
    node->addChild(dashlandsmenu);
    node->addChild(Dashlands);
    node->setTag(20);

    node2->addChild(sprite2);
    node2->addChild(ToxicFactory);
    node2->addChild(ToxicFactoryMenu);
    node2->setTag(22);

    ToxicFactoryMenu->setPosition(winSize / 2);
    ToxicFactoryMenu->setPositionY(ToxicFactoryMenu->getPositionY());

    node3->addChild(sprite3);
    node3->addChild(ComingSoon);
    node3->setTag(23);

        m_mainLevels = CCArray::create();
        m_levelPages = CCArray::create();

        m_level = 0;

        m_levelPages->addObject(node);
        m_levelPages->addObject(node2);
        m_levelPages->addObject(node3);

        m_scrollLayer = BoomScrollLayer::create(m_levelPages, 0, false, nullptr, static_cast<DynamicScrollDelegate*>(this));

        m_scrollLayer->m_extendedLayer->m_delegate = static_cast<BoomScrollLayerDelegate*>(this);

        if (page)
        {
            if (page == 21)
                m_scrollLayer->instantMoveToPage(20);
            m_scrollLayer->instantMoveToPage(page);
        }
        else
        {
            scrollLayerMoved(m_scrollLayer->m_extendedLayer->getPosition()); //
        }

        auto pointer = (CCSpriteBatchNode*)m_scrollLayer->getChildren()->objectAtIndex(1);
        /*pointer->setVisible(false);*/
        pointer->setPositionY(director->getScreenBottom() - 45);
        addChild(m_scrollLayer);


        //level 5 to level 6 animation
        if (wlevel5->m_normalPercent != 100)
        {
            Mod::get()->setSavedValue("islandlevel5complete", 0);
        }
        if (wlevel5->m_normalPercent == 100 && wlevel6->m_normalPercent == 0 && level5complete == 0)
        {
            //opacty

            level6Btn->setOpacity(0);

            level6Btn->setScale(1.5);
            level6Btn->setVisible(true);

            Mod::get()->setSavedValue("wlevelunlocked", 5);

            m_scrollLayer->moveToPage(1);
            level6Btn->runAction(CCSequence::create(
                CCDelayTime::create(1.2),
                CCCallFunc::create(this, callfunc_selector(IslandSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la funci�n runParticle
                CCFadeIn::create(0.1),
                CCEaseBounceOut::create(scaleWithBounce2),
                nullptr
            ));

            Mod::get()->setSavedValue("islandlevel5complete", 1);
        }
        else
        {
            if (wlevel5->m_normalPercent == 100)
            {
                level6Btn->setVisible(true);
            }
            else
            {
                Fpoint1->setOpacity(0);
                Fpoint2->setOpacity(0);
                Fpoint3->setOpacity(0);
                Fpoint4->setOpacity(0);
                Fpoint5->setOpacity(0);
            }

        }

      
        sprite->setPosition(winSize / 2);
        sprite->setPositionY(sprite->getPositionY() - 30);

        Dashlands->setPositionX(sprite->getPositionX());
        Dashlands->setPositionY(sprite->getPositionY() + 150);
        Dashlands->setScale(0.8);



        sprite2->setPosition(winSize / 2);
        sprite2->setPositionY(sprite2->getPositionY() - 30);

        sprite3->setPosition(winSize / 2);
        sprite3->setPositionY(sprite3->getPositionY() - 30);

        ToxicFactory->setPositionX(sprite2->getPositionX());
        ToxicFactory->setPositionY(sprite2->getPositionY() + 150);
        ToxicFactory->setScale(0.8);

        ComingSoon->setPositionX(sprite3->getPositionX());
        ComingSoon->setPositionY(sprite3->getPositionY() + 150);
        ComingSoon->setScale(0.8);
      

        //start arrow animation
        auto moveUp = CCMoveBy::create(0.5f, ccp(0, 5)); 
        auto moveDown = CCMoveBy::create(0.5f, ccp(0, -5));

        auto easeOutUp = CCEaseInOut::create(moveUp,1.5f);   
        auto easeInDown = CCEaseInOut::create(moveDown, 1.5f);

        auto moveSequence = CCSequence::create(easeOutUp, easeInDown, nullptr);

        auto repeatAction = CCRepeatForever::create(moveSequence);

        //island 1 loop
        
        auto moveUp21 = CCMoveBy::create(1.0f, ccp(0, 1));
        auto moveDown21 = moveUp21->reverse();

        auto moveUp121 = CCMoveBy::create(1.0f, ccp(0, 1));
        auto moveDown121 = moveUp121->reverse();

        auto easeOutUp21 = CCEaseOut::create(moveUp21, 1.5f);
        auto easeInDown21 = CCEaseIn::create(moveDown21, 1.5f);

        auto easeOutDown21 = CCEaseOut::create(moveDown121, 1.5f);
        auto easeInUp21 = CCEaseIn::create(moveUp121, 1.5f);
        auto moveSequence21 = CCSequence::create(easeOutUp21, easeInDown21, easeOutDown21, easeInUp21, nullptr);

        auto repeatAction21 = CCRepeatForever::create(moveSequence21);
        //island 2 loop
        auto moveUp2 = CCMoveBy::create(1.0f, ccp(0, 1)); 
        auto moveDown2 = moveUp2->reverse(); 

        auto moveUp12 = CCMoveBy::create(1.0f, ccp(0, 1)); 
        auto moveDown12 = moveUp2->reverse();

        auto easeOutUp2 = CCEaseOut::create(moveUp2, 1.5f); 
        auto easeInDown2 = CCEaseIn::create(moveDown2, 1.5f); 

        auto easeOutDown2 = CCEaseOut::create(moveDown12, 1.5f); 
        auto easeInUp2 = CCEaseIn::create(moveUp12, 1.5f); 
        auto moveSequence2 = CCSequence::create(easeOutUp2, easeInDown2, easeOutDown2, easeInUp2, nullptr);

        auto repeatAction2 = CCRepeatForever::create(moveSequence2);

        node->runAction(repeatAction21);

        node2->runAction(repeatAction2);


        
        if (wlevel1->m_normalPercent != 100)
        {
            auto level1arrow = CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png");

            level1arrow->setPosition(level1Btn->getPosition());

            level1arrow->setPositionY(level1arrow->getPositionY() + 40);
            level1arrow->setRotation(-90);
            level1arrow->setScale(0.6);
            dashlandsmenu->addChild(level1arrow);
            level1arrow->runAction(repeatAction);
        }

        m_background = CCSprite::create("GJ_gradientBG.png");
        m_background->setAnchorPoint({ 0.f, 0.f });
        addChild(m_background, -4);
        
        m_background->setScaleX((winSize.width + 10.f) / m_background->getTextureRect().size.width);
        m_background->setScaleY((winSize.height + 10.f) / m_background->getTextureRect().size.height);
        m_background->setPosition(ccp(-5, -5));
        m_background->setColor(GM->colorForIdx(4));
        
        m_background->setZOrder(-4);
        sprite3->setColor(ccBLACK);
        sprite3->setOpacity(40);
        
        m_background->setColor({ 0, 125, 255 });
        CCNode* sideArt = createSideArt();
        
        addChild(sideArt);
        
        auto pageBtnsMenu = CCMenu::create();
        pageBtnsMenu->setPosition({ 0, 0 });
        pageBtnsMenu->setZOrder(2);
        
        auto nextPageIcon = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        nextPageIcon->setFlipX(false);
        
        auto nextPageBtn = CCMenuItemSpriteExtra::create(
            nextPageIcon,
            this,
            menu_selector(IslandSelectLayer::onNext)
        );
        nextPageBtn->setPosition({ winSize.width * 0.95f, winSize.height * 0.5f });
    
        auto prevPageIcon = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        prevPageIcon->setFlipX(true);
        
        auto prevPageBtn = CCMenuItemSpriteExtra::create(
            prevPageIcon,
            this,
            menu_selector(IslandSelectLayer::onPrev)
        );
        prevPageBtn->setPosition({ winSize.width * 0.05f, winSize.height * 0.5f });
    
        pageBtnsMenu->addChild(nextPageBtn);
        pageBtnsMenu->addChild(prevPageBtn);
    
        this->addChild(pageBtnsMenu);

        if (level2complete == 1) {
            level2->setVisible(false);
        }
        if (level3complete == 1) {
            level3->setVisible(false);
        }
        if (level4complete == 1) {
            level4->setVisible(false);
        }
        if (level5complete == 1) {
            level5->setVisible(false);
        }
        if (level6complete == 1) {
            level6->setVisible(false);
        }
        if (level7complete == 1) {
            level7->setVisible(false);
        }
        if (level8complete == 1) {
            level8->setVisible(false);
        }
        if (level9complete == 1) {
            level9->setVisible(false);
        }
        if (level10complete == 1) {
            level10->setVisible(false);
        }
    
        return true;
}

void IslandSelectLayer::runParticle()
{
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto particles = CCParticleSystemQuad::create("coinPickupEffect.plist", 1);

    auto levelunlocked = Mod::get()->getSavedValue<int>("wlevelunlocked");

    auto extendedLayer = (ExtendedLayer*)m_scrollLayer->getChildren()->objectAtIndex(0);

    auto levelsnode1 = (more::IslandNode*)extendedLayer->getChildren()->objectAtIndex(0);

    auto levelsmenu1 = (CCMenu*)levelsnode1->getChildren()->objectAtIndex(2);


    auto levelsnode2 = (more::IslandNode*)extendedLayer->getChildren()->objectAtIndex(1);

    auto levelsmenu2 = (CCMenu*)levelsnode2->getChildren()->objectAtIndex(2);

   /* particles->setPosition({ ((winSize.width / 2) - 118) + 100, 136 });*/
    particles->setAnchorPoint({ 0.5f, 0.5f });
    particles->setScale(0.5f);
    particles->setZOrder(3);

  
    auto circlewave = CCCircleWave::create(16.0, 30, 0.3, 0,1);
    circlewave->setAnchorPoint({ 0.5f, 0.5f });
    circlewave->setScale(0.5f);
    circlewave->setZOrder(3);

    auto circlewave2 = CCCircleWave::create(16, 80, 0.3, 1, 1);
    circlewave2->setAnchorPoint({ 0.5f, 0.5f });
    circlewave2->setScale(0.5f);
    circlewave->setZOrder(3);
    if (levelunlocked == 1) {
        particles->setPosition({ -80, -30 });
    }

    if (levelunlocked == 2) {
        particles->setPosition({ -10, 10 });
    }
    if (levelunlocked == 3) {
        particles->setPosition({ 50, -25 });
    }
    if (levelunlocked == 4) {
        particles->setPosition({ 155, -10 });
    }
    if (levelunlocked == 5) {
        particles->setPosition({ -175, -12 });
    }
    if (levelunlocked == 6) {
        particles->setPosition({ -73, -28 });
    }
    if (levelunlocked == 7) {
        particles->setPosition({ -10, 15 });
    }
    if (levelunlocked == 8) {
        particles->setPosition({ 80, -38 });
    }
    if (levelunlocked == 9) {
        particles->setPosition({ 170, -10 });
    }

    particles->init();

    if (levelunlocked >= 1 && levelunlocked <= 4) {
        levelsmenu1->addChild(particles, 2);
   
    }
    else if (levelunlocked >= 5 && levelunlocked <= 9) {
        levelsmenu2->addChild(particles, 2);
    }
    particles->addChild(circlewave, 2);
    particles->addChild(circlewave2, 2);
}

CCNode* IslandSelectLayer::createSideArt() {
    CCNode* sideArt = CCNode::create();

    CCDirector* director = CCDirector::sharedDirector();
    const float screenLeft = director->getScreenLeft();
    const float screenRight = director->getScreenRight();
    const float screenBottom = director->getScreenBottom();

    CCSprite* left = CCSprite::createWithSpriteFrameName(
        "GJ_sideArt_001.png"
    );
    left->setAnchorPoint({ 0.0f, 0.0f });
    left->setPosition({ screenLeft - 1.0f, screenBottom - 1.0f });
    sideArt->addChild(left);

    CCSprite* right = CCSprite::createWithSpriteFrameName(
        "GJ_sideArt_001.png"
    );
    right->setAnchorPoint({ 1.0f, 0.0f });
    right->setPosition({ screenRight + 1.0f, screenBottom - 1.0f });
    right->setFlipX(true);
    sideArt->addChild(right);

    return sideArt;
}

void IslandSelectLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void IslandSelectLayer::onIslandLevel(CCObject* sender) {

    CCMenuItemSpriteExtra* button = typeinfo_cast<CCMenuItemSpriteExtra*>(sender);
    auto GLM = GameLevelManager::sharedState();
    auto levelName = "";
    switch(button->getTag()) {
        case 30:
            levelName = "The Factory";
            break;
        case 31:
            levelName = "The Woods";
            break;
        case 32:
            levelName = "The Complex";
            break;
        case 33:
            levelName = "The Storage";
            break;
        case 34:
            levelName = "The Ship";
            break;
        // case 35:
        //     levelName = "IslandLevel6";
        //     break;
        // case 36:
        //     levelName = "IslandLevel7";
        //     break;
        // case 37:
        //     levelName = "IslandLevel8";
        //     break;
        // case 38:
        //     levelName = "IslandLevel9";
        //     break;
        // case 39:
        //     levelName = "IslandLevel10";
        //     break;
        default:
            levelName = "";
            break;
    }
    IslandLevel::create(levelName, level, button)->show();

}

void IslandSelectLayer::onPlay(CCObject* sender) {
	auto currentScene = CCDirector::sharedDirector()->getRunningScene();

    CCMenuItemSpriteExtra* button = (CCMenuItemSpriteExtra*)sender;
    button->setEnabled(false);
    auto GLM = GameLevelManager::sharedState();
    auto playLayer = PlayLayer::scene(level, false, false);
    FMODAudioEngine::sharedEngine()->playEffect("playSound_01.ogg");

    CCDirector::get()->pushScene(CCTransitionFade::create(0.5f, playLayer));
}



cocos2d::ccColor3B IslandSelectLayer::colorForPage(int page) {
    auto GM = GameManager::sharedState();
    int colIDs[9] = { 6 ,17, 4, 9, 3, 11, 1, 3, 4 };

    return GM->colorForIdx(colIDs[page % 5]);
}

cocos2d::ccColor3B IslandSelectLayer::getColorValue(int level, int level2, float a3) {
    float mod = (a3 * (2.f / 3)) - 0.2f;
    if (mod < 1.0f)
    {
        if (mod <= 0.0f)
            mod = 0.0f;
    }
    else
        mod = 1.0f;

    ccColor3B col1 = colorForPage(level);
    ccColor3B col2 = colorForPage(level2);

    ccColor3B col3 = {
    static_cast<GLubyte>((col2.r * mod) + col1.r * (1.0f - mod)),
    static_cast<GLubyte>((col2.g * mod) + col1.g * (1.0f - mod)),
    static_cast<GLubyte>((col2.b * mod) + col1.b * (1.0f - mod))
    };
    return col3;
}

void IslandSelectLayer::scrollLayerMoved(CCPoint point) {
    const int pageCount = 3; 
    const float threshold = 0.7f; 

    float x = -point.x / this->m_fWindowWidth;
    while (x < 0.0f) {
        x += pageCount;
    }

    int ix = std::floor(x);

   
    float offset = x - ix;

    int firstPage = ix % pageCount;

    int lmao = firstPage + 1;
    int secondPage = lmao % pageCount;

    m_level = firstPage;

    if (std::abs(offset) > threshold) {

        ccColor3B color = getColorValue(firstPage, secondPage - 1, 12);
        m_background->setColor(color);



        ccColor3B Color1 = color;
        Color1.r = color.r * 0.8;
        Color1.g = color.g * 0.8;
        Color1.b = color.b * 0.8;

        ccColor3B Color2 = color;
        Color2.r = color.r * 0.9;
        Color2.g = color.g * 0.9;
        Color2.b = color.b * 0.9;


    }
}

void IslandSelectLayer::createStars(GJGameLevel* level, CCLayer* layer) {
    int totalstars = level->m_stars;
    float screenWidth = CCDirector::sharedDirector()->getWinSize().width;
    auto BG = (CCScale9Sprite*)layer->getChildren()->objectAtIndex(0);
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();

    std::string starspr = "";

    if (level->m_normalPercent == 100)
    {
        starspr = "GJ_starsIcon_001.png";
    }
    else
    {
        starspr = "GJ_starsIcon_gray_001.png";
    }



    float starWidth = 0;
    float spaceBetweenStars = 35.0f;


    float totalWidth = totalstars * (starWidth * 0.65) + (totalstars - 1) * spaceBetweenStars;

  
    float startX = BG->getPositionX() - totalWidth / 2;

   
    float startY = (BG->getPositionY()) - 113;

   
    float currentX = startX;


    for (int i = 0; i < totalstars; ++i) {
        auto star = CCSprite::createWithSpriteFrameName(starspr.c_str());

        star->setPosition({ currentX, startY });
        star->setScale(0.65);

        layer->addChild(star);

        currentX += (starWidth * 0.65) + spaceBetweenStars;
    }
}

void IslandSelectLayer::onClose(CCObject*) {
    keyBackClicked();
}

void IslandSelectLayer::updatePageWithObject(CCObject* page, CCObject* object) {
    if (!page || !object) {
        return;
    }

    GJGameLevel* level = static_cast<GJGameLevel*>(object);
  
    LevelPage* levelPage = typeinfo_cast<LevelPage*>(page);

    if (!levelPage) {
        return;
    }

    levelPage->updateDynamicPage(level);

}


void IslandSelectLayer::onNext(CCObject*) {
    m_scrollLayer->quickUpdate();
    m_scrollLayer->moveToPage(m_level + 1);
}

void IslandSelectLayer::onPrev(CCObject*) {
    m_scrollLayer->quickUpdate();
    m_scrollLayer->moveToPage(m_level - 1);
}

void sLOLwshow2(GJGameLevel* level212) {
    if (level212 == nullptr) return;

    if (level212->m_levelID == -1) {
        FLAlertLayer::create(nullptr, "It's a secret...", "<cr>Roses are red</c>\n<cl>Violets are blue</c>\n<cg>Welcome to</c>\n<cy>2.2</c>", "OK", nullptr, 360)->show();
        return;
    }

    if (level212->m_levelID == -2) {
        FLAlertLayer::create(nullptr, "The Tower", "The path leads to an <cr>old tower</c>. It's been left alone for <cg>years</c>, with little reason to <co>explore</c>.", "OK", nullptr, 360)->show();
        return;
    }

    if (level212->m_levelID != -1 && level212->m_levelID != -2) {
        std::string name = level212->m_levelName;
        std::string contentStream =
            "<cy>" + name + "</c>" +
            "\n<cg>Total Attempts</c>: " + std::to_string(level212->m_attempts) +
            "\n<cl>Total Jumps</c>: " + std::to_string(level212->m_jumps) +
            "\n<cp>Normal</c>: " + std::to_string(level212->m_normalPercent) + "%" +
            "\n<co>Practice</c>: " + std::to_string(level212->m_practicePercent) + "%";

        FLAlertLayer::create(nullptr, "Level Stats", contentStream, "OK", nullptr, 360)->show();
        return;
    }
}

void IslandSelectLayer::onInfo(CCObject* sender) {
    auto lol = Mod::get()->getSavedValue<int>("islandpopuptag");
    auto GLM = GameLevelManager::sharedState();

    auto level21 = GJGameLevel::create();
    int levellol = 0;
    if (lol == 30)
    {
        level21 = GLM->getMainLevel(2001, true);
    }

    if (lol == 31)
    {
        level21 = GLM->getMainLevel(2002, true);
    }

    if (lol == 32)
    {
        level21 = GLM->getMainLevel(2003, true);
    }

    if (lol == 33)
    {
        level21 = GLM->getMainLevel(2004, true);
    }
    if (lol == 34)
    {
        level21 = GLM->getMainLevel(2005, true);
    }
    if (lol == 35)
    {
        level21 = GLM->getMainLevel(2006, true);
    }
    if (lol == 36)
    {
        level21 = GLM->getMainLevel(2007, true);
    }
    if (lol == 37)
    {
        level21 = GLM->getMainLevel(2008, true);
    }
    if (lol == 38)
    {
        level21 = GLM->getMainLevel(2009, true);
    }
    if (lol == 39)
    {
        level21 = GLM->getMainLevel(2010, true);
    }

    sLOLwshow2(level21);
}