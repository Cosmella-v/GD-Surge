#include <Surge/modify/LevelPage.hpp>

using namespace geode::prelude;

void MyLevelPage::onInfo(CCObject* sender) {
    if(m_level->m_levelID.value() == -1) {
        if (AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault04")) {
            return FLAlertLayer::create(nullptr, "It was a secret...", "<cr>You shattered</c> what was meant to endure.<d050> <cg>No silence</c> remains,<d050> only <co>ashes</c> of a hidden world.", "OK", nullptr, 360)->show();            
        } else {
            return FLAlertLayer::create(nullptr, "It's a secret...", "<cl>Something</c> lies beneath the <cg>surface</c>... a <co>fracture</c> waiting to <cj>happen</c>.", "OK", nullptr, 360)->show();
        }
    }
    LevelPage::onInfo(sender);
}

// void MyLevelPage::updateDynamicPage(GJGameLevel* level) {
//     LevelPage::updateDynamicPage(level);

//     queueInMainThread([this, level]() {
//         if (auto scene = CCDirector::sharedDirector()->getRunningScene()) {
//             if (auto layer = scene->getChildByType<LevelSelectLayer*>(0)) {
//                 if (level->m_levelID == -1) {
//                     if (auto bg = typeinfo_cast<CCSprite*>(layer->getChildByID("background"))) {
//                         bg->setColor(GameManager::sharedState()->colorForIdx(15));
//                     }
//                     if (auto ground = layer->getChildByID("ground-layer")) {
//                         ground->setVisible(false);
//                     }
//                     if (auto buttonMenu = layer->getChildByID("button-menu")) {
//                         buttonMenu->removeFromParent();
//                     }
//                 } else {
//                     if (auto ground = layer->getChildByID("ground-layer")) {
//                         ground->setVisible(true);
//                     }
//                 }
//             }
//         }
//     });
// }