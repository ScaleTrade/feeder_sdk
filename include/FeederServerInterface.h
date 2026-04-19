//
// Created by  ScaleTrade on 11.03.2025.
//
#pragma once
#include <ctime>
#include <rapidjson/document.h>
#include <string>
#include <vector>

#include "Structures.h"
#include "model/FeederCandle.hpp"

class Core;

inline int FEEDER_SERVER_API = 101;

class FeederServerInterface {

public:
    FeederServerInterface(Core* st, const std::string name, int index);
    ~FeederServerInterface();

    virtual int TickSet(TickInfo& tick); //set quotes tick
    virtual int LogsOut(const std::string& type, const std::string& message);  //send logs to console
    static int GetApiVersion() { return FEEDER_SERVER_API; }

   //+------------------------------------------------------------------+
    // Chart
    //+------------------------------------------------------------------+
    virtual int GetCandles(const std::string& symbol, const std::string& frame, time_t from, time_t to, std::vector<FeederCandleRecord>* candles);
    virtual int SetCandles(const std::string& symbol, const std::vector<FeederCandleRecord>& candles);
    virtual int DeleteCandlesAll(const std::string& symbol);
    virtual int DeleteCandlesPeriod(const std::string& symbol, time_t from, time_t to);
    virtual int ImportCandleStores(const std::vector<FeederCandleRecord>& candles, int flush_data,const std::string& symbol);

    //+------------------------------------------------------------------+
    // Stream
    //+------------------------------------------------------------------+
    virtual int SendToManager(int manager_id, const rapidjson::Value& data); //send data to some Manager
    virtual int BroadcastToManagers(const rapidjson::Value& data); //send data to all Managers
    virtual int BroadcastNotifyToManagers(const rapidjson::Value& data); //send data to all Managers

private:
    Core* St;
    std::string feeder_name;
    int feeder_index;
};
