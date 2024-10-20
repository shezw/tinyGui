#!/bin/bash

######################################
##          Project Info

PROJ_DIR=$1
PLATFORM=$2
DEBUG_TYPE=$3

echo "Build-Config run with parameters [$1] [$2] [$3] "

PROJ_SRC_DIR="${PROJ_DIR}/src"
THIRD_DIR="${PROJ_DIR}/3rd"
PROJ_SCRIPTS_DIR="${PROJ_DIR}/scripts"
BUILD_DIR="${PROJ_DIR}/build/${PLATFORM}"
LOCAL_DIR="${PROJ_DIR}/local/${PLATFORM}"

INI_FILE="${PROJ_SCRIPTS_DIR}/${PLATFORM}.ini"

# platform default values
  # ssd202
platform_ssd202_toolchain="/opt/toolchain/arm-unknown-linux-gnueabihf"


  # macos
platform_mac_arch="arm64"

BUILD_TO_STANDALONE_FOLDER=1
IS_CROSS_COMPILING=0
TARGET_ARCH=""
COMPILER_PATH=""
COMPILER_BIN_DIR=""
COMPILER_PREFIX=""
COMPILER_VERSION=""

COMPILER_CC="gcc"
COMPILER_CXX="g++"
COMPILER_AR="ar"
COMPILER_LD="ld"
COMPILER_NM="nm"
COMPILER_OBJDUMP="objectdump"
COMPILER_RANLIB="ranlib"

function CheckToolchainUtil() {
    tool=$1
    ## todo
}

function ExitWithHelp() {

    echo "Usage:
ProjectDir, Platform is Required
./build-config.sh [ProjectDir] [Platform] [DebugType]
./build-config.sh \$PWD mac Debug
    "
    exit
}

function CheckBasicParameters() {

  if [[ "${PLATFORM} " == " " || "${PLATFORM} " == "unknown " ]]; then
    echo "PLATFORM is Required."
    ExitWithHelp
  fi

}


function CheckStandaloneDebugDir() {
  if [ "${DEBUG_TYPE} " == " " ]; then
    echo "Debug type is not specified. Use Release Type."
    DEBUG_TYPE="Release"
  fi

  read -p "Do you want to build and comipile files to different folder by Debug Type
[default: $BUILD_TO_STANDALONE_FOLDER]
0) No    [ Build to ${BUILD_DIR} ]
1) Yes   [ Build to ${BUILD_DIR}/${DEBUG_TYPE} ]
" choice

  case $choice in
    0)
      BUILD_TO_STANDALONE_FOLDER=0
      ;;
    1)
      ;;
    "")
      echo ""
      ;;
  esac

  if [ ${BUILD_TO_STANDALONE_FOLDER} -eq 1 ]; then
      LOCAL_DIR="${LOCAL_DIR}/${DEBUG_TYPE}"
      BUILD_DIR="${BUILD_DIR}/${DEBUG_TYPE}"
  fi
}

function CheckCross() {

  # 读取用户输入
  read -p "Is cross compiling?： [default:0]
0) No
1) Yes
" choice

  # 根据用户选择输出路径
  case $choice in
      0)
          echo "0：Not cross compiling."
          ;;
      1)
          echo "1：Cross compiling."
          IS_CROSS_COMPILING=1
          ;;
      *)
          echo "Use default value ${IS_CROSS_COMPILING}"
          ;;
  esac

  echo "Cross Compiling [ ${IS_CROSS_COMPILING} ]
  "
}

function CheckToolchainPath(){
  read -p "Please input Toolchain path [default: $1]
" choice

  case $choice in
    "")
      echo "Use default compiler path $1"
      COMPILER_PATH="${1}"
      ;;
    *)
      echo "Use user specified compiler path"
      COMPILER_PATH="${choice}"
      ;;
  esac

  echo "Toolchain Path is: [$COMPILER_PATH]"
}

function CheckSSD202() {
  IS_CROSS_COMPILING=1
  TARGET_ARCH="arm"
  CheckToolchainPath ${platform_ssd202_toolchain}
}

function CheckMacOS() {

  # 读取用户输入
  read -p "MacOS Arch： [default:0]
0) arm64
1) x86_64
" choice

  # 根据用户选择输出路径
  case $choice in
      0)
          echo "0：arm64."
          ;;
      1)
          echo "1：x86_64"
          platform_mac_arch="x86_64"
          ;;
      *)
          echo "Use default value ${platform_mac_arch}"
          ;;
  esac

  TARGET_ARCH=${platform_mac_arch}
  echo "MacOS Arch: [ ${platform_mac_arch} ]
  "

  CheckToolchainPath "/usr"

}

function CheckPlatform() {

  if [ "$1 " == "ssd202 " ]; then
      echo "Arch is armv7 with hard float! Please set compiler toolchain path."
      CheckSSD202
  fi

  if [ "$1 " == "mac " ]; then
      CheckMacOS
  fi

}

function CheckToolchainVersion() {

  read -p "Toolchain Prefix： [default:\"\"]
eg: arm-linux-gnueabihf
" toolchain_prefix

  case $toolchain_prefix in
      "")
          echo "Use empty bin prefix"
          ;;
      *)
        COMPILER_PREFIX="${toolchain_prefix}"
        echo "Use value ${COMPILER_PREFIX}"
        ;;
  esac

  echo "Use specified toolchain prefix: [ ${COMPILER_PREFIX} ]
  "

  read -p "GCC Version： [default:\"\"]
