import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "MaterialIcons.js" as MdiFont

Component {
    Frame {
        RowLayout {
            ColumnLayout {
                AvatarView {
                    Layout.preferredHeight: 300
                    Layout.preferredWidth: 150
                    source: model.display.avatar
                }

                RowLayout {
                    Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter

                    Button {
                        text: MdiFont.Icon.account
                        font.family: materialFont.name
                        ToolTip.text: qsTr("Identité")
                        implicitWidth: implicitContentWidth + leftPadding + rightPadding
                        onClicked: detailedView.replace(identityView)
                    }

                    Button {
                        text: MdiFont.Icon.accountGroup
                        font.family: materialFont.name
                        implicitWidth: implicitContentWidth + leftPadding + rightPadding
                        onClicked: detailedView.replace(relationshipsView)
                    }

                    Button {
                        text: MdiFont.Icon.group
                        font.family: materialFont.name
                        implicitWidth: implicitContentWidth + leftPadding + rightPadding
                        onClicked: detailedView.replace(affiliationsView)
                    }

                    Button {
                        text: MdiFont.Icon.textLong
                        font.family: materialFont.name
                        implicitWidth: implicitContentWidth + leftPadding + rightPadding
                        onClicked: detailedView.replace(descriptionView)
                    }
                }

            }

            Frame {
                id: characterDetails
                Layout.preferredHeight: 350
                Layout.preferredWidth: 400

                StackView {
                    id: detailedView
                    anchors.fill: parent
                    initialItem: identityView

                    IdentityView {
                        id: identityView
                    }

                    RelationshipsView {
                        id: relationshipsView
                    }

                    AffiliationsView {
                        id: affiliationsView
                    }

                    DescriptionView {
                        id: descriptionView
                    }
                }
            }
        }
    }
}
