#include <Geode/Geode.hpp>
#include "LevelTools.hpp"

using namespace geode::prelude;

bool MyLevelTools::verifyLevelIntegrity(gd::string verifyString, int levelID) {
    return true;
}

gd::string MyLevelTools::getAudioTitle(int audioID) {
    switch(audioID) {
        case 40: return "Badland";
        case 41: return "Unstable Geometry";
        default: return "";
    }
}

gd::string MyLevelTools::getAudioFileName(int audioID) {
    switch(audioID) {
        case 40: return "Badland.mp3"_spr;
        case 41: return "UnstableGeometry.mp3"_spr;
        default: return "";
    }
}

gd::string MyLevelTools::nameForArtist(int artistID) {
    switch(artistID) {
        case 1: return "Boom Kitty";
        case 2: return "Waterflame";
        default: return "";
    }
}

gd::string MyLevelTools::urlForAudio(int audioID) {
    switch(audioID) {
        case 40: return "https://www.youtube.com/watch?v=LfgzPpmjM0M";
        case 41: return "https://www.youtube.com/watch?v=8S9ZpjyrP0A";
        default: return "";
    }
}

gd::string MyLevelTools::ngURLForArtist(int artistID) {
    switch(artistID) {
        case 1: return "https://boomkitty.newgrounds.com/";
        case 2: return "https://waterflame.newgrounds.com/";
        default: return "";
    }
}

gd::string MyLevelTools::ytURLForArtist(int artistID) {
    switch(artistID) {
        case 1: return "https://www.youtube.com/@boomkitty";
        case 2: return "https://www.youtube.com/@waterflamemusic";
        default: return "";
    }
}

gd::string MyLevelTools::fbURLForArtist(int artistID) {
    switch(artistID) {
        case 1: return "https://www.facebook.com/Waterflameworkshop/";
        default: return "";
    }
}

int MyLevelTools::artistForAudio(int audioID) {
    switch(audioID) {
        case 40: return 1;
        case 41: return 2;
        default: return 0;
    }
}

GJGameLevel* MyLevelTools::getLevel(int levelID, bool loaded) {
    GJGameLevel* level = GJGameLevel::create();

    switch(levelID) {
        case 1: 
            setLevelInfo(level, 2, GJDifficulty::Hard, 0);
            level->m_levelName = getAudioTitle(40);
            level->m_audioTrack = 40;
            level->m_coins = 3;
            break;
        case 2:
            setLevelInfo(level, 6, GJDifficulty::Harder, 0);
            level->m_levelName = getAudioTitle(41);
            level->m_audioTrack = 41;
            level->m_coins = 3;
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