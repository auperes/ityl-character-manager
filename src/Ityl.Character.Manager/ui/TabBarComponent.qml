import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "MaterialIcons.js" as MdiFont

TabButton {
    id: control
    width: implicitWidth
    padding: 0

    property bool closeButtonVisible

    signal closedTab

    contentItem: RowLayout {
        anchors.fill: parent
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Text {
            text: control.text
            font: control.font
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            leftPadding: 10
            topPadding: 4
            bottomPadding: 4
            rightPadding: 10
        }

        Button {
            font.pointSize: 12
            padding: 0
            rightPadding: 8
            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            text: MdiFont.Icon.closeBoxOutline
            font.family: materialFont.name
            visible: control.closeButtonVisible

            onClicked: {
                control.closedTab()
            }

            background: Rectangle {
                width: 0
                height: 0
            }
        }
    }
}
