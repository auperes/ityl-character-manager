import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Character 1.0

ListView {
    id: characterView
    width: 1200
    implicitHeight: 880
    anchors.fill: parent
    clip: true

    model: CharacterModel {
        characters: charactersList
    }

    delegate: RowLayout {
        implicitWidth: parent.width
        anchors.margins: 15
        Frame {
            Image {
                source: model.avatar
            }
        }

        Frame {
            id: identityFrame
            implicitHeight: parent.height
            implicitWidth: 400
            ColumnLayout {
                anchors.fill: parent
                Label {
                    text: model.fullName
                }
                Label {
                    text: model.title
                }
                Label {
                    Layout.preferredWidth: parent.width
                    text: model.quote
                    wrapMode: Label.WordWrap
                }

                ListView {
                    Layout.fillHeight: true
                    model: characterRoles
                    delegate: RowLayout {
                        Label {
                            text: modelData
                        }
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    model: SkillModel {
                        skills: model.skills
                    }
                    delegate: RowLayout {
                        Label {
                            text: model.skillName
                        }
                        Label {
                            text: model.skillValues
                        }
                    }
                }

                Label {
                    text: model.birthPlace
                }

                Label {
                    text: model.livelyPlace
                }

                ListView {
                    Layout.fillHeight: true
                    model: RelationshipModel {
                        relationships: model.relationships
                    }
                    delegate: RowLayout {
                        Label {
                            text: model.type
                        }
                        Label {
                            Layout.preferredWidth: identityFrame.width
                            text: model.names
                            wrapMode: Label.WordWrap
                        }
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    model: ethnies
                    delegate: RowLayout {
                        Label {
                            text: modelData
                        }
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    model: groups
                    delegate: RowLayout {
                        Label {
                            text: modelData
                        }
                    }
                }
            }
        }

        Frame {
            Layout.fillHeight: true
            implicitWidth: 600
            Label {
                anchors.fill: parent
                text: model.description
                wrapMode: Label.WordWrap
            }
        }
    }
}
