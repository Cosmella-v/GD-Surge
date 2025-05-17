#include <Surge/modify/PlayLayer.hpp>

void MyPlayLayer::levelComplete() {
    auto levelID = this->m_level->m_levelID;

    if (levelID == 1001 && !m_isPracticeMode) {
        GameManager::sharedState()->reportAchievementWithID("geometry.ach.surge.vault03", 100, false);
    }

    PlayLayer::levelComplete();
}