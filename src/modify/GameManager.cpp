#include <Surge/modify/GameManager.hpp>
#include <Utils.hpp>

using namespace geode::prelude;

bool MyGameManager::isIconUnlocked(int _id, IconType _type) {
    if (_id <= 0) return false;

    switch(_type) {
        case IconType::Cube:
            if (_id == 483 || _id == 149 || _id == 150) return GameManager::isIconUnlocked(_id, _type);
            if (_id <= 485) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Ship:
            if (_id <= 169) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Ball:
            if (_id == 41) return GameManager::isIconUnlocked(_id, _type);
            if (_id <= 118) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Ufo:
            if (_id <= 149) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Wave:
            if (_id <= 96) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Robot:
            if (_id <= 68) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Spider:
            if (_id <= 69) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Swing:
            if (_id <= 43) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Jetpack:
            if (_id <= 8) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        default:
            return GameManager::isIconUnlocked(_id, _type);
    }

    return GameManager::isIconUnlocked(_id, _type);
}

bool MyGameManager::isColorUnlocked(int _id, UnlockType _type) {
    if (_type == UnlockType::Col2) {
        if (_id == 20 || _id == 31) return GameManager::isColorUnlocked(_id, _type);
        if (_id == 0 || _id > 8) return true;
    } else if (_type == UnlockType::Col1) {
        if (_id == 0 || _id > 9 || _id == 7) return true;
    } else {
        if (_id == 0 || _id > 8) return true;
    }
    return GameManager::isColorUnlocked(_id, _type);
}

int MyGameManager::countForType(IconType icon) {
    switch (icon) {
        case IconType::Cube:
            return 500;
        case IconType::Ship:
            return 180;
        case IconType::Ball:
            return 130;
        case IconType::Ufo:
            return 155;
        case IconType::Wave:
            return 105;
        case IconType::Robot:
            return 71;
        case IconType::Spider:
            return 70;
        case IconType::Swing:
            return 47;
        case IconType::Jetpack:
            return 8;
        default:
            return GameManager::countForType(icon);
    }
}

void MyGameManager::returnToLastScene(GJGameLevel* p0) {
    if (auto scene = GameManager::sharedState()->m_sceneEnum; scene == 9 || scene == 3) {
        GameManager::returnToLastScene(p0);
    } else {
        CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
    }
}