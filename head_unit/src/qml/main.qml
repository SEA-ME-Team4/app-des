import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window  {
    id: main
    visible: true
    width: 1024
    height: 600
    color: "#000000"

    MainLayout {
        visible: true
        scale: 0.5

        //Match target LCD
        x: -256
        y: -150
    }

}
