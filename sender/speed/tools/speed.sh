INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
export COMMONAPI_CONFIG=./config/commonapi.ini
echo Initializing CAN...
ip link set can0 up type can bitrate 1000000   dbitrate 8000000 restart-ms 1000 berr-reporting on fd on
ifconfig can0 txqueuelen 65536
echo Done.
./execute/speed
cd ${INIT_DIR}