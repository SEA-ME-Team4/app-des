echo [Initialize]
echo

check()
{   
    echo [$1]
    echo Checking $1...
    local init_count=$(ps|grep -w ./$1/execute/$1|grep -v 'grep'|grep -v $0|wc -l)
    if [ ${init_count} -eq 0 ]
    then
        echo $1 is Not Running
    else
        echo $1 is Running
    fi
    echo
}

if [ -z $1 ]
then
    check instrument_cluster
    check head_unit
    check input
    check speed
    check battery
    check racer
    check exception_handler
else
    check $1
fi

