echo [Initialize]
echo

INIT_DIR=${pwd}
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
cd ${SCRIPT_DIR}
sh config.sh

check_and_run()
{   
    echo [$1]
    echo Checking $1...
    local init_count=$(ps|grep ./$1/execute/$1|grep -v 'grep'|grep -v $0|wc -l)
    if [ ${init_count} -eq 0 ]
    then
        local is_file=$(ls|grep -w $1|grep -v 'grep'|wc -l)
        if [ ${is_file} -eq 0 ]
        then
            echo $1 is Not in execute folder
        else
            echo $1 is Not Running
            nohup ./$1/$1.sh </dev/null >/dev/null 2>&1 &
            echo Running $1 Automatically
            sleep 1
        fi

        local final_count=$(ps|grep -w ./$1/execute/$1|grep -v 'grep'|grep -v $0|wc -l)
        if [ ${final_count} -eq 0 ]
        then
            echo Failed
            Failed+=($1)
        else
            echo Succeed
            Succeed+=($1)
        fi
    else
        echo $1 is Already Running
        echo Pass
        Pass+=($1)
    fi   
    echo
}

Pass=()
Succeed=()
Failed=()

if [ -z $1 ]
then
    check_and_run head_unit
    check_and_run instrument_cluster
    sleep 2
    check_and_run input
    check_and_run speed
    check_and_run battery
    check_and_run racer
    check_and_run exception_handler
else
    check_and_run $1
fi

echo [Summary]
echo ${#Pass[@]} Pass : ${Pass[@]}
echo ${#Succeed[@]} Running : ${Succeed[@]}
echo ${#Failed[@]} Failed : ${Failed[@]}

cd ${INIT_DIR}
echo
echo [Finalize]
