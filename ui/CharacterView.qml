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

            ColumnLayout {
                anchors.fill: parent

                IdentityView {
                    Layout.preferredWidth: parent.width
                    Layout.fillWidth: true
                    Layout.preferredHeight: 325
                }

                RowLayout {
                    Layout.preferredHeight: 45
                    Layout.alignment: Qt.AlignCenter

                    Button {
                        text: "Relations"
                        onClicked: detailedView.replace(relationshipsView)
                    }

                    Button {
                        text: "Affiliations"
                        onClicked: detailedView.replace(affiliationsView)
                    }

                    Button {
                        text: "Description"
                        onClicked: detailedView.replace(descriptionView)
                    }
                }
            }
        }

        Frame {
            Layout.preferredHeight: 400
            Layout.preferredWidth: mainWindow.width - 800

            StackView {
                id: detailedView
                anchors.fill: parent

                RelationshipsView {
                    id: relationshipsView
                }

                AffiliationsView {
                    id: affiliationsView
                }

                DescriptionView {
                    id: descriptionView
                }

                initialItem: descriptionView
            }
        }
    }
}
