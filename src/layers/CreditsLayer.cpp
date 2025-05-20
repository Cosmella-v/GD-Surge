#include <Surge/layers/CreditsLayer.hpp>

void CreditsLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
    FMODAudioEngine::sharedEngine()->playMusic("secretLoop.mp3", true, 0.1f, 0);
}

bool CreditsLayer::init() {
    if (!CCLayer::init()) return false;

    setKeypadEnabled(true);

    auto musicPath = (Mod::get()->getSaveDir() / "songs" / "CreditsTheme.ogg").string();
    log::debug("Trying to play: {}", musicPath);
	FMODAudioEngine::sharedEngine()->playMusic(musicPath, false, 0.1f, 0);

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto menu = CCMenu::create();
    menu->setPosition({ 0.f, 0.f });
    menu->setAnchorPoint({ 0.f, 0.f });
    this->addChild(menu);

    auto background = CCSprite::create("GJ_gradientBG.png");
    background->setColor(ccc3(0, 102, 255));
    background->setScaleX(winSize.width / background->getContentSize().width);
    background->setScaleY(winSize.height / background->getContentSize().height);
    background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    background->setID("background");
    this->addChild(background, -1);

    auto backButton = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(CreditsLayer::backWrapper)
    );
    backButton->setPosition({ 25, winSize.height - 25 });
    menu->addChild(backButton);

    auto containerNode = CCNode::create();
    containerNode->setPosition({ 0.f, 0.f - winSize.height });
    this->addChild(containerNode);

    auto gdLogo = CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
    gdLogo->setPosition({ winSize.width / 2, winSize.height * 0.8f });
    containerNode->addChild(gdLogo);

    auto surgeLogo = CCSprite::createWithSpriteFrameName("surgeLogo_001.png"_spr);
    CCRect logoBounds = gdLogo->boundingBox();
    surgeLogo->setAnchorPoint({1.0f, 1.0f});
    surgeLogo->setPosition(ccp(logoBounds.getMaxX() - 2.f, logoBounds.getMinY() - 1.5f));
    containerNode->addChild(surgeLogo);

    std::vector<std::string> lines = {
        "Development Team", "OmgRod",
        "Art Design", "OmgRod", "Alphalaneous",
        "Icons", "MobMasterMind",
        "Levels", "Badland by OmgRod", "Unstable Geometry by OmgRod", "Tomb by OmgRod", "Detour by ____", "Beginning of Time by flingus", "Thermodynamix by OmgRod",
        "Songs", "Badland by Boom Kitty", "Unstable Geometry by Waterflame", "Tomb by Boom Kitty", "Detour by Boom Kitty", "The Beginning of Time by dj-Nate", "Thermodynamix by dj-Nate\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",
        "Special thanks to RobTop for creating Geometry Dash!"
    };

    std::unordered_set<std::string> titles = {
        "Development Team", "Art Design", "Icons", "Levels", "Songs"
    };

    float labelY = winSize.height * 0.5f;

    for (size_t i = 0; i < lines.size(); ++i) {
        const auto& line = lines[i];
        bool isTitle = titles.count(line);
        bool nextIsTitle = (i + 1 < lines.size()) && titles.count(lines[i + 1]);

        auto label = CCLabelBMFont::create(line.c_str(), "bigFont.fnt");
        label->setAnchorPoint({ 0.5f, 1.f });
        label->setAlignment(CCTextAlignment::kCCTextAlignmentCenter);
        label->setPosition({ winSize.width / 2.f, labelY });

        if (!isTitle) {
            label->setScale(0.5f);
        }

        containerNode->addChild(label);

        float spacing = 5.f;
        if (isTitle) {
            spacing = label->getContentSize().height + 16.0f;
        } else {
            spacing = label->getContentSize().height * 0.5f + 4.0f;
            if (nextIsTitle) {
                spacing += 10.0f;
            }
        }

        labelY -= spacing;
    }

    float totalHeight = 0.f;

    for (size_t i = 0; i < lines.size(); ++i) {
        const auto& line = lines[i];
        bool isTitle = titles.count(line);
        bool nextIsTitle = (i + 1 < lines.size()) && titles.count(lines[i + 1]);

        float scale = isTitle ? 1.f : 0.5f;

        auto tempLabel = CCLabelBMFont::create(line.c_str(), "bigFont.fnt");
        float labelHeight = tempLabel->getContentSize().height * scale;
        float spacing = isTitle ? (labelHeight + 16.0f) : (labelHeight + 4.0f);
        if (!isTitle && nextIsTitle)
            spacing += 10.0f;

        totalHeight += spacing;
    }

    auto moveAction = CCMoveTo::create(100.f, { 0.f, winSize.height + totalHeight });
    containerNode->runAction(moveAction);

    return true;
}

CreditsLayer* CreditsLayer::create() {
    auto layer = new CreditsLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

CCScene* CreditsLayer::scene() {
    auto scene = CCScene::create();
    auto layer = CreditsLayer::create();
    scene->addChild(layer);
    return scene;
}

void CreditsLayer::backWrapper(CCObject* sender) {
    keyBackClicked();
}