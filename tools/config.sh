echo [Initialize]
echo
INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)

echo Setting vsomeip.json
export VSOMEIP_CONFIGURATION_FILE=${SCRIPT_DIR}/vsomeip.json
echo vsomeip.json path is ${SCRIPT_DIR}/vsomeip.json

echo Setting commonapi.ini
export COMMONAPI_CONFIG=${SCRIPT_DIR}/commonapi.ini
echo vsomeip.json path is ${SCRIPT_DIR}/commonapi.ini

echo
echo [Finalize]
