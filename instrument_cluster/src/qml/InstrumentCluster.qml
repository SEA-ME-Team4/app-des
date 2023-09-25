import QtQuick 2.0
import VehicleClient 1.0

Rectangle {
    id: instrumentcluster
    color: "black"
    width: 1280
    height: 400

    property int timer_interval: 1000/120

    property int speed: 0
    property int battery: 0
    property int temp: 0
    property bool brake: false
    property int gear: 0

    property bool racer_status: true
    property bool speed_status: true
    property bool battery_status: true
    property bool input_status: true
    property bool gear_status: true

    property bool handler_status: false

    LeftCluster {
        x: 146
        y: 43
    }

    RightCluster {
        x: 774
        y: 43
    }

    GearSelection {
        x: 512
        y: 43
    }

    CenterCar {
        id: centerCar
        x: 430
        y: 54
    }

    StatusIndicator
    {
        x: 512
        y: 346
    }

    VehicleClient {
        id: vehicleclient

        onSpeedChanged: {instrumentcluster.speed = speed}
        onBatteryChanged: {instrumentcluster.battery = battery}
        onTempChanged: {instrumentcluster.temp = temp}
        onBrakeChanged: {instrumentcluster.brake = brake}
        onGearChanged: {instrumentcluster.gear = gear}

        onSpeedStatus: {instrumentcluster.speed_status = status}
        onBatteryStatus: {instrumentcluster.battery_status = status}
        onInputStatus: {instrumentcluster.input_status = status}
        onRacerStatus: {instrumentcluster.racer_status = status}
        onGearStatus: {instrumentcluster.gear_status = status}
    }
}
