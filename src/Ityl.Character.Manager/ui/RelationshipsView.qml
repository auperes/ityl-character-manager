import QtQuick
import QtQuick.Layouts

Component {
    Item {
        id: relationshipsView
        ListView {
            id: relationshipsListView
            implicitHeight: contentHeight
            model: display.relationships
            delegate: GridLayout {
                columns: 2
                Layout.fillHeight: true
                Text {
                    id: relationshipType
                    Layout.preferredWidth: 100
                    text: model.display.type
                    height: parent.height
                    font.bold: true
                }
                Text {
                    Layout.preferredWidth: relationshipsView.width - relationshipType.width
                    text: model.display.names
                    wrapMode: Text.WordWrap
                    height: parent.height
                }
            }
        }
    }
}
