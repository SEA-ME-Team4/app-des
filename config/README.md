# Configuration

## Path of Cofiguration files

- Cofiguration files (`commonapi.ini` and `vsomeip.json`) need to be in a same path with execution files.
- As we are using shell script for execution, we decide to mark variables these configuration files by `export` command. (implemented in `tools/config.sh`)
    - export VSOMEIP_CONFIGURATION_FILE={path of `vsomeip.json`}
    - export COMMONAPI_CONFIG={path of `commonapi.ini`}

## commonapi.ini

- Define Connection between `CommonAPI Interface` and `Binding Library` for Runtime level
- Binding Library can be changed by modifying this file

## vsomeip.json

- Service ID and Instance ID is defined in `.fdepl` file
- In `vsomeip.json`, we can set many variables about vsomeip communication
    - `unicast` address
    - vsomeip `logging` option (include `dlt`)
    - `service port` (reliable-tcp / unreliable-udp)
    - `routing manager`
    - `multicast` address, `port` and `protocol(tcp/udp)` for `service discovery`
    

## Reference

- [vsomeip in 10 minutes](https://github.com/COVESA/vsomeip/wiki/vsomeip-in-10-minutes)
- [CommonAPI C SomeIP in 10 minutes](https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes)
