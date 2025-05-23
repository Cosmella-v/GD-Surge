#include <Surge/layers/BasementLayer.hpp>
#include <Surge/layers/CreditsLayer.hpp>

void BasementLayer::keyBackClicked() {
    BasementLayer::onExit(nullptr);
}

bool BasementLayer::init() {
    if (!CCLayer::init()) return false;

    auto director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	auto bg = CCSprite::create("GJ_gradientBG.png");
	auto bgSize = bg->getTextureRect().size;
	bg->setAnchorPoint({ 0.0f, 0.0f });
	bg->setScaleX((winSize.width + 10.0f) / bgSize.width);
	bg->setScaleY((winSize.height + 10.0f) / bgSize.height);
	bg->setPosition({ -5.0f, -5.0f });
	bg->setColor({ 60, 0, 60 });
	this->addChild(bg);

	auto misc = CCMenu::create();
	this->addChild(misc);

	m_pButtonMenu = CCMenu::create();
	this->addChild(m_pButtonMenu);

	m_obNext = ccp(0.0f, 75.0f);

	auto backBtn = CCMenuItemSpriteExtra::create(
		CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
		this,
		menu_selector(BasementLayer::onExit)
	);
	backBtn->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);
	misc->addChild(backBtn);

	auto title = CCLabelBMFont::create("The Basement", "goldFont.fnt");
	title->setPosition(winSize.width / 2, winSize.height / 2 + 130.0f);
	title->setScale(1.2f);
	this->addChild(title);

	this->addButton("GJ_chatBtn_001.png", "Secret Level", menu_selector(BasementLayer::onSecretLevel));
	this->addButton("GDS_questBtn.png"_spr, "Credits", menu_selector(BasementLayer::onCredits));
	// this->addButton("GJ_reportBtn_001.png", "Comment Ban");
	// this->addButton("GJ_musicOnBtn_001.png", "Whitelist Artist");
    // this->addButton("GJ_levelLeaderboardBtn_001.png", "Unfreeze Leaderboards");

    // this->addButton(CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png"), "Secret Level");
	// this->addButton(CircleButtonSprite::create(CCSprite::create("questIcon.png"_spr), CircleBaseColor::Green, CircleBaseSize::MediumAlt), "Credits");

	m_bButtonsEntered = false;

	this->setKeypadEnabled(true);

	this->runSequentialFadeIn();

    return true;
}

BasementLayer* BasementLayer::create() {
    auto layer = new BasementLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

CCScene* BasementLayer::scene() {
    auto scene = CCScene::create();
    auto layer = BasementLayer::create();
    scene->addChild(layer);
    return scene;
}

void BasementLayer::onExit(CCObject*) {
	GameManager::sharedState()->fadeInMusic("menuLoop.mp3");
	CCDirector::sharedDirector()->popSceneWithTransition(0.5f, kPopTransitionFade);
}

void BasementLayer::addButton(const char* node, const char* text, SEL_MenuHandler callback) {
    auto winSize = CCDirector::sharedDirector()->getWinSize();

    // if (auto rgba = dynamic_cast<CCRGBAProtocol*>(node)) {
    //     rgba->setOpacity(0);
    // }

    auto btn = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName(node),
        this,
        callback
    );
    btn->setPosition(m_obNext.x - 150.0f, m_obNext.y);

    btn->setOpacity(0);

    m_pButtonMenu->addChild(btn);

    auto label = CCLabelBMFont::create(text, "bigFont.fnt");
    label->setAnchorPoint({ 0.f, 0.f });
    label->setPosition(m_obNext.x - 120.0f, m_obNext.y - 10.0f);
    label->setScale(0.7f);
    label->setOpacity(0);
    m_pButtonMenu->addChild(label);

    m_vButtonLabelPairs.push_back({ btn, label });
    m_obNext.y -= 45.0f;
}

void BasementLayer::runSequentialFadeIn() {
    float delay = 0.0f;

    for (auto& pair : m_vButtonLabelPairs) {
        auto btn = pair.first;
        auto label = pair.second;

        btn->runAction(CCSequence::create(
            CCDelayTime::create(delay),
            CCFadeTo::create(0.5f, 255),
            nullptr
        ));

        label->runAction(CCSequence::create(
            CCDelayTime::create(delay),
            CCFadeTo::create(0.5f, 255),
            nullptr
        ));

        delay += 0.5f;
    }
}

void BasementLayer::onSecretLevel(CCObject*) {
    auto level = GJGameLevel::create();
    level->m_levelID = 1001;
    level->m_levelName = "The Gauntlet";
    level->m_audioTrack = 1000;
    level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(1001);
    level->m_stars = 8;
    level->m_difficulty = GJDifficulty::Insane;
    auto scene = PlayLayer::scene(level, false, false);
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}

void BasementLayer::onCredits(CCObject*) {
    auto scene = CreditsLayer::scene();
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}