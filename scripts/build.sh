#!/bin/bash

######################################
##          Project Info


PROJ_DIR=$(cd $(dirname $0);cd ../; pwd)
PROJ_SCRIPTS_DIR="${PROJ_DIR}/scripts"
PROJ_SRC_DIR="${PROJ_DIR}/src"
THIRD_DIR="${PROJ_DIR}/3rd"

PLATFORM="unknown"
DEBUG_TYPE="Debug"
HOST_TYPE="unknown"
TARGET_SYSTEM="unknown"
SKIP=0
HELP=0
CLEAN=0
TARGET_ARCH="x86_64"
IS_CROSS_COMPILING=0
SHARED=0

MAKE_CORES=32
CMAKE_COMMAND="cmake"
MAKE_COMMAND="make"
AUTOTOOL_COMMAND="configure"
AUTOTOOL_GEN="aclocal & autoconf & automake"

set_build_config=0

while [[ $# -gt 0 ]];do
  key=${1}
  case ${key} in
        config)
          echo "Set build config";
          set_build_config=1
          shift 1
          ;;
        -p|--platform)
            echo "Platform: $2";
            PLATFORM=$2
            shift 2
            ;;
        --shared)
            echo "Build libs with SHARED";
            SHARED=1
            shift 1
            ;;
        --release)
            echo "Build release (no debug)";
            DEBUG_TYPE=Release
            shift 1
            ;;
        -k|--skip)
            echo "Skip confirm";
            SKIP=1
            shift 1
            ;;
        -c|--clean)
            echo "Clean build dir";
            CLEAN=1
            shift 1
            ;;
        -h|--help)
            HELP=1
            shift 1
            ;;
        -d|--debug)
            case "$2" in
                "")
                    echo "Compile Mode: Debug(-d)";
                    DEBUG_TYPE=Debug
                    shift 1;
                    ;;
                *)
                    echo "Compile Mode: $2";
                    DEBUG_TYPE=$2
                    shift 2;
                    ;;
            esac
            ;;
        --)
            shift
            break
            ;;
        *)
          echo "Invalid Args $1";
          shift
          break
          ;;
    esac
done

BUILD_DIR="${PROJ_DIR}/build/${PLATFORM}"
LOCAL_DIR="${PROJ_DIR}/local/${PLATFORM}"

INI_FILE=${PROJ_SCRIPTS_DIR}/${PLATFORM}.ini

source "${PROJ_SCRIPTS_DIR}/build-config.sh"

function ReadBuildINI() {
    echo "ReadBuildINI from ${INI_FILE}"
    ConfigReadFromINI
}

if [[ -f "${INI_FILE}" && ${set_build_config} -eq 0 ]]; then
  ReadBuildINI
else
  ConfigAndSave
fi
