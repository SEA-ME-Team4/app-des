import QtQuick 2.0

Image {
    id: centercar
    x: 0
    y: 0
    fillMode: Image.PreserveAspectFit
    source: "/images/field.png"

    property bool plight: (parent.brake || parent.gear==0) ? true : false
    property bool rlight: (parent.gear==1)? true : false
    property bool dlight: (!parent.brake && (parent.gear==3 || parent.gear==4))? true : false
    property bool redline: (parent.brake) ? true : false
    property bool whiteline: (!parent.brake && !(parent.speed==0) && (parent.gear==3 || parent.gear==4))? true : false

    Image {
        id: brakelight
        x: 0
        y: 0
        fillMode: Image.PreserveAspectFit
        source: "/images/car-highlights.png"
        visible: centercar.plight
        opacity: centercar.plight
        Behavior on opacity { NumberAnimation { duration: 500} }
    }

    Image {
        id: brakelineL
        x: 116
        y: 40
        source: "/images/red-border-left.png"
        fillMode: Image.PreserveAspectFit
        visible: centercar.redline
        opacity: centercar.redline
        Behavior on opacity { NumberAnimation { duration: 500} }
    }

    Image {
        id: brakelineR
        x: 235
        y: 40
        source: "/images/red-border-right.png"
        fillMode: Image.PreserveAspectFit
        visible: centercar.redline
        opacity: centercar.redline
        Behavior on opacity { NumberAnimation { duration: 500} }
    }

    Image {
        id: straight_arrow
        x: 200
        y: 79
        source: "/images/arrow-0.png"
        fillMode: Image.PreserveAspectFit
        visible: centercar.dlight
        opacity: centercar.dlight
        Behavior on opacity { NumberAnimation { duration: 500} }
    }

    Rectangle {
        x: 137
        y: 142
        visible: centercar.whiteline
        opacity: centercar.whiteline
        Behavior on opacity { NumberAnimation { duration: 500} }

        Image {
            id: l_line1
            x: 0
            y: 0
            fillMode: Image.PreserveAspectFit
            source: "/images/white-line-left.png"
        }

        Image {
            id: r_line3
            x: 146
            y: 61
            source: "/images/white-line-right.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: r_line1
            x: 127
            y: 0
            fillMode: Image.PreserveAspectFit
            source: "/images/white-line-right.png"
        }

        Image {
            id: r_line2
            x: 108
            y: -57
            fillMode: Image.PreserveAspectFit
            source: "/images/white-line-right.png"
        }

        Image {
            id: l_line2
            x: 19
            y: -57
            fillMode: Image.PreserveAspectFit
            source: "/images/white-line-left.png"
        }

        Image {
            id: l_line3
            x: -20
            y: 62
            source: "/images/white-line-left.png"
            fillMode: Image.PreserveAspectFit
        }
    }

    Image {
        id: rearlight
        x: 0
        y: 156
        fillMode: Image.PreserveAspectFit
        source: "/images/rearlight.png"
        visible: centercar.rlight
        opacity: centercar.rlight
        Behavior on opacity { NumberAnimation { duration: 500} }
    }
}
