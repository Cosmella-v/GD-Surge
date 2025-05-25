#include <Surge/modify/MusicDownloadManager.hpp>

using namespace geode::prelude;

gd::string MyMusicDownloadManager::pathForSFXFolder(int sfxID) {
    // std::filesystem::path saveDir = Mod::get()->getSaveDir();
    // std::string path = (saveDir / "sfx/").string();
    // log::debug("sfx path: {}", path);
    // return gd::string(path);
    return fmt::format("s{}.ogg"_spr, sfxID);
}

gd::string MyMusicDownloadManager::pathForSongFolder(int songID) {
    // std::filesystem::path saveDir = Mod::get()->getSaveDir();
    // std::string path = (saveDir / "songs/").string();
    // log::debug("song path: {}", path);
    // return gd::string(path);
    return fmt::format("{}.mp3"_spr, songID);
}
