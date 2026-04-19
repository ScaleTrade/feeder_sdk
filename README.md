# Feeder SDK

This directory contains the exported public header set for feed modules.

Sync command:

```bash
./tools/sync_feeder_sdk.sh
```

Publish command:

```bash
./tools/publish_sdk.sh feeder
```

This command runs sync, smoke-check, creates a commit for `sdk/feeder` if the snapshot changed, and then pushes the SDK to the `feeder_sdk` remote with `git subtree`.

The command rebuilds:

- `sdk/feeder/include/FeederInterface.h`
- `sdk/feeder/include/FeederServerInterface.h`
- `sdk/feeder/include/Structures.h`
- `sdk/feeder/include/model/*`
- `sdk/feeder/include/rapidjson/*`

The SDK exposes only feeder-facing public headers and shared public structures required to build feed integrations outside the main repository tree.

Feeder contract:

- feeder state uses `FeederStateRecord`
- chart methods use `FeederCandleRecord`
- internal `structures/*.hpp` are no longer the public feeder contract

Example:

- `sdk/feeder/examples/minimal_feeder.cpp`

Notes:

- Public headers are synced directly from the product tree. Do not edit `sdk/feeder/include/*` manually.
- RapidJSON is exported under `sdk/feeder/include/rapidjson`, and public headers use `#include <rapidjson/...>`.
- Consumer include path should point to `sdk/feeder/include`.
- `sdk_contract/feeder/*` is the canonical source for the exported feeder contracts; `sdk/feeder/include/model/*` is the synced snapshot.

Smoke-check:

```bash
./tools/check_sdk_headers.sh
```

This script re-syncs the SDKs and runs a syntax-only compile check for the SDK example files.
