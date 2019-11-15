import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

import Character 1.0

Component {
    RowLayout {
        Frame {
            RowLayout {
                anchors.fill: parent
                Image {
                    anchors.margins: 0
                    source: model.display.avatar
                }
            }
        }

        Frame {
            id: identityFrame
            implicitHeight: parent.height
            implicitWidth: 500

            ScrollView {
                implicitHeight: parent.height
                implicitWidth: 475
                clip: true

                ColumnLayout {
                    anchors.fill: parent

                    Rectangle {
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: characterHeader.height + 6
                        color: "#b1cae7"

                        ColumnLayout {
                            width: parent.width
                            id: characterHeader

                            Item { Layout.fillHeight: true }

                            Text {
                                text: model.display.fullName
                                Layout.alignment: Qt.AlignCenter
                                font.pointSize: 12
                            }

                            Text {
                                text: model.display.title
                                Layout.alignment: Qt.AlignCenter
                                font.pointSize: 9
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
                                Layout.preferredWidth: 60
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

                    ListView {
                        id: relationshipsListView
                        Layout.preferredHeight: relationshipsListView.count * 20
                        model: display.relationships
                        delegate: GridLayout {
                            columns: 2
                            Layout.fillHeight: true
                            Text {
                                Layout.preferredWidth: 75
                                text: model.display.type
                                height: parent.height
                                font.bold: true
                            }
                            Text {
                                Layout.preferredWidth: 390
                                text: model.display.names
                                wrapMode: Text.WordWrap
                                height: parent.height
                            }
                        }
                    }

                    ListView {
                        id: ethniesListView
                        Layout.preferredHeight: ethniesListView.count * 14
                        model: display.ethnies
                        delegate: RowLayout {
                            Text {
                                text: modelData
                            }
                        }
                    }

                    ListView {
                        id: groupsListView
                        Layout.preferredHeight: groupsListView.count * 14
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
