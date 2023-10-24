echo [App Service Initialize]
echo

INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
sh app-config.sh

initial_service()
{   
    nohup ./$1/$1.sh </dev/null >/dev/null 2>&1 &
    echo Running $1 Automatically
    echo
}

initial_service head_unit
initial_service instrument_cluster
initial_service input
initial_service speed
initial_service battery
initial_service racer
initial_service exception_handler

echo Starting app-checker
nohup sh app-checker.sh </dev/null >/dev/null 2>&1 &

cd ${INIT_DIR}
echo
echo [App Service Finalize]
