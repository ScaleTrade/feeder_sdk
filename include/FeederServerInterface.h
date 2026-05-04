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
    virtual ~FeederServerInterface() = default;

    virtual int TickSet(TickInfo& tick) = 0; //set quotes tick
    virtual int LogsOut(const std::string& type, const std::string& message) = 0;  //send logs to console
    static int GetApiVersion() { return FEEDER_SERVER_API; }

   //+------------------------------------------------------------------+
    // Chart
    //+------------------------------------------------------------------+
    virtual int GetCandles(const std::string& symbol, const std::string& frame, time_t from, time_t to, std::vector<FeederCandleRecord>* candles) = 0;
    virtual int SetCandles(const std::string& symbol, const std::vector<FeederCandleRecord>& candles) = 0;
    virtual int DeleteCandlesAll(const std::string& symbol) = 0;
    virtual int DeleteCandlesPeriod(const std::string& symbol, time_t from, time_t to) = 0;
    virtual int ImportCandleStores(const std::vector<FeederCandleRecord>& candles, int flush_data,const std::string& symbol) = 0;

    //+------------------------------------------------------------------+
    // Stream
    //+------------------------------------------------------------------+
    virtual int SendToManager(int manager_id, const rapidjson::Value& data) = 0; //send data to some Manager
    virtual int BroadcastToManagers(const rapidjson::Value& data) = 0; //send data to all Managers
    virtual int BroadcastNotifyToManagers(const rapidjson::Value& data) = 0; //send data to all Managers

    //+------------------------------------------------------------------+
    // Symbols
    //+------------------------------------------------------------------+
    virtual int GetSymbolsList(std::vector<std::string>* symbols) = 0;
    virtual int GetSymbolsListBySecId(int sec_index, std::vector<std::string>* symbols) = 0;

};
