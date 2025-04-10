#include <Geode/Geode.hpp>
#include "WorldSelectLayerR.hpp"

using namespace geode::prelude;

#if !defined(GEODE_IS_ANDROID) && !defined(GEODE_IS_IOS)

void WorldSelectLayerR::animateInActiveIsland() {
    auto activeNode = *(long**)(this + 0x1c8);
    if (activeNode != nullptr) {
        int pageIndex = (**(code**)(*activeNode + 0x40))(activeNode);
        goToPage(pageIndex - 1, false);

        // Create and run actions
        auto delayAction = cocos2d::CCDelayTime::create(1.0);
        auto unlockAction = cocos2d::CCCallFunc::create(*(CCCallFunc**)(this + 0x1c8), (CCObject*)GJWorldNode::unlockActiveItem);
        auto sequenceAction = cocos2d::CCSequence::create(delayAction, unlockAction, nullptr);
        cocos2d::CCNode::runAction((CCNode*)this, sequenceAction);

        // Unblock buttons after delay
        auto unblockAction = cocos2d::CCCallFunc::create((CCCallFunc*)this, (CCObject*)unblockButtons);
        auto unblockSequence = cocos2d::CCSequence::create(delayAction, unblockAction, nullptr);
        cocos2d::CCNode::runAction((CCNode*)this, unblockSequence);
    }
}

ulong WorldSelectLayerR::colorForPage(int page) {
    switch (page) {
        case 0:
            return 0xff7d19;
        case 1:
            return 0xff1996;
        default:
            return 0x969696;
    }
}

CCLayer* WorldSelectLayerR::create(int param_1) {
    auto layer = new(std::nothrow) WorldSelectLayerR(param_1);
    if (layer && layer->init(param_1)) {
        layer->autorelease();
        return layer;
    }

    // Clean up if initialization failed
    if (layer) {
        layer->release();
    }
    return nullptr;
}

ulong WorldSelectLayerR::getColorValue(int page1, int page2, float mixFactor) {
    // Clamp mixFactor to the range [0.0, 1.0]
    mixFactor = std::clamp(mixFactor / 0.6666667f - 0.2f, 0.0f, 1.0f);

    uint color1 = colorForPage(page1);
    uint color2 = colorForPage(page2);

    float complement = 1.0f - mixFactor;
    float r = NEON_fmadd(static_cast<float>(color1 & 0xff), complement, mixFactor * static_cast<float>(color2 & 0xff));
    float g = NEON_fmadd(static_cast<float>((color1 >> 8) & 0xff), complement, mixFactor * static_cast<float>((color2 >> 8) & 0xff));
    float b = NEON_fmadd(static_cast<float>((color1 >> 16) & 0xff), complement, mixFactor * static_cast<float>((color2 >> 16) & 0xff));

    return (ulong)CONCAT12(static_cast<char>(static_cast<int>(b)),
        CONCAT11(static_cast<char>(static_cast<int>(g)),
        static_cast<char>(static_cast<int>(r))));
}

void WorldSelectLayerR::goToPage(int page, bool animated) {
    int totalPages = BoomScrollLayer::getTotalPages(*(BoomScrollLayer**)(this + 0x1a8));
    if (page >= 0 && page < totalPages) {
        BoomScrollLayer::quickUpdate(*(BoomScrollLayer**)(this + 0x1a8));
        
        if (animated) {
            BoomScrollLayer::instantMoveToPage(*(BoomScrollLayer**)(this + 0x1a8), page);
        } else {
            BoomScrollLayer::moveToPage(*(BoomScrollLayer**)(this + 0x1a8), page);
        }

        updateArrows();
    }
}

