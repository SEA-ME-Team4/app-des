INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
./execute/battery
cd ${INIT_DIR}