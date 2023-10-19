import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window  {
    id: main
    visible: true
    width: 1024
    height: 600
    color: "#000000"

    property double ratio: 0.5
    property int loc_x: -(width * ratio / 2)
    property int loc_y: -(height * ratio / 2)

    MainLayout {
        visible: true
        scale: ratio

        //Match target LCD
        x: loc_x
        y: loc_y
    }
}