void __thiscall WorldSelectLayerR::init(WorldSelectLayerR *this, int param_1) {
    char cVar1, cVar2, cVar3;
    int iVar4;
    CCTextureCache *this_00;
    CCSpriteFrameCache *this_01;
    long *plVar5;
    CCNode *pCVar6;
    CCMenuItemSpriteExtra *pCVar7;
    CCDirector *pCVar8;
    CCSprite *pCVar9;
    CCPoint *pCVar10;
    undefined8 uVar11;
    char *pcVar12;
    CCFiniteTimeAction *pCVar13;
    CCAction *pCVar14;
    GameStatsManager *this_02;
    GameManager *this_03;
    long lVar15;
    code *pcVar16;
    float fVar17, fVar18;
    undefined1 local_28, local_27, local_26;
    float local_20, local_1c;
    CCPoint aCStack_18[8], local_10;
    undefined1 local_f, local_e;
    long local_8;

    local_8 = ___stack_chk_guard;
    cVar1 = cocos2d::CCLayer::init((CCLayer *)this);
    
    if (cVar1 != '\0') {
        // Load textures and sprites
        this_00 = (CCTextureCache *)cocos2d::CCTextureCache::sharedTextureCache();
        cocos2d::CCTextureCache::addImage(this_00, "WorldSheet.png", false);
        
        this_01 = (CCSpriteFrameCache *)cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
        cocos2d::CCSpriteFrameCache::addSpriteFramesWithFile(this_01, "WorldSheet.plist");

        // Call some custom functions
        (**(code **)(*(long *)this + 0x420))(this, 1);
        (**(code **)(*(long *)this + 0x430))(this, 1);
        
        // Set up background sprite
        cocos2d::CCDirector::sharedDirector();
        cocos2d::CCDirector::getWinSize();
        plVar5 = (long *)cocos2d::CCSprite::create("GJ_gradientBG.png");
        *(long **)(this + 0x1a0) = plVar5;
        pcVar16 = *(code **)(*plVar5 + 0x118);
        cocos2d::CCPoint::CCPoint(&local_10, 0.0, 0.0);
        (*pcVar16)(plVar5, &local_10);
        
        // Additional sprite adjustments
        (**(code **)(*(long *)this + 0x1c0))(this, *(undefined8 *)(this + 0x1a0), 0xfffffffe);
        plVar5 = *(long **)(this + 0x1a0);
        (**(code **)(*plVar5 + 0x80))((local_20 + 10.0) / *(float *)(plVar5 + 0x36), plVar5);
        plVar5 = *(long **)(this + 0x1a0);
        (**(code **)(*plVar5 + 0x90))((local_1c + 10.0) / *(float *)((long)plVar5 + 0x1b4), plVar5);

        // Set position for sprites and other elements
        plVar5 = *(long **)(this + 0x1a0);
        pcVar16 = *(code **)(*plVar5 + 0xb8);
        cocos2d::CCPoint::CCPoint(&local_10, -5.0, -5.0);
        (*pcVar16)(plVar5, &local_10);
        local_10 = (CCPoint)0x33;
        local_f = 0x33;
        local_e = 0x33;
        (**(code **)(**(long **)(this + 0x1a0) + 0x3b0))(*(long **)(this + 0x1a0), &local_10);
        
        // Create menu and set positions
        plVar5 = (long *)cocos2d::CCMenu::create();
        (**(code **)(*(long *)this + 0x1c0))(this, plVar5, 2);
        pcVar16 = *(code **)(*plVar5 + 0xb8);
        cocos2d::CCPoint::CCPoint(&local_10, local_20 - 40.0, local_1c - 25.0);
        (*pcVar16)(plVar5, &local_10);
        
        // Create and customize button
        pCVar6 = (CCNode *)cocos2d::CCSprite::createWithSpriteFrameName("garageRope_001.png");
        pCVar7 = (CCMenuItemSpriteExtra *)CCMenuItemSpriteExtra::create(pCVar6, (CCNode *)0x0, (CCObject *)this, onGarage);
        CCMenuItemSpriteExtra::setSizeMult(pCVar7, 1.2);
        CCMenuItemSpriteExtra::useAnimationType(pCVar7, 1);
        cocos2d::CCPoint::CCPoint(&local_10, 0.0, -8.0);
        cocos2d::CCPoint::operator=((CCPoint *)(pCVar7 + 0x1b4), &local_10);
        
        // Handle sprite for the menu button
        pcVar16 = *(code **)(*plVar5 + 0x1b8);
        *(undefined4 *)(pCVar7 + 0x1bc) = 0x3e4ccccd;
        *(undefined4 *)(pCVar7 + 0x1c0) = 0x3e4ccccd;
        (*pcVar16)(plVar5, pCVar7);
        
        // Additional sprite setup and menu button for the side art
        local_28 = 0xff;
        local_27 = 0xff;
        local_26 = 0xff;
        plVar5 = (long *)cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
        pcVar16 = *(code **)(*plVar5 + 0x118);
        cocos2d::CCPoint::CCPoint(&local_10, 0.0, 0.0);
        (*pcVar16)(plVar5, &local_10);
        pcVar16 = *(code **)(*plVar5 + 0xb8);
        
        pCVar8 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
        fVar17 = (float)cocos2d::CCDirector::getScreenLeft(pCVar8);
        fVar18 = (float)cocos2d::CCDirector::getScreenBottom(pCVar8);
        cocos2d::CCPoint::CCPoint(&local_10, fVar17 - 1.0, fVar18 - 1.0);
        (*pcVar16)(plVar5, &local_10);
        (**(code **)(*(long *)this + 0x1c0))(this, plVar5, 1);
        (**(code **)(*plVar5 + 0x3b0))(plVar5, &local_28);
        
        // More sprite setup for right side
        pCVar9 = (CCSprite *)cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
        pcVar16 = *(code **)(*(long *)pCVar9 + 0x118);
        cocos2d::CCPoint::CCPoint(&local_10, 1.0, 0.0);
        (*pcVar16)(pCVar9, &local_10);
        pcVar16 = *(code **)(*(long *)pCVar9 + 0xb8);
        
        pCVar8 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
        fVar17 = (float)cocos2d::CCDirector::getScreenRight(pCVar8);
        fVar18 = (float)cocos2d::CCDirector::getScreenBottom(pCVar8);
        cocos2d::CCPoint::CCPoint(&local_10, fVar17 + 1.0, fVar18 - 1.0);
        (*pcVar16)(pCVar9, &local_10);
        cocos2d::CCSprite::setFlipX(pCVar9, true);
        (**(code **)(*(long *)this + 0x1c0))(this, pCVar9, 1);
        (**(code **)(*(long *)pCVar9 + 0x3b0))(pCVar9, &local_28);

        // Create and position the menu for navigation buttons
        pCVar10 = (CCPoint *)cocos2d::CCMenu::create();
        (**(code **)(*(long *)this + 0x1c0))(this, pCVar10, 5);
        
        // Handle controller connection for navigation button
        cVar2 = PlatformToolbox::isControllerConnected();
        if (cVar2 == '\0') {
            pCVar9 = (CCSprite *)cocos2d::CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
            (**(code **)(*(long *)pCVar9 + 0xa0))(0x3f19999a);
            cocos2d::CCSprite::setFlipX(pCVar9, true);
        } else {
            pCVar9 = (CCSprite *)cocos2d::CCSprite::createWithSpriteFrameName("controllerBtn_DPad_Left_001.png");
            (**(code **)(*(long *)pCVar9 + 0xa0))(0x3f19999a);
        }

        // Create and configure the previous navigation button
        uVar11 = CCMenuItemSpriteExtra::create((CCNode *)pCVar9, (CCNode *)0x0, (CCObject *)this, onPrev);
        lVar15 = *(long *)pCVar10;
        *(undefined8 *)(this + 0x1b0) = uVar11;
        (**(code **)(lVar15 + 0x1b8))(pCVar10, uVar11);
        CCMenuItemSpriteExtra::setSizeMult(*(CCMenuItemSpriteExtra **)(this + 0x1b0), 2.0);
        plVar5 = *(long **)(this + 0x1b0);
        pcVar16 = *(code **)(*plVar5 + 0xb8);
        pCVar8 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
        fVar17 = (float)cocos2d::CCDirector::getWinSizeWidth(pCVar8);
        cocos2d::CCPoint::CCPoint(&local_10, fVar17 - 60.0, fVar18 + 15.0);
        (*pcVar16)(plVar5, &local_10);
        (**(code **)(*(long *)this + 0x1c0))(this, pCVar10, 0);
    }
    // Return based on stack checking
    if (local_8 != ___stack_chk_guard) {
        __stack_chk_fail();
    }
}

