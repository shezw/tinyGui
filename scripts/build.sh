#!/bin/bash

######################################
##          Project Info


PROJ_DIR=$(cd $(dirname $0);cd ../; pwd)
PROJ_SCRIPTS_DIR="${PROJ_DIR}/scripts"
PROJ_SRC_DIR="${PROJ_DIR}/src"
THIRD_DIR="${PROJ_DIR}/3rd"


host_type="unknown"
platform="unknown"
debug="Debug"
skip=0
help=0
clean=0
arch="x86_64"
cross=0
shared=0

make_cores=32
cmake_command="cmake"
make_command="make"
autotool_command="configure"
autotool_gen="aclocal & autoconf & automake"

set_build_config=0

INI_FILE=${PROJ_SCRIPTS_DIR}/${platform}.ini

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
            platform=$2
            shift 2
            ;;
        --shared)
            echo "Build libs with SHARED";
            shared=1
            shift 1
            ;;
        --release)
            echo "Build release (no debug)";
            debug=Release
            shift 1
            ;;
        -k|--skip)
            echo "Skip confirm";
            skip=1
            shift 1
            ;;
        -c|--clean)
            echo "clean build dir";
            clean=1
            shift 1
            ;;
        -h|--help)
            help=1
            shift 1
            ;;
        -d|--debug)
            case "$2" in
                "")
                    echo "Compile Mode: Debug(-d)";
                    debug=Debug
                    shift 1;
                    ;;
                *)
                    echo "Compile Mode: $2";
                    debug=$2
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

function ReadBuildINI() {
    echo "ReadBuildINI from ${INI_FILE}"
}

function SetBuildINI() {
  ${PROJ_SCRIPTS_DIR}/set-build-config.sh ${PROJ_DIR} ${platform} ${debug}
}

if [[ -f "${INI_FILE}" && ${set_build_config} -eq 0 ]]; then
  ReadBuildINI
else
  SetBuildINI
fi
