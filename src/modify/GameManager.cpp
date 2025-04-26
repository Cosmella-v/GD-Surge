#include <Surge/modify/GameManager.hpp>

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

void MyGameManager::unloadIcon(int request) {
    
}

void MyGameManager::dataLoaded(DS_Dictionary* dict) {
    GameManager::dataLoaded(dict);
}