export COMMONAPI_CONFIG=./config/commonapi.ini

INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
echo Setting time from time.bora.net
rdate -s time.bora.net
echo $(date)
export COMMONAPI_CONFIG=./config/commonapi.ini
./execute/head_unit -platform eglfs --no-sandbox
cd ${INIT_DIR}