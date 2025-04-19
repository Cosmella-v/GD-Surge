#include <Geode/Geode.hpp>
#include "LevelTools.hpp"

using namespace geode::prelude;

bool MyLevelTools::verifyLevelIntegrity(gd::string verifyString, int levelID) {
    return true;
}

gd::string MyLevelTools::getAudioTitle(int audioID) {
    switch(audioID) {
        case -1: return "Stay Inside Me";
        case 40: return "Badland";
        case 41: return "Unstable Geometry";
        case 42: return "Tomb";
        case 43: return "Detour";
        case 44: return "The Beginning of Time";
        case 45: return "Thermodynamix";
        default: return "";
    }
}

gd::string MyLevelTools::getAudioFileName(int audioID) {
    switch(audioID) {
        case -1: return "StayInsideMe.mp3";
        case 40: return "Badland.mp3"_spr;
        case 41: return "UnstableGeometry.mp3"_spr;
        case 42: return "Tomb.mp3"_spr;
        case 43: return "Detour.mp3"_spr;
        case 44: return "TheBeginningOfTime.mp3"_spr;
        case 45: return "Thermodynamix.mp3"_spr;
        default: return "";
    }
}

gd::string MyLevelTools::nameForArtist(int artistID) {
    switch(artistID) {
        case 1: return "Boom Kitty";
        case 2: return "Waterflame";
        case 3: return "dj-Nate";
        case 4: return "OcularNebula";
        default: return "";
    }
}

gd::string MyLevelTools::urlForAudio(int audioID) {
    switch(audioID) {
        case -1: return "https://www.youtube.com/watch?v=5Epc1Beme90";
        case 40: return "https://www.youtube.com/watch?v=LfgzPpmjM0M";
        case 41: return "https://www.youtube.com/watch?v=8S9ZpjyrP0A";
        case 42: return "https://www.youtube.com/watch?v=k02da3gk0Yg";
        case 43: return "https://www.youtube.com/watch?v=9Q6XICGoEaM";
        case 44: return "https://www.youtube.com/watch?v=-66Vk9FqgMU";
        case 45: return "https://www.youtube.com/watch?v=QUFIGUBrN3M";
        default: return "";
    }
}

gd::string MyLevelTools::ngURLForArtist(int artistID) {
    switch(artistID) {
        case 1: return "https://boomkitty.newgrounds.com/";
        case 2: return "https://waterflame.newgrounds.com/";
        case 3: return "https://dj-nate.newgrounds.com/";
        case 4: return "https://ocularnebula.newgrounds.com/";
        default: return "";
    }
}

gd::string MyLevelTools::ytURLForArtist(int artistID) {
    switch(artistID) {
        case 1: return "https://www.youtube.com/@BoomKitty";
        case 2: return "https://www.youtube.com/@WaterflameMusic";
        case 3: return "https://www.youtube.com/@dj-Nate";
        case 4: return "https://www.youtube.com/@OcularNebula";
        default: return "";
    }
}

gd::string MyLevelTools::fbURLForArtist(int artistID) {
    switch(artistID) {
        case 2: return "https://www.facebook.com/Waterflameworkshop/";
        case 3: return "https://www.facebook.com/djnateofficial/";
        default: return "";
    }
}

int MyLevelTools::artistForAudio(int audioID) {
    switch(audioID) {
        case -1: return 4;
        case 40: return 1;
        case 41: return 2;
        case 42: return 1;
        case 43: return 1;
        case 44: return 3;
        case 45: return 3;
        default: return 0;
    }
}

GJGameLevel* MyLevelTools::getLevel(int levelID, bool loaded) {
    GJGameLevel* level = GJGameLevel::create();

    switch(levelID) {
        case 1: 
            setLevelInfo(level, 4, GJDifficulty::Hard, 0);
            level->m_levelName = getAudioTitle(40);
            level->m_audioTrack = 40;
            level->m_coins = 3;
            break;
        case 2:
            setLevelInfo(level, 6, GJDifficulty::Harder, 0);
            level->m_levelName = getAudioTitle(41);
            level->m_audioTrack = 41;
            level->m_coins = 3;
            break;
        case 3:
            setLevelInfo(level, 7, GJDifficulty::Harder, 0);
            level->m_levelName = getAudioTitle(42);
            level->m_audioTrack = 42;
            level->m_coins = 3;
            break;
        case 4:
            setLevelInfo(level, 8, GJDifficulty::Insane, 0);
            level->m_levelName = getAudioTitle(43);
            level->m_audioTrack = 43;
            level->m_coins = 3;
            break;
        case 5:
            setLevelInfo(level, 5, GJDifficulty::Hard, 0);
            level->m_levelName = getAudioTitle(44);
            level->m_audioTrack = 44;
            level->m_coins = 3;
            break;
        case 6:
            setLevelInfo(level, 10, GJDifficulty::Demon, 15);
            level->m_levelName = getAudioTitle(45);
            level->m_audioTrack = 45;
            level->m_coins = 3;
            break;
    }
    if (!loaded) {
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);
    }
    level->m_levelID = levelID;
    level->m_levelType = GJLevelType::Local;
    return level;
}

void MyLevelTools::setLevelInfo(GJGameLevel* level, int stars, GJDifficulty difficulty, int coinsRequired) {
    level->m_stars = stars;
    level->m_difficulty = difficulty;
    level->m_requiredCoins = coinsRequired;
}