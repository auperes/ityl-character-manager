import QtQuick
import QtQuick.Layouts

Component {
    ColumnLayout {
        id: affiliationsView

        Text {
            text: "Peuples"
            font.bold: true
            Layout.preferredWidth: parent.width
        }

        ListView {
            id: ethniesListView
            Layout.preferredHeight: contentHeight
            Layout.bottomMargin: 5
            model: display.ethnies
            delegate: RowLayout {
                Text {
                    text: modelData
                    wrapMode: Text.WordWrap
                    Layout.preferredWidth: affiliationsView.width
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
            Layout.preferredHeight: contentHeight
            Layout.fillHeight: true
            model: display.groups
            delegate: RowLayout {
                Text {
                    text: display.styledGroupInfo
                    wrapMode: Text.WordWrap
                    Layout.preferredWidth: affiliationsView.width
                }
            }
        }

        Item { Layout.fillHeight: true }
    }

}