void WorldSelectLayerR::onPrev(CCObject *param_1) {
    if (param_1[0x1d0] != (CCObject)0x0) {
        return;
    }
    goToPage((WorldSelectLayerR *)param_1, *(int *)(*(long *)(param_1 + 0x1a8) + 0x244) - 1, false);
}

long* WorldSelectLayerR::scene(int param_1) {
    long *plVar1;
    long lVar2;
    undefined8 uVar3;

    plVar1 = (long *)cocos2d::CCScene::create();
    lVar2 = AppDelegate::get();
    *(long **)(lVar2 + 0x18) = plVar1;
    uVar3 = create(param_1);
    (**(code **)(*plVar1 + 0x1b8))(plVar1, uVar3);
    return plVar1;
}

void __thiscall WorldSelectLayerR::scrollLayerMoved(WorldSelectLayerR *this, float *param_2) {
    int iVar1, iVar2;
    undefined3 uVar3;
    float fVar4;
    float local_10[2];
    long local_8;

    fVar4 = *param_2;
    local_8 = ___stack_chk_guard;
    cocos2d::CCDirector::sharedDirector();
    cocos2d::CCDirector::getWinSize();

    // Adjust fVar4 based on local_10[0]
    for (fVar4 = -fVar4 / local_10[0]; fVar4 < 0.0; fVar4 += 23.0);

    iVar2 = (int)fVar4 % 0x17;
    iVar1 = iVar2 + 1;
    if (iVar1 == 0x17) {
        iVar1 = 0;
    }

    uVar3 = getColorValue(this, iVar2, iVar1, fVar4 - (float)(int)fVar4);
    local_10[0] = (float)CONCAT13(local_10[0]._3_1_, uVar3);
    (**(code **)(**(long **)(this + 0x1a0) + 0x3b0))(*(long **)(this + 0x1a0), local_10);

    if (local_8 != ___stack_chk_guard) {
        __stack_chk_fail();
    }
}

