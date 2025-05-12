#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    auto music = (const char*)((Mod::get()->getResourcesDir() / "music.zip").u8string().c_str());
    auto unzip = geode::utils::file::Unzip::create(music);
    if (unzip.isErr()) {
        return;
    }

    unzip.unwrap().extractAllTo(Mod::get()->getSaveDir());
}