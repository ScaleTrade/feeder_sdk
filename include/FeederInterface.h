//
// Created by  ScaleTrade on 02.03.2026.
//
#pragma once
#include "string"
#include <rapidjson/document.h>
#include "Structures.h"

inline int FEEDER_VERSION_API = 128;

struct StateFeeder {
    time_t   last_tick= 0;
    time_t   last_ping= 0;
    int      state = 0;
};

class FeederInterface {
public:
    virtual ~FeederInterface() = default;
    virtual int getApiVersion() const { return FEEDER_VERSION_API; }
    virtual std::string feeder_name() const { return "Demo feeder"; };
    virtual std::string feeder_description() const { return "Demo feeder"; }
    virtual int CustomAction(rapidjson::Value& req, rapidjson::Value& res, rapidjson::Document::AllocatorType& allocator) { return RET_OK_NONE; }
    virtual int GetState(StateFeeder *state) { return RET_OK_NONE; }
};
