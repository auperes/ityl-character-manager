import QtQuick
import QtQuick.Layouts

Component {
    id: groupPartView

    ColumnLayout {
        implicitWidth: parent.width

        Text {
            id: subGroupTitle
            text: display.name
            font.pointSize: display.nameSize
            font.bold: true
        }

        Text {
            id: subGroupDescription
            Layout.fillWidth: true
            Layout.preferredWidth: parent.parent.width
            text: display.description
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignJustify
            visible: Boolean(display.description)
        }

        GridView {
            id: currentCharacters
            visible: currentCharacters.count > 0
            cellHeight: 370
            cellWidth: 580
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: contentHeight
            flow: GridView.FlowLeftToRight
            layoutDirection: GridView.LeftToRight

            model: display.currentCharacters.model
            delegate: CharacterCompactView {}
        }

        Text {
            text: "Old characters"
            font.pointSize: 10
            visible: oldCharacters.count > 0
        }

        GridView {
            id: oldCharacters
            visible: oldCharacters.count > 0
            interactive: false
            cellWidth: 110
            cellHeight: 150
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            flow: GridView.FlowLeftToRight
            layoutDirection: GridView.LeftToRight

            model: display.oldCharacters.model
            delegate: CharacterMinimizedView {}
        }
    }
}
