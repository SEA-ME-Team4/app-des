INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
export COMMONAPI_CONFIG=./config/commonapi.ini
./execute/battery
cd ${INIT_DIR}