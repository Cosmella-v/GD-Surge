#include <Surge/modify/GameManager.hpp>

using namespace geode::prelude;

/*UnlockType MyGameManager::convertIconTypeToUnlockType(IconType iconType) {
    switch (iconType) {
        case IconType::Cube:         return UnlockType::Cube;
        case IconType::Ship:         return UnlockType::Ship;
        case IconType::Ball:         return UnlockType::Ball;
        case IconType::Robot:        return UnlockType::Robot;
        case IconType::Spider:       return UnlockType::Spider;
        case IconType::Swing:        return UnlockType::Swing;
        case IconType::Jetpack:      return UnlockType::Jetpack;
        case IconType::DeathEffect:  return UnlockType::Death;
        case IconType::Special:      return UnlockType::GJItem;
        case IconType::Item:         return UnlockType::GJItem;
        case IconType::ShipFire:     return UnlockType::ShipFire;
        case IconType::Ufo:          return UnlockType::Bird;
        case IconType::Wave:         return UnlockType::Dart;

        default:
            return UnlockType::Cube;
    }
}*/

bool MyGameManager::isIconUnlocked(int _id, IconType _type) {
    if (_id <= 0) return false;

    switch(_type) {
        case IconType::Cube:
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
        // case IconType::DeathEffect:
        //     if (_id <= 20) {
        //         return true;
        //     } else {
        //         return GameManager::isIconUnlocked(_id, _type);
        //     }
        // case IconType::ShipFire:
        //     if (_id <= 6) {
        //         return true;
        //     } else {
        //         return GameManager::isIconUnlocked(_id, _type);
        //     }
        // case IconType::Special:
        //     if (_id <= 7) {
        //         return true;
        //     } else {
        //         return GameManager::isIconUnlocked(_id, _type);
        //     }
        default:
            return GameManager::isIconUnlocked(_id, _type);
    }

    return GameManager::isIconUnlocked(_id, _type);
}

bool MyGameManager::isColorUnlocked(int _id, UnlockType _type) {
    if (_id == 0 || _id > 8) return true;
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
            return 104;
        case IconType::Robot:
            return 71;
        case IconType::Spider:
            return 70;
        case IconType::Swing:
            return 47;
        case IconType::Jetpack:
            return 8;
        // case IconType::Special:
        //     return 7;
        // case IconType::DeathEffect:
        //     return 20;
        // case IconType::ShipFire:
        //     return 6;
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