// #include <Surge/modify/AnimatedShopKeeper.hpp>

// using namespace geode::prelude;

// // bool MyAnimatedShopKeeper::init(ShopType shop) {
// //     if (!AnimatedShopKeeper::init(ShopType{5}))
// //         return AnimatedShopKeeper::init(shop);

// //     if (CCAnimatedSprite::initWithType("GDSShopKeeper"_spr, nullptr, false)) {
// //         this->m_idleInt2 = ((rand() * 4.6566e-10) * 5.0) + 10.0;
// //         this->m_idleInt1 = ((rand() * 4.6566e-10) * 2.0) + 1.0;
// //         this->m_animationManager->stopAnimations();
// //         return true;
// //     }

// //     return true;
// // }

// bool AnimatedShopKeeper::init(ShopType type) {
//     this->m_type = type;
//     const char *typeStr;
//     switch (type) {
//         case 1:
//             typeStr = "GJShopKeeper2";
//             break;
//         case 2:
//             typeStr = "GJShopKeeper3";
//             break;
//         case 3:
//             typeStr = "GJShopKeeper4";
//             break;
//         case 4:
//             typeStr = "GJShopKeeper5";
//             break;
//         case 5:
//             typeStr = "GDSShopKeeper"_spr;
//             break;
//         default:
//             typeStr = "GJShopKeeper";
//             break;
//     }
//     if (CCAnimatedSprite::initWithType(typeStr, nullptr, false)) {
//         this->m_idleInt2 = ((rand() * 4.6566e-10) * 5.0) + 10.0;
//         this->m_idleInt1 = ((rand() * 4.6566e-10) * 2.0) + 1.0;
//         this->m_animationManager->stopAnimations();
//         return true;
//     }
//     return false;
// }