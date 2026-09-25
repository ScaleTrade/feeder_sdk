#pragma once

#include <ctime>

struct FeederStateRecord {
    time_t last_tick = 0; // Unix time of the last quote received from the upstream provider.
    time_t last_ping = 0; // Unix time of the last successful upstream heartbeat response.
    int state = 0;        // Feeder-specific raw transport state; the server exposes but does not interpret it.
};
