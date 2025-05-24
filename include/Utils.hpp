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