void __thiscall WorldSelectLayerR::scrollLayerMoved(WorldSelectLayerR *this) {
    scrollLayerMoved(this - 0x198);
}

void WorldSelectLayerR::scrollLayerScrolledToPage(BoomScrollLayer *param_1, int param_2) {
    int iVar1, iVar2;
    bool bVar3;
    BoomScrollLayer *this;
    code *pcVar4;
    long *plVar5;

    if (*(long *)(param_1 + 0x1a8) == 0) {
        bVar3 = false;
    } else {
        bVar3 = *(int *)(*(long *)(param_1 + 0x1a8) + 0x244) > 0;
    }

    (**(code **)(**(long **)(param_1 + 0x1b0) + 0x148))(*(long **)(param_1 + 0x1b0), bVar3);
    plVar5 = *(long **)(param_1 + 0x1b8);
    this = *(BoomScrollLayer **)(param_1 + 0x1a8);
    pcVar4 = *(code **)(*plVar5 + 0x148);

    if (this != nullptr) {
        iVar1 = *(int *)(this + 0x244);
        iVar2 = BoomScrollLayer::getTotalPages(this);
        (*pcVar4)(plVar5, iVar1 < iVar2 - 1);
        return;
    }

    (*pcVar4)(plVar5, 0);
}

void __thiscall WorldSelectLayerR::scrollLayerScrolledToPage(WorldSelectLayerR *this, BoomScrollLayer *param_1, int param_2) {
    scrollLayerScrolledToPage((BoomScrollLayer *)(this - 0x198), (int)param_1);
}

