#include <Surge/modify/GameManager.hpp>
#include <Utils.hpp>

using namespace geode::prelude;

bool MyGameManager::isIconUnlocked(int _id, IconType _type) {
    if (_id <= 0) return false;

    switch(_type) {
        case IconType::Cube:
            if (_id == 483 || _id == 149 || _id == 150 || _id == 19 || _id == 31 || _id == 32 || _id == 371 || _id == 365 || _id == 341 || _id == 407 || _id == 65) return GameManager::isIconUnlocked(_id, _type);
            if (_id <= 485) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Ship:
            if (_id == 161 || _id == 65) return GameManager::isIconUnlocked(_id, _type);
            if (_id <= 169) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Ball:
            if (_id == 2 || _id == 13 || _id == 117 || _id == 46 || _id == 41) return GameManager::isIconUnlocked(_id, _type);
            if (_id <= 118) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Ufo:
            if (_id == 3 || _id == 5) return GameManager::isIconUnlocked(_id, _type);
            if (_id <= 149) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Wave:
            if (_id == 93 || _id == 45 || _id == 3) return GameManager::isIconUnlocked(_id, _type);
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
            if (_id == 32 || _id == 9) return GameManager::isIconUnlocked(_id, _type);
            if (_id <= 43) {
                return true;
            } else {
                return GameManager::isIconUnlocked(_id, _type);
            }
        case IconType::Jetpack:
            // if (_id <= 8) {
            //     return true;
            // } else {
            //     return GameManager::isIconUnlocked(_id, _type);
            // }
            return true;
        default:
            return true;
    }

    return GameManager::isIconUnlocked(_id, _type);
}

bool MyGameManager::isColorUnlocked(int _id, UnlockType _type) {
    if (_type == UnlockType::Col2) {
        if (_id == 16 || _id == 5 || _id == 11 || _id == 12 || _id == 6 || _id == 7 || _id == 14 || _id == 17 || _id == 20 || _id == 31 || _id == 18 || _id == 19 || _id == 27 || _id == 21) return GameManager::isColorUnlocked(_id, _type);
        return true;
    } else if (_type == UnlockType::Col1) {
        if (_id == 15 || _id == 56 || _id == 96 || _id == 71) return GameManager::isColorUnlocked(_id, _type);
        return true;
    } else {
        return true;
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
            return 125;
        case IconType::Ufo:
            return 155;
        case IconType::Wave:
            return 105;
        case IconType::Robot:
            return 68;
        case IconType::Spider:
            return 75;
        case IconType::Swing:
            return 50;
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