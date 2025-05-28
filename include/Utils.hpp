#include <Geode/Geode.hpp>

using namespace geode::prelude;

class GDSFollowLinks {
public:
    static void onTwitch() {
        CCApplication::sharedApplication()->openURL("https://www.twitch.tv/omgrod1000");
    }

    static void onTwitter() {
        CCApplication::sharedApplication()->openURL("https://x.com/0mgrod");
    }

    static void onDiscord() {
        CCApplication::sharedApplication()->openURL("https://discord.gg/vK3DuqJwyW");
    }

    static void onFacebook() {
        FLAlertLayer::create("nope", "i'm not a boomer", "OK")->show();
    }

    static void onYouTube() {
        CCApplication::sharedApplication()->openURL("https://www.youtube.com/@OmgRodYT");
    }

    static void onReddit() {
        CCApplication::sharedApplication()->openURL("https://www.reddit.com/r/omgrod/");
    }

    static void onRobTop() {
        CCApplication::sharedApplication()->openURL("https://omgrod.me/");
    }
};

// Code by Prevter
// (currently useless tho)

/*

int getTotalOrbsForLevel(GJGameLevel* level, int levelID) {
    return GameStatsManager::get()->getBaseCurrencyForLevel(level);
}

int getCurrentOrbsForLevel(GJGameLevel* level, int levelID) {
    auto gsm = GameStatsManager::get();
    auto totalOrbs = getTotalOrbsForLevel(level, levelID);
    auto dailyId = level->m_dailyID.value();

    cocos2d::CCDictionary* currencyScores;
    if (dailyId <= 0) {
        if (level->m_levelType == GJLevelType::Local) {
            currencyScores = gsm->m_mainCurrencyScores;
        } else if (level->m_gauntletLevel) {
            currencyScores = gsm->m_gauntletCurrencyScores;
        } else {
            currencyScores = gsm->m_onlineCurrencyScores;
        }
        dailyId = levelID;
    } else {
        currencyScores = gsm->m_timelyCurrencyScores;
    }

    auto& str = currencyScores->valueForKey(fmt::to_string(dailyId))->m_sString;
    if (str.empty()) return 0;
    if (auto res = geode::utils::numFromString<int>(str)) {
        auto resValue = res.unwrap();
        if (resValue >= 100) return totalOrbs * 1.25;
        return std::floor(totalOrbs * (resValue / 100.f));
    }
    return 0;
}

*/