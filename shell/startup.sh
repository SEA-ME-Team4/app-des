#!/bin/bash

echo [Initialize]
echo

check_and_run()
{   
    echo [$1]
    echo Checking $1...
    local init_count=$(ps -ef|grep -w ./execute/$1|grep -v 'grep'|grep -v $0|wc -l)
    if [ ${init_count} -eq 0 ]
    then
        echo $1 is Not Running
        nohup ./execute/$1 </dev/null >/dev/null 2>&1 &
        disown
        echo Running $1 Automatically
        sleep 1

        local final_count=$(ps -ef|grep -w ./execute/$1|grep -v 'grep'|grep -v $0|wc -l)
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
        echo Succeed
        Succeed+=($1)
    fi   
    echo
}

Succeed=()
Failed=()

check_and_run instrument_cluster
check_and_run head_unit
check_and_run input
check_and_run speed
check_and_run battery
check_and_run racer
check_and_run exception_handler

echo [Summary]
echo ${#Succeed[@]} Running : ${Succeed[@]}
echo ${#Failed[@]} Failed : ${Failed[@]}
echo
echo [Finalize]