import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Ityl 1.0

Item {
    id: groupView
    property GroupUiView groupUiView

    Component {
        id: groupParts

        ListView {
            id: groupPartsList
            model: groupUiView.parts
            interactive: false
            implicitHeight: contentHeight
            spacing: 30
            delegate: GroupPartView {}
        }
    }

    ScrollView {
        anchors.fill: parent
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        ColumnLayout {
            implicitWidth: groupView.width - 40

            Rectangle {
                Layout.preferredHeight: groupHeader.height + 6
                Layout.fillWidth: true
                color: groupUiView.nationColor
                Layout.leftMargin: 20
                Layout.rightMargin: 20

                ColumnLayout {
                    width: parent.width
                    id: groupHeader

                    Item { Layout.fillHeight: true }

                    Text {
                        Layout.alignment: Qt.AlignCenter
                        text: groupUiView.name
                        font.pointSize: 18
                        font.bold: true
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            Text {
                Layout.fillWidth: true
                Layout.preferredWidth: groupView.width - 40
                text: groupUiView.description
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignJustify
                Layout.leftMargin: 20
                Layout.rightMargin: 20
            }

            Loader {
                sourceComponent: groupUiView.hasParts ? groupParts : ""
                Layout.fillWidth: true
                Layout.leftMargin: 20
                Layout.rightMargin: 20
            }

            Item {
                Layout.fillHeight: true
                Layout.leftMargin: 20
                Layout.rightMargin: 20
            }
        }
    }
}
