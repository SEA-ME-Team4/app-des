echo Initializing CAN...
/sbin/ip link set can0 up type can bitrate 1000000   dbitrate 8000000 restart-ms 1000 berr-reporting on fd on
ifconfig can0 txqueuelen 65536
echo Done.
./speed/execute/speed