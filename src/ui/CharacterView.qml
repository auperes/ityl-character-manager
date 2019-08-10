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
            implicitWidth: 400
            ColumnLayout {
                anchors.fill: parent

                Text {
                    text: model.display.fullName
                }
                Text {
                    text: model.display.title
                }
                Text {
                    Layout.preferredWidth: parent.width
                    text: model.display.quote
                    wrapMode: Label.WordWrap
                }

                ListView {
                    Layout.fillHeight: true
                    model: display.roles
                    delegate: RowLayout {
                        Text {
                            text: modelData
                        }
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    model: display.skills
                    delegate: RowLayout {
                        Text {
                            text: model.display.skillName
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

//                ListView {
//                    implicitHeight: 100
//                    model: RelationshipModel {
//                        relationships: model.relationships
//                    }
//                    delegate: RowLayout {
//                        Layout.fillHeight: true
//                        Text {
//                            text: model.type
//                            height: parent.height
//                        }
//                        Text {
//                            Layout.preferredWidth: 350
//                            text: model.names
//                            wrapMode: Text.WordWrap
//                            height: parent.height
//                        }
//                    }
//                }

                ListView {
                    Layout.fillHeight: true
                    model: display.ethnies
                    delegate: RowLayout {
                        Text {
                            text: modelData
                        }
                    }
                }

                ListView {
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

        Frame {
            Layout.fillHeight: true
            implicitWidth: 600
            Text {
                anchors.fill: parent
                text: model.display.description
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignJustify
            }
        }
    }
}
