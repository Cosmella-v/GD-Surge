#include "SecretLayer.hpp"
#include <ctime>
#include <algorithm>

using namespace geode::prelude;

// Static member definitions
int MySecretLayer::lastIndex = -1;
int normalMessages = 0;
bool isRiddle = false;
MySecretLayer::VaultCode* selectedRiddle = nullptr;

std::vector<std::string> MySecretLayer::messages = {
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
    "How did you get in here?!",
    "I'm gonna sleep now... ZzZzZzzZzZzZzZzZzZzZz",
    "You're STILL here?!",
    "Why not just leave??",
    "Why not start counting levels?",
    "Fine, you win. You may press the button.",
    "Did RubRub send you? No? Even worse.",
    "This place is off-limits, capisce?",
    "You again? What now?",
    "Great, another button masher.",
    "Touch anything and I scream.",
    "What do you even want from me?",
    "You can't keep doing this forever.",
    "Snooping detected.",
    "This is classified nonsense, go away.",
    "RubRub secured this room for a reason!",
    "You're like a bad penny...",
    "Still haven't found the exit, huh?",
    "You must be bored out of your mind.",
    "At this point I admire your persistence.",
    "No secrets here. Go bother someone else.",
    "You want answers? Wrong vault.",
    "You're gonna trigger something bad!",
    "I'm not responsible for what happens next.",
    "Hey! My stuff!",
    "This is my space, not a public park.",
    "Maybe a spider will scare you away...",
    "I'm running out of ways to say 'go away'.",
    "This isn't a therapy session.",
    "Do I LOOK like I know anything?",
    "You're making me nervous...",
    "You're going to mess everything up!",
    "Maybe RubRub wants me to suffer...",
    "If I say the code, will you leave?",
    "I'm about to lose it, seriously.",
    "Touch that again and I\'ll bite.",
    "You're poking the wrong corner, buddy.",
    "No Easter Eggs here. Only regret.",
    "I've seen things... like YOU coming back again.",
    "Wanna hear a secret? Too bad.",
    "I told you to stop, didn\'t I?",
    "Why must you poke the void?",
    "You're opening things you shouldn't be touching.",
    "RubRub warned me about people like you.",
    "Back! Back, foul intruder!",
    "This vault is cursed. Just sayin'.",
    "You think this is a game? …oh wait.",
    "You're giving me actual anxiety.",
    "Stop it. Just stop it.",
    "The walls aren't listening, but I am.",
    "Even the icons are judging you.",
    "You're about to unlock... disappointment.",
    "If this is about the stars, I don't have them.",
    "This is why we can't have nice secret rooms.",
    "I knew hiding it behind a fake wall wasn\'t enough.",
    "Do you even know what you're looking for?",
    "Knock knock. Who\'s there? NOT YOU.",
    "404: Entry denied.",
    "This isn\'t what RubRub meant by 'exploration'.",
    "Do you feel accomplished yet?",
    "I had dreams once… then you showed up.",
    "There\'s no treasure. Just me. And you. Unfortunately.",
    "Hey look, it's you again… joy.",
    "This isn\'t a chatroom.",
    "Your curiosity is... irritating.",
    "Keep pressing and see what happens. I dare you.",
    "One more press and I walk out.",
    "I should charge rent for how often you visit.",
    "You won't find anything. Except my resentment.",
    "What if I told you this room was a fake?",
    "You're wasting your time here.",
    "Guess who doesn\'t want you here? Me.",
    "The password is... haha no.",
    "RubRub's gonna hear about this!",
    "This is a certified no-touch zone.",
    "Why do you hurt me this way?",
    "Back so soon? I was almost happy.",
    "If I rolled my eyes harder, I'd see my brain.",
    "I miss when this place was quiet.",
    "Your presence here is... statistically unfortunate.",
    "You just HAD to touch the weird-looking wall.",
    "Oh sure, come in, press things, ignore warnings.",
    "Do you even know how many rules you're breaking?",
    "You press things like you're trying to get a prize.",
    "Go away or I\'ll start rhyming.",
    "If you're trying to unlock something, try not being annoying.",
    "I swear, I had sanity before you arrived.",
    "Stop. Think. Then leave.",
    "This is the definition of trespassing.",
    "You\'ve already found all the secrets. Probably.",
    "What are you expecting, applause?",
    "No codes, no cookies, no hope.",
    "My patience level is lower than your star count.",
    "I bet you're proud of yourself, huh?",
    "Maybe if I ignore you, you'll vanish.",
    "Still pushing buttons like it's gonna change things.",
    "Ever heard of boundaries?",
    "I've been here since 2.0 and you're still annoying.",
    "I could be napping right now.",
    "There\'s nothing here but disappointment.",
    "Careful, you\'re gonna cause problems.",
    "If I had emotions, they'd be tired.",
    "Oh cool, you again. Yay.",
    "This vault is empty. Like your inbox.",
    "The more you poke, the more I question everything.",
    "Congratulations. You've unlocked... absolutely nothing."
};

