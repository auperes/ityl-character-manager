import QtQuick
import QtQuick.Controls

Button {
    id: buttonLink
    padding: 0

    contentItem: Text {
        text: buttonLink.text
        MouseArea {
            hoverEnabled: true
            anchors.fill: parent
            cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
            onEntered: {
                parent.color = "blue"
                parent.font.underline = true
            }
            onExited: {
                parent.color = "black"
                parent.font.underline = false
            }
            onClicked: buttonLink.clicked()
        }
    }

    background: Rectangle {
    }
}
