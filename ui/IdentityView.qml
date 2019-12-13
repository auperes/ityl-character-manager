import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

import Character 1.0

Item {
    Layout.alignment: Qt.AlignTop
    ColumnLayout {
        anchors.fill: parent
        Layout.alignment: Qt.AlignTop

        Rectangle {
            Layout.alignment: Qt.AlignTop
            Layout.preferredWidth: parent.width
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
        }

        ListView {
            id: rolesListView
            Layout.preferredHeight: rolesListView.count * 14
            model: display.roles
            delegate: RowLayout {
                Text {
                    text: modelData
                }
            }
        }

        ListView {
            id: skillsListView
            Layout.preferredHeight: skillsListView.count * 14
            model: display.skills
            delegate: RowLayout {
                Text {
                    Layout.preferredWidth: 70
                    text: model.display.skillName
                    font.bold: true
                }
                Text {
                    text: model.display.skillValues
                }
            }
        }

        Text {
            text: model.display.birthPlace
        }

        Text {
            text: model.display.livelyPlace
        }
    }
}
