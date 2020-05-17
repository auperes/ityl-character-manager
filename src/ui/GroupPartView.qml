import QtQuick 2.0
import QtQuick.Layouts 1.12

Component {
    id: groupPartView

    ColumnLayout {
        implicitWidth: parent.width

        Text {
            id: subGroupTitle
            text: display.name
            font.pointSize: 14
            font.bold: true
        }

        Text {
            id: subGroupDescription
            Layout.fillWidth: true
            Layout.preferredWidth: parent.parent.width
            text: display.description
            wrapMode: Text.WordWrap
            visible: Boolean(display.description)
        }

        Text {
            text: "Current characters"
            font.pointSize: 10
            visible: currentCharacters.count > 0
        }

        ListView {
            id: currentCharacters
            visible: currentCharacters.count > 0
            interactive: false
            spacing: 10
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            model: display.currentCharacters.model
            delegate: CharacterView {}
        }

        Text {
            text: "Old characters"
            font.pointSize: 10
            visible: oldCharacters.count > 0
        }

        ListView {
            id: oldCharacters
            visible: oldCharacters.count > 0
            interactive: false
            spacing: 10
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            model: display.oldCharacters.model
            delegate: CharacterView {}
        }

        Loader {
            id: groupPartsLoader
            source: display.hasParts ? "GroupPartListView.qml" : ""
            Layout.preferredHeight: childrenRect.height
            Layout.preferredWidth: parent.parent.width
            Layout.fillWidth: true
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
