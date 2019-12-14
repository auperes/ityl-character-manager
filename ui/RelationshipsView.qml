import QtQuick 2.0
import QtQuick.Layouts 1.12

Component {
    ListView {
        id: relationshipsListView
        model: display.relationships
        delegate: GridLayout {
            columns: 2
            Layout.fillHeight: true
            Text {
                Layout.preferredWidth: 100
                text: model.display.type
                height: parent.height
                font.bold: true
            }
            Text {
                Layout.preferredWidth: 380
                text: model.display.names
                wrapMode: Text.WordWrap
                height: parent.height
            }
        }
    }
}
