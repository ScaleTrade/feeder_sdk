#pragma once

#include <ctime>

struct FeederStateRecord {
    time_t last_tick = 0;
    time_t last_ping = 0;
    int state = 0;
};
