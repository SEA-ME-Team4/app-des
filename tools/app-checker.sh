echo [App Checker Initialize]
echo

check_service()
{   
    local init_count=$(ps|grep -w ./$1/execute/$1|grep -v 'grep'|grep -v $0|wc -l)
    if [ ${init_count} -eq 0 ]
    then
        echo $1 is Not Running
        nohup ./$1/$1.sh </dev/null >/dev/null 2>&1 &
        echo Running $1 Automatically
    fi
    echo
}

while :
do
    check_service instrument_cluster
    check_service head_unit
    check_service input
    check_service speed
    check_service battery
    check_service racer
    check_service exception_handler
    sleep 1
done

echo
echo [App Checker Finalize]
