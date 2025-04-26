#include <Geode/Geode.hpp>
#include <Geode/modify/SongsLayer.hpp>

using namespace geode::prelude;

class $modify(MySongsLayer, SongsLayer) {
	void customSetup();
};