std::vector<MySecretLayer::VaultCode> MySecretLayer::vaultCodes = {
    VaultCode{
        "badland",
        []() {
            auto array = CCArray::create();
            array->addObject(CCString::create("I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?"));
            array->addObject(CCString::create("I am not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, and I can drown. What am I?"));
            return array;
        },
        []() -> bool { return true; }
    },
    VaultCode{
        "i am robtop",
        []() {
            auto array = CCArray::create();
            array->addObject(CCString::create("I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?"));
            array->addObject(CCString::create("I am not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, and I can drown. What am I?"));
            return array;
        },
        []() -> bool { return true; }
    },
    VaultCode{
        "rod's basement",
        []() {
            auto array = CCArray::create();
            array->addObject(CCString::create("I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?"));
            array->addObject(CCString::create("I am not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, and I can drown. What am I?"));
            return array;
        },
        []() -> bool { return true; }
    }
};

bool MySecretLayer::init() {
    if (!SecretLayer::init()) return false;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int index;
    do {
        index = std::rand() % messages.size();
    } while (index == lastIndex && messages.size() > 1);

    lastIndex = index;

    m_messageLabel->setString(messages[index].c_str());
    m_messageLabel->setColor({ 255, 255, 255 });

    m_searchInput->setAllowedChars(" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");

    return true;
}

void MySecretLayer::onSubmit(CCObject* sender) {
    std::string input = m_searchInput->getString();
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    auto gm = GameManager::sharedState();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (normalMessages > 10) isRiddle = true;

    if (isRiddle) {
        int randomIndex = std::rand() % MySecretLayer::vaultCodes.size();
        VaultCode selectedVaultCode = MySecretLayer::vaultCodes[randomIndex];

        CCArray* riddles = selectedVaultCode.riddle();

        if (riddles && riddles->count() > 0) {
            CCString* riddleString = (CCString*)riddles->objectAtIndex(0);
            
            m_messageLabel->setString(riddleString->getCString());
            m_messageLabel->setColor({ 0, 255, 255 });
        }
    } else {
        normalMessages++;
        int index;
        do {
            index = std::rand() % messages.size();
        } while (index == lastIndex && messages.size() > 1);

        lastIndex = index;

        m_messageLabel->setString(messages[index].c_str());
        m_messageLabel->setColor({ 255, 255, 255 });
    }

    if (input == "badland" && !(AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault01"))) {
        m_messageLabel->setString("Do I look like the Wraith?");
        m_messageLabel->setColor({ 0, 255, 0 });
        gm->reportAchievementWithID("geometry.ach.surge.vault01", 100, false);
    }
    
    if (input == "i am robtop" && !(AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault02"))) {
        m_messageLabel->setString("no you're not...");
        m_messageLabel->setColor({ 0, 255, 0 });
        gm->reportAchievementWithID("geometry.ach.surge.vault02", 100, false);
    }
    if (input == "rod's basement" && !(AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault03")) && !(Mod::get()->getSavedValue<bool>("basement-unlocked"))) {
        m_messageLabel->setString("Come in...");
        m_messageLabel->setColor({ 0, 255, 0 });
        gm->reportAchievementWithID("geometry.ach.surge.vault03", 50, false);
        Mod::get()->setSavedValue("basement-unlocked", true);
    }
}
