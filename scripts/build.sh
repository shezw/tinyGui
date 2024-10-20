#!/bin/bash

######################################
##          Project Info

PROJECT=tinyGUI
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
SHARED="OFF"

MAKE_CORES="-j32"
CMAKE_COMMAND="cmake"
MAKE_COMMAND="make"
MAKE_INSTALL_COMMAND="make install"
AUTOTOOL_COMMAND="configure"
AUTOTOOL_GEN="aclocal & autoconf & automake"
CMAKE_TOOLCHAIN_FILE="${PROJ_DIR}/cmake/cross_toolchain.cmake"

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
            SHARED="ON"
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
  ReadBuildINI
fi

CMAKE_OPTIONS=" \
-D CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} \
-D IS_CROSS_COMPILING=${IS_CROSS_COMPILING} \
-D TARGET_ARCH=${TARGET_ARCH} \
-D TARGET_SYSTEM=${TARGET_SYSTEM} \
-D COMPILER_PATH=${COMPILER_PATH} \
-D COMPILER_BIN_DIR=${COMPILER_BIN_DIR} \
-D COMPILER_PREFIX=${COMPILER_PREFIX} \
-D COMPILER_VERSION=${COMPILER_VERSION} \
-D COMPILER_TARGET_PREFIX=${LOCAL_DIR} \
-D DEBUG_TYPE=${DEBUG_TYPE} \
-D COMPILER_CC=${COMPILER_CC} \
-D COMPILER_CXX=${COMPILER_CXX} \
-D COMPILER_AR=${COMPILER_AR} \
-D COMPILER_LD=${COMPILER_LD} \
-D COMPILER_NM=${COMPILER_NM} \
-D COMPILER_OBJDUMP=${COMPILER_OBJDUMP} \
-D COMPILER_RANLIB=${COMPILER_RANLIB} \
-D PROJ_DIR=${PROJ_DIR} \
-D PLATFORM=${PLATFORM} \
-D BUILD_DIR=${BUILD_DIR} \
-D LOCAL_DIR=${LOCAL_DIR} \
-D INSTALL_PKGCONFIG_DIR=${LOCAL_DIR}/lib/pkgconfig \
-D CMAKE_INSTALL_PREFIX=${LOCAL_DIR} \
-D CMAKE_BUILD_TYPE=${DEBUG_TYPE}
-D BUILD_SHARED_LIBS=${SHARED}
"

mkdir -p "${BUILD_DIR}/${PROJECT}"
mkdir -p "${LOCAL_DIR}"

cd ${BUILD_DIR}/${PROJECT}

${CMAKE_COMMAND} ${PROJ_DIR} ${CMAKE_OPTIONS}

${MAKE_COMMAND} ${MAKE_CORES}

${MAKE_INSTALL_COMMAND} ${MAKE_CORES}