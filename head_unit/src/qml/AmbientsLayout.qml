import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

GridLayout {
    width: 886
    height: 553

    property color ambientColor: control.color

    Control {
        id: control
        property real ringWidth: 20
        property real hsvValue: 1.0
        property real hsvSaturation: 1.0

        anchors.centerIn: parent

        readonly property color color: Qt.hsva(mousearea.angle, 1.0, 1.0, 1.0)

        contentItem: Item {
            implicitWidth: 500
            implicitHeight: width

            ShaderEffect {
                id: shadereffect
                width: parent.width; height: parent.height
                readonly property real ringWidth: control.ringWidth / width / 2
                readonly property real s: control.hsvSaturation
                readonly property real v: control.hsvValue

                vertexShader: "
                    #version 300 es

                    layout(location = 0) in vec4 a_position;
                    layout(location = 1) in vec2 a_texCoord;
                    out vec2 qt_TexCoord0;

                    void main() {
                        gl_Position = a_position;
                        qt_TexCoord0 = a_texCoord;
                    }"

                fragmentShader: "
                    #version 300 es

                    precision mediump float;

                    in vec2 qt_TexCoord0;
                    out vec4 FragColor;

                    uniform float qt_Opacity;
                    uniform float ringWidth;
                    uniform float s;
                    uniform float v;

                    vec3 hsv2rgb(vec3 c) {
                        vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
                        vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
                        return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
                    }

                    void main() {
                        vec2 coord = qt_TexCoord0 - vec2(0.5);
                        float ring = smoothstep(0.0, 0.01, -abs(length(coord) - 0.5 + ringWidth) + ringWidth);
                        FragColor = vec4(hsv2rgb(vec3(-atan(coord.y, coord.x) / 6.2831 + 0.5, s, v)), 1.0);
                        FragColor *= ring;
                    }"
            }

            Rectangle {
                id: indicator
                x: (parent.width - width)/2
                y: control.ringWidth * 0.1

                width: control.ringWidth * 0.8; height: width
                radius: width/2

                color: 'white'
                border {
                    width: mousearea.containsPress ? 3 : 1
                    color: Qt.lighter(control.color)
                    Behavior on width { NumberAnimation { duration: 50 } }
                }

                transform: Rotation {
                    angle: mousearea.angle * 360
                    origin.x: indicator.width/2
                    origin.y: control.availableHeight/2 - indicator.y
                }
            }

            MouseArea {
                id: mousearea
                anchors.fill: parent
                property real angle: Math.atan2(width/2 - mouseX, mouseY - height/2) / 3.14 / 2  + 0.5
            }
        }
    }
}
