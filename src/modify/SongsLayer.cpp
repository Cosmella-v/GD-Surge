#include "SongsLayer.hpp"

void MySongsLayer::customSetup() {
    CCArray* songObjectArray = CCArray::create();
    songObjectArray->addObject(SongObject::create(40));
    songObjectArray->addObject(SongObject::create(41));
    songObjectArray->addObject(SongObject::create(42));
    songObjectArray->addObject(SongObject::create(43));
    songObjectArray->addObject(SongObject::create(44));
    songObjectArray->addObject(SongObject::create(45));
    // songObjectArray->addObject(SongObject::create(46));
    // songObjectArray->addObject(SongObject::create(47));
    // songObjectArray->addObject(SongObject::create(48));
    // songObjectArray->addObject(SongObject::create(49));
    songObjectArray->addObject(SongObject::create(-1));

    m_listLayer->m_listView = CustomListView::create(songObjectArray, nullptr, 220.0, 356.0, 0, BoomListType::Song, 0.0);
    m_listLayer->addChild(m_listLayer->m_listView);
}