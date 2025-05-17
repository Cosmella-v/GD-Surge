#include <Surge/modify/MusicDownloadManager.hpp>

using namespace geode::prelude;

gd::string MusicDownloadManager::pathForSFXFolder(int sfxID) {
    std::filesystem::path saveDir = Mod::get()->getSaveDir();
    std::string path = (saveDir / "sfx").string();
    log::debug("sfx path: {}", path);
    return gd::string(path);
}

gd::string MusicDownloadManager::pathForSongFolder(int songID) {
    std::filesystem::path saveDir = Mod::get()->getSaveDir();
    std::string path = (saveDir / "songs").string();
    log::debug("song path: {}", path);
    return gd::string(path);
}
