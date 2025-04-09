#include "SecretLayer.hpp"

using namespace geode::prelude;

void MySecretLayer::onSubmit(CCObject* sender) {
    std::string input = m_searchInput->getString();
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    auto gm = GameManager::sharedState();
    
    if (input == "badland") {
        m_messageLabel->setString("Do I look like the Wraith?");
		gm->reportAchievementWithID("geometry.ach.surge.vault01", 100, false);
    }        
}