#include <Geode/Geode.hpp>
#include "LevelPage.hpp"

using namespace geode::prelude;

void MyLevelPage::updateDynamicPage(GJGameLevel* level) {
    LevelPage::updateDynamicPage(level);
    
    if (level->m_levelID == -3) {
        auto label = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("coming-soon-label"));
        if (label) {
            label->setString("Islands");
        }
        this->removeChildByID("button-menu");
    }
}
