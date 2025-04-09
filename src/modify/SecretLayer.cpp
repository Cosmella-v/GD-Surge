#include "SecretLayer.hpp"

using namespace geode::prelude;

void MySecretLayer::onSubmit(CCObject* sender) {
    std::string input = m_searchInput->getString();
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    auto gm = GameManager::sharedState();

    static int lastIndex = -1;

    std::vector<std::string> messages = {
        "What are you poking around for?",
        "Don't you have better things to do?",
        "There is no spoo",
        "I should have hid this room better...",
        "You're not supposed to be in here...",
        "RubRub won't like this...",
        "Don't touch that",
        "Why U touch my stuff?",
        "RubRub better not find you in here...",
        "Can't you just leave?",
        "This is not the room you are looking for...",
        "Sneaky sneaky...",
        "It's my precious...",
        "You shall not pass!",
        "Don't push the button!",
        "You're gonna get me in trouble...",
        "This is getting ridiculus...",
        "Go collect some stars",
        "Maybe there are new levels?",
        "Just, stop bothering me",
        "I'm gonna stop talking",
        "You're hopeless...",
        "Really, still here?",
        "Fine, press the button",
        "How did you get in here?!"
    };

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int index;
    do {
        index = std::rand() % messages.size();
    } while (index == lastIndex && messages.size() > 1); // Ensure different message

    lastIndex = index;

    m_messageLabel->setString(messages[index].c_str());
    m_messageLabel->setColor({ 255, 255, 255 });

    if (input == "badland" && !(AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault01"))) {
        m_messageLabel->setString("Do I look like the Wraith?");
        gm->reportAchievementWithID("geometry.ach.surge.vault01", 100, false);
        m_messageLabel->setColor({ 0, 255, 0 });
    }        
}
