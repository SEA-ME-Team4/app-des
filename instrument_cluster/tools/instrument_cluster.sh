INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
./execute/instrument_cluster -platform linuxfb
cd ${INIT_DIR}