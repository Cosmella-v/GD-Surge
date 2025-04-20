#include "SecretLayer.hpp"
#include <ctime>
#include <algorithm>

using namespace geode::prelude;

// Static member definitions
int MySecretLayer::lastIndex = -1;

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
    "Touch that again and I'll bite.",
    "You're poking the wrong corner, buddy.",
    "No Easter Eggs here. Only regret.",
    "I've seen things... like YOU coming back again.",
    "Wanna hear a secret? Too bad.",
    "I told you to stop, didn't I?",
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
    "I knew hiding it behind a fake wall wasn't enough.",
    "Do you even know what you're looking for?",
    "Knock knock. Who's there? NOT YOU.",
    "404: Entry denied.",
    "This isn't what RubRub meant by 'exploration'.",
    "Do you feel accomplished yet?",
    "I had dreams once… then you showed up.",
    "There's no treasure. Just me. And you. Unfortunately.",
    "Hey look, it's you again… joy.",
    "This isn't a chatroom.",
    "Your curiosity is... irritating.",
    "Keep pressing and see what happens. I dare you.",
    "One more press and I walk out.",
    "I should charge rent for how often you visit.",
    "You won't find anything. Except my resentment.",
    "What if I told you this room was a fake?",
    "You're wasting your time here.",
    "Guess who doesn't want you here? Me.",
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
    "Go away or I'll start rhyming.",
    "If you're trying to unlock something, try not being annoying.",
    "I swear, I had sanity before you arrived.",
    "Stop. Think. Then leave.",
    "This is the definition of trespassing.",
    "You've already found all the secrets. Probably.",
    "What are you expecting, applause?",
    "No codes, no cookies, no hope.",
    "My patience level is lower than your star count.",
    "I bet you're proud of yourself, huh?",
    "Maybe if I ignore you, you'll vanish.",
    "Still pushing buttons like it's gonna change things.",
    "Ever heard of boundaries?",
    "I've been here since 2.0 and you're still annoying.",
    "I could be napping right now.",
    "There's nothing here but disappointment.",
    "Careful, you're gonna cause problems.",
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
            array->addObject(CCString::create("badland riddle test"));
            array->addObject(CCString::create("wtf is this"));
            return array;
        },
        []() -> bool { return !(AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault01")); },
        "Do I look like the Wraith?",
        []() {
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.surge.vault01", 100, false);
        }
    },
    VaultCode{
        "i am robtop",
        []() {
            auto array = CCArray::create();
            array->addObject(CCString::create("Still poking? Have some popcorn."));
            array->addObject(CCString::create("I'm the dev, and I'm watching."));
            array->addObject(CCString::create("Throwing popcorn, entertained."));
            array->addObject(CCString::create("Here's the code - don't mess up."));
            array->addObject(CCString::create("It's clear. Just think a bit."));
            array->addObject(CCString::create("Say my name. Escape awaits."));
            return array;
        },
        []() -> bool { return !(AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault02")); },
        "no you're not...",
        []() {
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.surge.vault02", 100, false);
        }
    },
    VaultCode{
        "rod's basement",
        []() {
            auto array = CCArray::create();
            array->addObject(CCString::create("Still snooping around, huh?"));
            array->addObject(CCString::create("There's a place below, true."));
            array->addObject(CCString::create("The name's short, simple, clue."));
            array->addObject(CCString::create("It's not that hard, think a sec."));
            array->addObject(CCString::create("Who owns the basement? Check."));
            array->addObject(CCString::create("Now, take that, slap it below,"));
            array->addObject(CCString::create("And boom, you got the code."));
            return array;
        },
        []() -> bool {
            return !(AchievementManager::sharedState()->isAchievementEarned("geometry.ach.surge.vault03"))
                && !(Mod::get()->getSavedValue<bool>("basement-unlocked"));
        },
        "Come in...",
        []() {
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.surge.vault03", 50, false);
            Mod::get()->setSavedValue("basement-unlocked", true);
        }
    }
};

std::unordered_map<std::string, int> MySecretLayer::riddleProgress;

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

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (const VaultCode& vaultCode : vaultCodes) {
        if (input == vaultCode.code && vaultCode.condition()) {
            m_messageLabel->setString(vaultCode.successText);
            m_messageLabel->setColor({ 0, 255, 0 });

            vaultCode.onSuccess();

            m_fields->isRiddle = false;
            m_fields->selectedRiddleIndex = -1;
            m_fields->currentRiddleIndex = 0;
            m_fields->normalMessages = 0;

            return;
        }
    }

    bool showedMessage = false;

    if (m_fields->normalMessages > 10)
        m_fields->isRiddle = true;

    if (m_fields->isRiddle) {
        if (m_fields->selectedRiddleIndex == -1) {
            std::vector<int> validIndices;
            for (int i = 0; i < vaultCodes.size(); ++i) {
                if (vaultCodes[i].condition()) {
                    validIndices.push_back(i);
                }
            }

            if (!validIndices.empty()) {
                int randomPick = std::rand() % validIndices.size();
                m_fields->selectedRiddleIndex = randomPick;
                m_fields->currentRiddleIndex = 0;
            } else {
                m_fields->isRiddle = false;
                m_fields->selectedRiddleIndex = -1;
                m_fields->currentRiddleIndex = 0;
            }
        }

        if (m_fields->isRiddle && m_fields->selectedRiddleIndex != -1) {
            VaultCode& selectedVaultCode = vaultCodes[m_fields->selectedRiddleIndex];
            CCArray* riddles = selectedVaultCode.riddle();

            if (riddles && riddles->count() > 0) {
                CCString* riddleString = (CCString*)riddles->objectAtIndex(m_fields->currentRiddleIndex);
                m_messageLabel->setString(riddleString->getCString());
                m_messageLabel->setColor({ 0, 255, 255 });

                m_fields->currentRiddleIndex++;

                if (m_fields->currentRiddleIndex >= riddles->count()) {
                    m_fields->isRiddle = false;
                    m_fields->normalMessages = 1;
                    m_fields->selectedRiddleIndex = -1;
                    m_fields->currentRiddleIndex = 0;
                }

                showedMessage = true;
            }
        }
    }

    if (!showedMessage) {
        m_fields->normalMessages++;
        int index;
        do {
            index = std::rand() % messages.size();
        } while (index == lastIndex && messages.size() > 1);

        lastIndex = index;

        m_messageLabel->setString(messages[index].c_str());
        m_messageLabel->setColor({ 255, 255, 255 });
    }
}
