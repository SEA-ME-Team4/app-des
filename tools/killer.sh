echo [Initialize]
echo

killer()
{
    local count=$(ps|grep -w ./$1/execute/$1|grep -v 'grep'|grep -v $0|wc -l)
    echo [$1]
    if [ ${count} -eq 0 ]
    then
        echo Not Running
        NotRunning+=($1)
    else
        var=$(ps|grep -w ./$1/execute/$1|grep -v 'grep'|grep -v $0)
        pid=$(echo ${var} | cut -d " " -f1)
        kill -n 9 ${pid}

        sleep 0.5
        local check=$(ps|grep -w ./$1s/execute/$1|grep -v 'grep'|grep -v $0|wc -l)
        if [ ${check} -eq 0 ]
        then
            echo Killed
            Killed+=($1)
        else
            echo Failed
            Failed+=($1)
        fi
    fi
    echo
}

NotRunning=()
Killed=()
Failed=()

if [ -z $1 ]
then
    killer instrument_cluster
    killer head_unit
    killer input
    killer can_app
    killer battery
    killer racer
    killer exception_handler
else
    killer $1
fi

echo [Summary]
echo ${#NotRunning[@]} NotRunning : ${NotRunning[@]}
echo ${#Killed[@]} Killed : ${Killed[@]}
echo ${#Failed[@]} Failed : ${Failed[@]}
echo
echo [Finalize]
