#!/bin/bash

echo [Initialize]
echo

killer()
{
    local count=$(ps -ef|grep -w ./execute/$1|grep -v 'grep'|grep -v $0|wc -l)
    echo [$1]
    if [ ${count} -eq 0 ]
    then
        echo Not Running
        NotRunning+=($1)
    else
        var=$(ps -ef|grep -w ./execute/$1|grep -v 'grep'|grep -v $0)
        pid=$(echo ${var} | cut -d " " -f2)
        kill -9 ${pid}
        echo Killed
        Killed+=($1)
    fi
    echo
}

NotRunning=()
Killed=()

killer instrument_cluster
killer head_unit
killer input
killer speed
killer battery
killer racer
killer exception_handler

echo [Summary]
echo ${#NotRunning[@]} NotRunning : ${NotRunning[@]}
echo ${#Killed[@]} Killed : ${Killed[@]}
echo
echo [Finalize]