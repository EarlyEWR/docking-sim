#!/usr/bin/env bash
set -euo pipefail

MODE="${1:-bridge}"                    # bridge (default) or host
IMAGE="${IMAGE_NAME:-telemetry-bridge:foxy}"    # optional image override
PORT="${PORT:-8091}"                   # optional UDP port override

case "$MODE" in
  bridge)
    echo "Mode: bridge | UDP port: ${PORT} | Image: ${IMAGE}"
    exec docker run --rm -p "${PORT}:${PORT}/udp" "${IMAGE}"
    ;;
  host)
    echo "Mode: host | Image: ${IMAGE}"
    exec docker run --rm --network host "${IMAGE}"
    ;;
  *)
    echo "Usage: $0 {bridge|host}"
    echo " IMAGE_NAME=<name> override image (default: telemetry-bridge:foxy)"
    echo " PORT=<port> override UDP port, bridge mode only (default: 8091)"
    exit 1
    ;;
esac