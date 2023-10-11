echo [Initialize]
echo

killer()
{
    local count=$(ps|grep -w ./execute/$1|grep -v 'grep'|grep -v $0|wc -l)
    echo [$1]
    if [ ${count} -eq 0 ]
    then
        echo Not Running
        NotRunning+=($1)
    else
        var=$(ps|grep -w ./execute/$1|grep -v 'grep'|grep -v $0)
        pid=$(echo ${var} | cut -d " " -f1)
	echo ${pid}
        kill -n 9 ${pid}
        echo Killed
        Killed+=($1)
    fi
    echo
}

NotRunning=()
Killed=()

if [ -z $1 ]
then
    killer instrument_cluster
    killer head_unit
    killer input
    killer speed
    killer battery
    killer racer
    killer exception_handler
else
    killer $1
fi

echo [Summary]
echo ${#NotRunning[@]} NotRunning : ${NotRunning[@]}
echo ${#Killed[@]} Killed : ${Killed[@]}
echo
echo [Finalize]
