#include <Surge/modify/LevelPage.hpp>

void MyLevelPage::onInfo(CCObject* sender) {
    if(m_level->m_levelID.value() == -1) {
        return FLAlertLayer::create(nullptr, "It's a secret...", "<cl>Something</c> lies beneath the <cg>surface</c>... a <co>fracture</c> waiting to <cj>happen</c>.", "OK", nullptr, 360)->show();
    }
    LevelPage::onInfo(sender);
}