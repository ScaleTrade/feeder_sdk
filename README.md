# Feeder SDK

This directory contains the exported public header set for feed modules.

Sync command:

```bash
./tools/sync_feeder_sdk.sh
```

The command rebuilds:

- `sdk/feeder/include/FeederInterface.h`
- `sdk/feeder/include/FeederServerInterface.h`
- `sdk/feeder/include/Structures.h`
- `sdk/feeder/include/structures/*`
- `sdk/feeder/include/rapidjson/*`

The SDK exposes only feeder-facing public headers and shared public structures required to build feed integrations outside the main repository tree.

Example:

- `sdk/feeder/examples/minimal_feeder.cpp`

Notes:

- Public headers are synced directly from the product tree. Do not edit `sdk/feeder/include/*` manually.
- RapidJSON is exported under `sdk/feeder/include/rapidjson`, and public headers use `#include <rapidjson/...>`.
- Consumer include path should point to `sdk/feeder/include`.

Smoke-check:

```bash
./tools/check_sdk_headers.sh
```

This script re-syncs the SDKs and runs a syntax-only compile check for the SDK example files.
