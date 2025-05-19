// #include <Surge/modify/CCAnimatedSprite.hpp>

// using namespace geode::prelude;

// bool MyCCAnimatedSprite::initWithType(const char* type, CCTexture2D* texture, bool p2) {
//     if (!texture) {
//         CCDictionary* definition = typeinfo_cast<CCDictionary*>(ObjectManager::instance()->getDefinition(type));
//         CCRect rect{0.0f, 0.0f, 0.0f, 0.0f};

//         auto spriteSheet = definition->valueForKey("spriteSheet");
//         std::string spriteSheetPath = spriteSheet->getCString();
//         spriteSheetPath += ".png";

//         CCTextureCache::sharedTextureCache()->addImage(spriteSheetPath.c_str(), 0);
//     }

//     if (CCSprite::initWithTexture(texture, {0.0f, 0.0f, 0.0f, 0.0f})) {
//         this->m_bDontDraw = true;
//         this->m_unkString1 = "";
//         this->loadType(type, texture, p2);
//         return true;
//     }
  
//     return false;
// }