void WorldSelectLayerR::scrollLayerWillScrollToPage(BoomScrollLayer *param_1, int param_2) {
    int iVar1, iVar2;
    bool bVar3;
    BoomScrollLayer *this;
    code *pcVar4;
    long *plVar5;

    if (*(long *)(param_1 + 0x1a8) == 0) {
        bVar3 = false;
    } else {
        bVar3 = *(int *)(*(long *)(param_1 + 0x1a8) + 0x244) > 0;
    }

    (**(code **)(**(long **)(param_1 + 0x1b0) + 0x148))(*(long **)(param_1 + 0x1b0), bVar3);
    plVar5 = *(long **)(param_1 + 0x1b8);
    this = *(BoomScrollLayer **)(param_1 + 0x1a8);
    pcVar4 = *(code **)(*plVar5 + 0x148);

    if (this != nullptr) {
        iVar1 = *(int *)(this + 0x244);
        iVar2 = BoomScrollLayer::getTotalPages(this);
        (*pcVar4)(plVar5, iVar1 < iVar2 - 1);
        return;
    }

    (*pcVar4)(plVar5, 0);
}

void __thiscall WorldSelectLayerR::scrollLayerWillScrollToPage(WorldSelectLayerR *this, BoomScrollLayer *param_1, int param_2) {
    scrollLayerWillScrollToPage((BoomScrollLayer *)(this - 0x198), (int)param_1);
}

