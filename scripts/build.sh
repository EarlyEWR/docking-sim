#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"

IMAGE_NAME="${IMAGE_NAME:-telemetry-bridge:foxy}"
NO_CACHE="${NO_CACHE:-0}"

DOCKER_ARGS=()
[[ "${NO_CACHE}" == 1 ]] && DOCKER_ARGS+=(--no-cache)

echo "Building ${IMAGE_NAME} from ${ROOT_DIR}/Dockerfile"
docker build "${DOCKER_ARGS[@]}" -t "${IMAGE_NAME}" "${ROOT_DIR}"
echo "Build complete"