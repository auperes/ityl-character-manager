import QtQuick 2.0
import QtQuick.Layouts 1.12

Component {
    ColumnLayout {
        Text {
            text: "Peuples"
            font.bold: true
            Layout.preferredWidth: parent.width
        }

        ListView {
            id: ethniesListView
            Layout.preferredHeight: ethniesListView.count
            Layout.fillHeight: true
            model: display.ethnies
            delegate: RowLayout {
                Text {
                    text: modelData
                }
            }
        }

        Text {
            text: "Groupes"
            font.bold: true
            Layout.preferredWidth: parent.width
        }

        ListView {
            id: groupsListView
            Layout.preferredHeight: groupsListView.count
            Layout.fillHeight: true
            model: display.groups
            delegate: RowLayout {
                Text {
                    text: modelData
                }
            }
        }
    }

}
