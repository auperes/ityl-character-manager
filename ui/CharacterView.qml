import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

import Character 1.0

Component {
    RowLayout {
        AvatarView {
            Layout.preferredHeight: 400
            Layout.preferredWidth: 200
        }

        Frame {
            id: identityFrame
            Layout.preferredHeight: 400
            Layout.preferredWidth: 500

            ScrollView {
                anchors.fill: parent
                clip: true

                ColumnLayout {
                    anchors.fill: parent
                    Layout.alignment: Qt.AlignTop

                    IdentityView {
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: 250
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignTop
                    }

                    ListView {
                        id: relationshipsListView
                        Layout.preferredHeight: relationshipsListView.count * 22
                        Layout.preferredWidth: parent.width
                        Layout.fillHeight: true
                        Layout.fillWidth: true
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

                    ListView {
                        id: ethniesListView
                        Layout.preferredHeight: ethniesListView.count * 16
                        Layout.fillHeight: true
                        model: display.ethnies
                        delegate: RowLayout {
                            Text {
                                text: modelData
                            }
                        }
                    }

                    ListView {
                        id: groupsListView
                        Layout.preferredHeight: groupsListView.count * 16
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
        }

        Frame {
            Layout.fillHeight: true
            implicitWidth: 800

            ScrollView {
                implicitHeight: parent.height
                implicitWidth: 775
                clip: true

                Text {
                    Layout.alignment: Qt.AlignCenter
                    width: 770
                    text: model.display.description
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignJustify
                }
            }
        }
    }
}
