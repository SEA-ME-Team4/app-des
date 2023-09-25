import QtQuick 2.0

Rectangle {
    id: statusindicator
    property double raceropacity: (!parent.racer_status)? 1 : 0
    property double speedopacity: (parent.speed_status || parent.racer_status)? 1 : 0.3
    property double inputopacity: (parent.input_status || parent.racer_status)? 1 : 0.3
    property double batteryopacity: (parent.battery_status || parent.racer_status)? 1 : 0.3
    property double gearopacity: (parent.gear_status || parent.racer_status)? 1 : 0.3
    color: "black"

    Image {
    source: "/images/top-line.png"
    fillMode: Image.PreserveAspectFit
    }

    Image {
        id: speedstatusimage
        x: 0
        y: 12
        source: "/images/speedstatus.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.speedopacity
    }

    Image {
        id: speedstatusimage_racercheck
        x: 0
        y: 12
        source: "/images/speedometercheck.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.raceropacity
    }

    Image {
        id: inputstatusimage
        x: 75
        y: 12
        source: "/images/inputstatus.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.inputopacity
    }

    Image {
        id: inputstatusimage_racercheck
        x: 75
        y: 12
        source: "/images/inputcheck.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.raceropacity
    }

    Image {
        id: batterystatusimage
        x: 146
        y: 12
        source: "/images/batterystatus.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.batteryopacity
    }

    Image {
        id: batterystatusimage_racercheck
        x: 146
        y: 12
        source: "/images/batterycheck.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.raceropacity
    }

    Image {
        id: tempstatusimage
        x: 224
        y: 12
        source: "/images/gearstatus.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.gearopacity
    }

    Image {
        id: tempstatusimage_racercheck
        x: 224
        y: 12
        source: "/images/gearcheck.png"
        fillMode: Image.PreserveAspectFit
        opacity: statusindicator.raceropacity
    }
}