void __thiscall WorldSelectLayerR::setupWorlds(WorldSelectLayerR *this) {
    CCArray *worldArray; // Array to hold world layers
    CCObject *layerObject;
    CCNode *worldNode;
    CCActionInterval *moveAction1, *moveAction2;
    CCFiniteTimeAction *easeAction1, *easeAction2;
    CCAction *repeatAction;
    CCString *worldLabelString;
    char *labelCString;
    long *spriteObject;
    long *menuItem;
    BoomScrollLayer *scrollLayer;
    uint worldIndex = 1;
    float xPos, yPos;
    CCPoint moveBy[8];
    CCPoint offset[8];
    long stackGuard = ___stack_chk_guard;

    // Get screen size and create world array
    cocos2d::CCDirector::sharedDirector();
    cocos2d::CCDirector::getWinSize();
    worldArray = (CCArray *)cocos2d::CCArray::create();

    // Set up initial position
    xPos = local_28 * 0.5f;
    yPos = NEON_fmadd(local_24, 0x3f000000, 0xc1700000) + 2.0f - 5.0f;
    cocos2d::CCPoint::CCPoint(moveBy, xPos, yPos);

    // Loop through each world
    do {
        // Create a new layer for the world
        layerObject = (CCObject *)cocos2d::CCLayer::create();
        worldNode = (CCNode *)GJWorldNode::create(worldIndex, this);

        // Add the world node to the layer
        (**(code **)(*(long *)layerObject + 0x1b8))(layerObject, worldNode);
        (**(code **)(*(long *)worldNode + 0x48))(worldNode, worldIndex);

        if (worldIndex == 2) {
            // Special handling for world 2 (e.g., positioning adjustment)
            cocos2d::CCPoint::CCPoint(offset, 0.0f, -10.0f);
            cocos2d::CCPoint::operator+(moveBy, offset);
            (*(*(code **)(*(long *)worldNode + 0xb8)))(worldNode, moveBy);
        }

        // Set up animations for each world
        cocos2d::CCPoint::CCPoint(offset, 0.0f, -4.0f);
        moveAction1 = (CCActionInterval *)cocos2d::CCMoveBy::create(2.0f, offset);
        easeAction1 = (CCFiniteTimeAction *)cocos2d::CCEaseInOut::create(moveAction1, 1.8f);
        cocos2d::CCPoint::CCPoint(offset, 0.0f, 4.0f);
        moveAction2 = (CCActionInterval *)cocos2d::CCMoveBy::create(2.0f, offset);
        easeAction2 = (CCFiniteTimeAction *)cocos2d::CCEaseInOut::create(moveAction2, 1.8f);
        CCSequence *sequenceAction = (CCActionInterval *)cocos2d::CCSequence::create(easeAction1, easeAction2, nullptr);
        repeatAction = (CCAction *)cocos2d::CCRepeatForever::create(sequenceAction);
        cocos2d::CCNode::runAction(worldNode, repeatAction);
        (**(code **)(*(long *)repeatAction + 0x68))(0x3f000000, repeatAction);

        // Set world label sprite
        worldLabelString = (CCString *)cocos2d::CCString::createWithFormat("worldLabel_%02d_001.png", (ulong)worldIndex);
        labelCString = (char *)cocos2d::CCString::getCString(worldLabelString);
        spriteObject = (long *)cocos2d::CCSprite::createWithSpriteFrameName(labelCString);
        (**(code **)(*(long *)layerObject + 0x1b8))(layerObject, spriteObject);
        cocos2d::CCPoint::CCPoint(offset, 0.0f, 142.0f);
        cocos2d::CCPoint::operator+(moveBy, offset);
        (*(*(code **)(*spriteObject + 0xb8)))(spriteObject, moveBy);

        if (*(long *)(worldNode + 0x148) != 0) {
            // If there is a condition to break early for certain worlds
            goto skipLabelSetup;
        }

        // Additional logic for handling "Coming Soon" label
        if (worldIndex == 3) {
            spriteObject = (long *)cocos2d::CCLabelBMFont::create("Coming Soon", "bigFont.fnt");
            (**(code **)(*(long *)layerObject + 0x1b8))(layerObject, spriteObject);
            (**(code **)(*spriteObject + 0xa0))(0x3f4ccccd, spriteObject);
            cocos2d::CCPoint::CCPoint(offset, 0.0f, 142.0f);
            cocos2d::CCPoint::operator+(moveBy, offset);
            (*(*(code **)(*spriteObject + 0xb8)))(spriteObject, moveBy);

            // Create a button for free levels
            CCNode *freeLevelsButtonSprite = (CCNode *)cocos2d::CCSprite::createWithSpriteFrameName("GJ_freeLevelsBtn_001.png");
            CCMenuItem *freeLevelsButton = (CCMenuItem *)CCMenuItemSpriteExtra::create(freeLevelsButtonSprite, nullptr, (CCObject *)this, onFreeLevels);
            menuItem = (long *)cocos2d::CCMenu::createWithItem(freeLevelsButton);
            (**(code **)(*(long *)layerObject + 0x1b8))(layerObject, menuItem);
            cocos2d::CCPoint::CCPoint(offset, local_28 * 0.5f, fVar14);
            (*(*(code **)(*menuItem + 0xb8)))(menuItem, moveBy);
        }

    skipLabelSetup:
        // Set the world node for the layer
        *(CCNode **)(this + 0x1c8) = worldNode;
        worldIndex++;
    } while (worldIndex != 4);

    // Create scroll layer
    long scrollLayerInstance = BoomScrollLayer::create(worldArray, 0, false, nullptr, nullptr);
    *(long *)(this + 0x1a8) = scrollLayerInstance;
    *(WorldSelectLayerR **)(*(long *)(scrollLayerInstance + 0x1f0) + 0x198) = this + 0x198;
    *(WorldSelectLayerR **)(*(long *)(this + 0x1a8) + 0x218) = this + 0x198;
    (**(code **)(*(long *)this + 0x1b8))(this, *(undefined8 *)(this + 0x1a8));

    // Set the position of the page indicator
    scrollLayer = *(BoomScrollLayer **)(this + 0x1a8);
    CCDirector *director = (CCDirector *)cocos2d::CCDirector::sharedDirector();
    float screenBottom = (float)cocos2d::CCDirector::getScreenBottom(director);
    cocos2d::CCPoint::CCPoint(moveBy, local_28 * 0.5f, screenBottom + 15.0f);
    BoomScrollLayer::setPagesIndicatorPosition(scrollLayer, moveBy);

    if (stackGuard != ___stack_chk_guard) {
        // Stack protection failure, terminate
        __stack_chk_fail();
    }
}

