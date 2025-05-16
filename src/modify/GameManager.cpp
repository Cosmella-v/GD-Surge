#include <Surge/modify/GameManager.hpp>

using namespace geode::prelude;

bool MyGameManager::isIconUnlocked(int _id, IconType _type) {
    if (_id <= 0) return false;
    if (_id <= 485) return true;
    return false;
}
bool MyGameManager::isColorUnlocked(int _id, UnlockType _type) {
    if (_id == 0) return true;
    if (_id <= 8) return false;
    return true;
}