#include "GameManager.hpp"

using namespace geode::prelude;

// gd::string MyGameManager::sheetNameForIcon(int iconID, int iconType) {
//     if(iconType == 5) {
//         if(iconID == 2) {
//         return "robot_02"_spr;
//         }
//         if(iconID == 3) {
//         return "robot_03"_spr;
//         }
//     }
//     auto ret = GameManager::sheetNameForIcon(iconID, iconType);
//     return ret;
// }

CCTexture2D* MyGameManager::loadIcon(int iconID, int iconType, int _idk) {
    if(iconID == 2) {
        if(iconType == 1 || iconType == 2 || iconType == 3 || iconType == 7 || iconType == 8) {
            return nullptr;
        }
    }
    //if(iconType == 5) {
    //    if(iconID == 2 || iconID == 3) {
    //        return nullptr;
    //    }
    //}

    if(iconType == 0) {
        if(iconID < 31 && iconID > 12) {
            return nullptr;
        }
    }
    return GameManager::loadIcon(iconID, iconType, _idk);
}

void MyGameManager::dataLoaded(DS_Dictionary* dict) {
    GameManager::dataLoaded(dict);
}