void __thiscall WorldSelectLayerR::showCompleteDialog(WorldSelectLayerR *this) {
    int iVar1;
    char cVar2;
    bool bVar3;
    GameManager *this_00;
    CCArray *this_01;
    CCObject *pCVar4;
    DialogLayer *this_02;
    int *piVar5;
    undefined1 auStack_30[8];
    undefined1 auStack_28[16];
    long local_18;
    long local_10;
    long local_8;

    local_8 = ___stack_chk_guard;
    this[0x1d0] = (WorldSelectLayerR)0x0;
    this_00 = (GameManager *)GameManager::sharedState();
    GameManager::setUGV(this_00, "18", true);
    
    this_01 = (CCArray *)cocos2d::CCArray::create();
    FUN_00dea7dc(&local_18, "The Keymaster", auStack_30);

    FUN_00dea7dc(&local_10,
        "Well, well, well...<d020> I see you have <cg>completed</c> the <cl>first two</c> islands.", auStack_28);

    pCVar4 = (CCObject *)DialogObject::create(0x3f800000, &local_18, &local_10, 2, 0, 0xffffff);
    cocos2d::CCArray::addObject(this_01, pCVar4);

    if ((undefined8 *)(local_10 + -0x18) != &DAT_0131a5b0) {
        piVar5 = (int *)(local_10 + -8);
        do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5, 0x10);
            if (bVar3) {
                *piVar5 = iVar1 - 1;
                cVar2 = ExclusiveMonitorsStatus();
            }
        } while (cVar2 != '\0');

        if (iVar1 < 1) {
            operator.delete((undefined8 *)(local_10 + -0x18));
        }
    }

    if ((undefined8 *)(local_18 + -0x18) != &DAT_0131a5b0) {
        piVar5 = (int *)(local_18 + -8);
        do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5, 0x10);
            if (bVar3) {
                *piVar5 = iVar1 - 1;
                cVar2 = ExclusiveMonitorsStatus();
            }
        } while (cVar2 != '\0');

        if (iVar1 < 1) {
            operator.delete((undefined8 *)(local_18 + -0x18));
        }
    }

    FUN_00dea7dc(&local_18, "The Keymaster", auStack_30);

    FUN_00dea7dc(&local_10,
        "Not bad,<d030> not bad at all.\n<d030>I have <co>unlocked</c> <cg>online levels</c> for you.", auStack_28);

    pCVar4 = (CCObject *)DialogObject::create(0x3f59999a, &local_18, &local_10, 2, 0, 0xffffff);
    cocos2d::CCArray::addObject(this_01, pCVar4);

    if ((undefined8 *)(local_10 + -0x18) != &DAT_0131a5b0) {
        piVar5 = (int *)(local_10 + -8);
        do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5, 0x10);
            if (bVar3) {
                *piVar5 = iVar1 - 1;
                cVar2 = ExclusiveMonitorsStatus();
            }
        } while (cVar2 != '\0');

        if (iVar1 < 1) {
            operator.delete((undefined8 *)(local_10 + -0x18));
        }
    }

    if ((undefined8 *)(local_18 + -0x18) != &DAT_0131a5b0) {
        piVar5 = (int *)(local_18 + -8);
        do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5, 0x10);
            if (bVar3) {
                *piVar5 = iVar1 - 1;
                cVar2 = ExclusiveMonitorsStatus();
            }
        } while (cVar2 != '\0');

        if (iVar1 < 1) {
            operator.delete((undefined8 *)(local_18 + -0x18));
        }
    }

    FUN_00dea7dc(&local_18, "The Keymaster", auStack_30);

    FUN_00dea7dc(&local_10, "<cl>Let's see what more you can do<d010>.<d010>.<d010>.</c>", auStack_28);

    pCVar4 = (CCObject *)DialogObject::create(0x3f800000, &local_18, &local_10, 2, 0, 0xffffff);
    cocos2d::CCArray::addObject(this_01, pCVar4);

    if ((undefined8 *)(local_10 + -0x18) != &DAT_0131a5b0) {
        piVar5 = (int *)(local_10 + -8);
        do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5, 0x10);
            if (bVar3) {
                *piVar5 = iVar1 - 1;
                cVar2 = ExclusiveMonitorsStatus();
            }
        } while (cVar2 != '\0');

        if (iVar1 < 1) {
            operator.delete((undefined8 *)(local_10 + -0x18));
        }
    }

    if ((undefined8 *)(local_18 + -0x18) != &DAT_0131a5b0) {
        piVar5 = (int *)(local_18 + -8);
        do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5, 0x10);
            if (bVar3) {
                *piVar5 = iVar1 - 1;
                cVar2 = ExclusiveMonitorsStatus();
            }
        } while (cVar2 != '\0');

        if (iVar1 < 1) {
            operator.delete((undefined8 *)(local_18 + -0x18));
        }
    }

    this_02 = (DialogLayer *)DialogLayer::createWithObjects(this_01, 2);
    (**(code **)(*(long *)this + 0x1c0))(this, this_02, 100);
    DialogLayer::updateChatPlacement(this_02, 0);
    DialogLayer::animateInRandomSide(this_02);

    if (local_8 != ___stack_chk_guard) {
        __stack_chk_fail();
    }
    return;
}

