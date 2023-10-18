INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
./execute/head_unit -platform eglfs --no-sandbox
cd ${INIT_DIR}