" toolchain_version

  case $toolchain_version in
      "")
          echo "Use empty version"
          ;;
      *)
        COMPILER_VERSION="$toolchain_version"
          echo "Use version value ${COMPILER_VERSION}"
          ;;
  esac

  echo "Use specified toolchain version: [ ${COMPILER_VERSION} ]
  "

}

function CheckToolchain() {

    TOOLCHAIN_TOOL_PREFIX=""
    TOOLCHAIN_TOOL_SUFFIX=""

    if [ -d "${COMPILER_PATH}" ]; then
      COMPILER_BIN_DIR="${COMPILER_PATH}/bin"

      if [ -f "${COMPILER_BIN_DIR}/gcc" ]; then
        echo "Check ${COMPILER_BIN_DIR}/gcc OK!"
        COMPILER_PREFIX=""
        COMPILER_VERSION=""
      elif [ -f "${COMPILER_BIN_DIR}/gcc-${COMPILER_VERSION}" ]; then
        echo "Check ${COMPILER_BIN_DIR}/gcc-${COMPILER_VERSION} OK!"
        COMPILER_PREFIX=""
        TOOLCHAIN_TOOL_PREFIX=""
        TOOLCHAIN_TOOL_SUFFIX="-${COMPILER_VERSION}"

      elif [ -f "${COMPILER_BIN_DIR}/${COMPILER_PREFIX}-gcc" ]; then
        echo "Check ${COMPILER_BIN_DIR}/${COMPILER_PREFIX}-gcc OK!"
        COMPILER_VERSION=""
        TOOLCHAIN_TOOL_PREFIX="${COMPILER_PREFIX}-"
        TOOLCHAIN_TOOL_SUFFIX=""

      elif [ -f "${COMPILER_BIN_DIR}/${COMPILER_PREFIX}-gcc-${COMPILER_VERSION}" ]; then
        echo "Check ${COMPILER_BIN_DIR}/${COMPILER_PREFIX}-gcc-${COMPILER_VERSION} OK!"
        TOOLCHAIN_TOOL_PREFIX="${COMPILER_PREFIX}-"
        TOOLCHAIN_TOOL_SUFFIX="-${COMPILER_VERSION}"

      else
        echo "Check GCC Failed. ${COMPILER_BIN_DIR}/gcc not exists."
        CheckToolchainVersion
        CheckToolchain
      fi
    else
        echo "Check Toolchain Path Failed. ${COMPILER_PATH} not exists."
        CheckToolchainPath "${COMPILER_PATH}"
        CheckToolchain
    fi

    COMPILER_CC="${COMPILER_BIN_DIR}/${TOOLCHAIN_TOOL_PREFIX}gcc${TOOLCHAIN_TOOL_SUFFIX}"
    COMPILER_CXX="${COMPILER_BIN_DIR}/${TOOLCHAIN_TOOL_PREFIX}g++${TOOLCHAIN_TOOL_SUFFIX}"
    COMPILER_AR="${COMPILER_BIN_DIR}/${TOOLCHAIN_TOOL_PREFIX}ar${TOOLCHAIN_TOOL_SUFFIX}"
    COMPILER_LD="${COMPILER_BIN_DIR}/${TOOLCHAIN_TOOL_PREFIX}ld${TOOLCHAIN_TOOL_SUFFIX}"
    COMPILER_NM="${COMPILER_BIN_DIR}/${TOOLCHAIN_TOOL_PREFIX}nm${TOOLCHAIN_TOOL_SUFFIX}"
    COMPILER_OBJDUMP="${COMPILER_BIN_DIR}/${TOOLCHAIN_TOOL_PREFIX}objectdump${TOOLCHAIN_TOOL_SUFFIX}"
    COMPILER_RANLIB="${COMPILER_BIN_DIR}/${TOOLCHAIN_TOOL_PREFIX}ranlib${TOOLCHAIN_TOOL_SUFFIX}"

}

function SaveConfigIni() {

configuration="[toolchain]
; Compiler configuration
IS_CROSS_COMPILING=${IS_CROSS_COMPILING}
TARGET_ARCH=${TARGET_ARCH}
COMPILER_PATH=${COMPILER_PATH}
COMPILER_BIN_DIR=${COMPILER_BIN_DIR}
COMPILER_PREFIX=${COMPILER_PREFIX}
COMPILER_VERSION=${COMPILER_VERSION}
COMPILER_TARGET_PREFIX=${LOCAL_DIR}
DEBUG_TYPE=${DEBUG_TYPE}
COMPILER_CC=${COMPILER_CC}
COMPILER_CXX=${COMPILER_CXX}
COMPILER_AR=${COMPILER_AR}
COMPILER_LD=${COMPILER_LD}
COMPILER_NM=${COMPILER_NM}
COMPILER_OBJDUMP=${COMPILER_OBJDUMP}
COMPILER_RANLIB=${COMPILER_RANLIB}

[project]
; Project configuration
PROJ_DIR=${PROJ_DIR}
PLATFORM=${PLATFORM}
BUILD_DIR=${BUILD_DIR}
LOCAL_DIR=${LOCAL_DIR}
"

echo "${configuration}"
echo "${configuration}" > "${INI_FILE}"

}

CheckBasicParameters
CheckStandaloneDebugDir
CheckCross
CheckPlatform "${PLATFORM}"
CheckToolchain

SaveConfigIni