void WorldSelectLayerR::tryShowAd(void) {
    int iVar1;

    iVar1 = GameManager::sharedState();
    GameManager::tryShowInterstitial(iVar1, 0x78, 0x8c);
    return;
}

void __thiscall WorldSelectLayerR::unblockButtons(WorldSelectLayerR *this) {
    this[0x1d0] = (WorldSelectLayerR)0x0;
    (**(code **)(**(long **)(this + 0x1a8) + 0x3d8))(*(long **)(this + 0x1a8), 1);
    return;
}

void __thiscall WorldSelectLayerR::updateArrows(WorldSelectLayerR *this) {
    int iVar1;
    int iVar2;
    bool bVar3;
    BoomScrollLayer *this_00;
    code *pcVar4;
    long *plVar5;

    if (*(long *)(this + 0x1a8) == 0) {
        bVar3 = false;
    } else {
        bVar3 = 0 < *(int *)(*(long *)(this + 0x1a8) + 0x244);
    }

    (**(code **)(**(long **)(this + 0x1b0) + 0x148))(*(long **)(this + 0x1b0), bVar3);

    plVar5 = *(long **)(this + 0x1b8);
    this_00 = *(BoomScrollLayer **)(this + 0x1a8);
    pcVar4 = *(code **)(*plVar5 + 0x148);

    if (this_00 != (BoomScrollLayer *)0x0) {
        iVar1 = *(int *)(this_00 + 0x244);
        iVar2 = BoomScrollLayer::getTotalPages(this_00);
        (*pcVar4)(plVar5, iVar1 < iVar2 + -1);
        return;
    }

    (*pcVar4)(plVar5, 0);
    return;
}

void __thiscall WorldSelectLayerR::~WorldSelectLayerR(WorldSelectLayerR *this) {
    *(undefined ***)this = &PTR_copyWithZone_0128ae10;
    *(undefined ***)(this + 0x140) = &PTR_~WorldSelectLayerR_0128b2a8;
    *(undefined **)(this + 0x148) = &DAT_0128b318;
    *(undefined ***)(this + 0x150) = &PTR_keyBackClicked_0128b330;
    *(undefined ***)(this + 0x158) = &PTR_keyDown_0128b350;
    *(undefined ***)(this + 0x160) = &PTR_rightKeyDown_0128b370;
    *(undefined ***)(this + 0x198) = &PTR_scrollLayerScrollingStarted_0128b398;

    cocos2d::CCLayer::~CCLayer((CCLayer *)this);

    return;
}

#endif