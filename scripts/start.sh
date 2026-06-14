#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
COMPOSE_FILE="${ROOT_DIR}/docker-compose.yaml"
MODE="${1:-bridge}"
NO_BUILD="${NO_BUILD:-0}"

COMPOSE_ARGS=()
[[ "${NO_BUILD}" != "1" ]] && COMPOSE_ARGS+=(--build)

case "$MODE" in 
    bridge)
        exec docker compose -f "${COMPOSE_FILE}" --profile bridge up "${COMPOSE_ARGS[@]}"
        ;;
    host)
        exec docker compose -f "${COMPOSE_FILE}" --profile host up "${COMPOSE_ARGS[@]}"
        ;;
    *)
    echo "Usage: $0 {bridge|host}"
    echo " NO_BUILD=1 skip rebuilding the image"
    exit 1
    ;;
esac