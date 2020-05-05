import QtQuick 2.0
import QtQuick.Layouts 1.12

Item {
    ColumnLayout {
        anchors.fill: parent

        Text {
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width
            text: "Group title"
        }

        Text {
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width
            text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
            wrapMode: Text.WordWrap
        }

        GroupPartView {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

}
