#include "SongsLayer.hpp"

void MySongsLayer::customSetup() {
    CCArray* songObjectArray = CCArray::create();
    songObjectArray->addObject(SongObject::create(0));
    songObjectArray->addObject(SongObject::create(1));
    songObjectArray->addObject(SongObject::create(2));
    songObjectArray->addObject(SongObject::create(3));
    songObjectArray->addObject(SongObject::create(4));
    songObjectArray->addObject(SongObject::create(5));
    // songObjectArray->addObject(SongObject::create(6));
    // songObjectArray->addObject(SongObject::create(7));
    // songObjectArray->addObject(SongObject::create(8));
    // songObjectArray->addObject(SongObject::create(9));
    songObjectArray->addObject(SongObject::create(-1));

    m_listLayer->m_listView = CustomListView::create(songObjectArray, nullptr, 220.0, 356.0, 0, BoomListType::Song, 0.0);
    m_listLayer->addChild(m_listLayer->m_listView);
}