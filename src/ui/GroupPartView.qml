import QtQuick 2.0
import QtQuick.Layouts 1.12

Item {

    ColumnLayout {
        anchors.fill: parent

        Text {
            id: subGroupTitle
            Layout.fillWidth: true
            text: "Subgroup title"
        }

        Text {
            id: subGroupDescription
            Layout.fillWidth: true
            text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
            wrapMode: Text.WordWrap
        }

        CharacterListView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: charactersManager.addCollection("Tous", "").model
        }
    }

}
