import QtQuick 2.0
import QtQuick.Layouts 1.12

Component {
    id: groupPartView

    ColumnLayout {
        implicitWidth: parent.width

        Text {
            id: subGroupTitle
            Layout.alignment: Qt.AlignCenter
            text: "Subgroup title"
            font.pointSize: 14
            font.bold: true
        }

        Text {
            id: subGroupDescription
            Layout.fillWidth: true
            Layout.preferredWidth: parent.parent.width
            text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
            wrapMode: Text.WordWrap
        }

        ListView {
            interactive: false
            spacing: 10
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            model: charactersManager.addCollection("Tous", "").model
            delegate: CharacterView {}
        }
    }

}
