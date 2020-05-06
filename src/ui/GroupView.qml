import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {
    id: groupView
    anchors.fill: parent

    ScrollView {
        anchors.fill: parent
        clip: true
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        ColumnLayout {
            implicitWidth: groupView.width

            Text {
                Layout.alignment: Qt.AlignCenter
                text: "Group title"
                font.pointSize: 16
                font.bold: true
            }

            Text {
                Layout.fillWidth: true
                Layout.preferredWidth: groupView.width
                text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                wrapMode: Text.WordWrap
            }

            ListView {
                model: 2
                Layout.fillWidth: true
                Layout.preferredHeight: contentHeight
                spacing: 30
                delegate: GroupPartView {}
            }

            Item {
                Layout.fillHeight: true
            }
        }
    }
}
