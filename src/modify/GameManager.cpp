#include <Surge/modify/GameManager.hpp>

using namespace geode::prelude;

UnlockType MyGameManager::convertIconTypeToUnlockType(IconType iconType) {
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
}

bool MyGameManager::isIconUnlocked(int _id, IconType _type) {
    if (_id <= 0) return false;

    UnlockType unlockType = convertIconTypeToUnlockType(_type);
    
    if (AchievementManager::sharedState()->achievementForUnlock(_id, unlockType).empty()) {
        return true;
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
        return 514;
    case IconType::Ship:
        return 177;
    case IconType::Ball:
        return 126;
    case IconType::Ufo:
        return 154;
    case IconType::Wave:
        return 100;
    case IconType::Robot:
        return 68;
    case IconType::Spider:
        return 69;
    case IconType::Swing:
        return 47;
    case IconType::Jetpack:
        return 9;
    case IconType::Special:
        return 7;
    case IconType::DeathEffect:
        return 20;
    case IconType::ShipFire:
        return 6;
    case IconType::Item:
        return 21;
    default:
        return GameManager::countForType(icon);
    }
}