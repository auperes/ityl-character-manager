import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import Ityl 1.0

Item {
    id: groupView
    anchors.fill: parent
    property GroupUiView groupUiView

    Component {
        id: groupParts

        ListView {
            id: groupPartsList
            model: groupUiView.parts
            implicitHeight: contentHeight
            spacing: 30
            delegate: GroupPartView {}
        }
    }

    ScrollView {
        anchors.fill: parent
        clip: true
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        ColumnLayout {
            implicitWidth: groupView.width

            Text {
                Layout.alignment: Qt.AlignCenter
                text: groupUiView.name
                font.pointSize: 16
                font.bold: true
            }

            Text {
                Layout.fillWidth: true
                Layout.preferredWidth: groupView.width
                text: groupUiView.description
                wrapMode: Text.WordWrap
            }

            Loader {
                sourceComponent: groupUiView.hasParts ? groupParts : ""
            }

            Item {
                Layout.fillHeight: true
            }
        }
    }
}
