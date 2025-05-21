#include <Surge/modify/LocalLevelManager.hpp>

using namespace geode::prelude;

gd::string MyLocalLevelManager::getMainLevelString(int id) {

    auto file = CCString::createWithFormat("level%i.txt"_spr, id);
    if(file == nullptr) return "";
    auto content = CCString::createWithContentsOfFile(file->getCString());
    if(content == nullptr) return "";

    return gd::string(content->getCString());
    return LocalLevelManager::getMainLevelString(id);
}