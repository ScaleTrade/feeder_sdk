//
// Created by  ScaleTrade on 02.03.2026.
//
#pragma once
#include "string"
#include <rapidjson/document.h>
#include "Structures.h"
#include "model/FeederState.hpp"

inline int FEEDER_VERSION_API = 128;

class FeederInterface {
public:
    virtual ~FeederInterface() = default;
    virtual int getApiVersion() const { return FEEDER_VERSION_API; }
    virtual std::string feeder_name() const { return "Demo feeder"; };
    virtual std::string feeder_description() const { return "Demo feeder"; }
    virtual int CustomAction(rapidjson::Value& req, rapidjson::Value& res, rapidjson::Document::AllocatorType& allocator) { return RET_OK_NONE; }
    virtual int GetState(FeederStateRecord *state) { return RET_OK_NONE; }
};
