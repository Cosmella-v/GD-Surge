#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    auto musicPath = Mod::get()->getResourcesDir() / "music.zip";
    auto unzip = geode::utils::file::Unzip::create(musicPath);
    if (unzip.isErr()) {
        FLAlertLayer::create(
            "Error",
            "Failed to unzip music files.",
            "OK"
        )->show();
        return;
    }

    auto& archive = unzip.unwrap();
    auto success = archive.extractAllTo(Mod::get()->getSaveDir());
    if (!success.isOk()) {
        FLAlertLayer::create(
            "Error",
            "Failed to unzip music files.",
            "OK"
        )->show();
        return;
    }
}
