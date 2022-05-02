import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Component {
    ColumnLayout {
        id: identityView

        Rectangle {
            Layout.preferredWidth: identityView.width
            Layout.preferredHeight: characterHeader.height + 6
            color: model.display.nationColor

            ColumnLayout {
                width: parent.width
                id: characterHeader

                Item { Layout.fillHeight: true }

                Text {
                    text: model.display.fullName
                    Layout.alignment: Qt.AlignCenter
                    font.pointSize: 14
                }

                Text {
                    text: model.display.title
                    Layout.alignment: Qt.AlignCenter
                    font.pointSize: 12
                    visible: model.display.hasTitle
                }

                Item { Layout.fillHeight: true }
            }
        }

        Text {
            Layout.preferredWidth: parent.width
            text: model.display.quote
            wrapMode: Label.WordWrap
            font.italic: true
            Layout.bottomMargin: 10
        }

        ListView {
            id: rolesListView
            Layout.preferredHeight: contentHeight
            Layout.bottomMargin: 5
            model: display.roles
            delegate: RowLayout {
                Text {
                    text: modelData
                    wrapMode: Text.WordWrap
                    Layout.preferredWidth: identityView.width
                }
            }
        }

        ListView {
            id: skillsListView
            Layout.preferredHeight: contentHeight
            Layout.bottomMargin: 5
            model: display.skills
            delegate: RowLayout {
                Text {
                    Layout.preferredWidth: 70
                    text: model.display.skillName
                    font.bold: true
                }
                Text {
                    Layout.preferredWidth: identityView.width - 70
                    text: model.display.skillValues
                    wrapMode: Text.WordWrap
                }
            }
        }

        Text {
            text: model.display.birthPlace
        }

        Text {
            text: model.display.livelyPlace
        }

        Item { Layout.fillHeight: true }
    }
}
