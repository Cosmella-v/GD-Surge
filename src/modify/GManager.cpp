#include <Surge/modify/GManager.hpp>

using namespace geode::prelude;

void MyGManager::setup() {

    auto compare = std::string(m_fileName);

    compare.insert(std::string_view(compare).find(".dat"), "Surge");

    m_fileName = compare;
    GManager::setup();
}