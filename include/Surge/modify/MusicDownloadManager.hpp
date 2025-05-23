#include <Geode/Geode.hpp>
#include <Geode/modify/MusicDownloadManager.hpp>

using namespace geode::prelude;

class $modify(MyMusicDownloadManager, MusicDownloadManager) {
	gd::string pathForSFXFolder(int sfxID);
	gd::string pathForSongFolder(int songID);
};