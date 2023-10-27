# Tools

## Feature

- Register a shell script running the entire application as a `Service`
- Export `vsomeip` and `commonapi` configuration
- Continuously monitor while running
- Check process status and automatically restarting

## Description

| FileName | Description |
| --- | --- |
| app-service | Start whole application in background with nohup <br/> Call app-config and app-chekcer |
| app-config | export VSOMEIP_CONFIGURATION_FILE for vsomeip configuration (vsomeip.json) <br/> export COMMONAPI_CONFIG for commonapi configuration (commonapi.json) |
| app-checker | Check process status and automatically restart |

## Reference

- [nohup](https://en.wikipedia.org/wiki/Nohup)
