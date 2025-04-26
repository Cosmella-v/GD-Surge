#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>

class $modify(MyLoadingLayer, LoadingLayer) {
    $override
    bool init(bool fromReload);
};