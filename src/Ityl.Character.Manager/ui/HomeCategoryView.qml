import QtQuick
import QtQuick.Layouts

Item {
    id: homeCategoryView

    GridLayout {
        columns: 2
        rowSpacing: 20

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            visible: regionsList.count > 0

            Text {
                font.bold: true
                text: "Régions"
            }

            ListView {
                id: regionsList
                Layout.preferredHeight: contentHeight
                Layout.fillHeight: true
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.regions
                delegate: LinkButton {
                    text: modelData
                    onClicked: homeView.selectElement("region", modelData)
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            visible: ethniesList.count > 0

            Text {
                font.bold: true
                text: "Peuples"
            }

            ListView {
                id: ethniesList
                Layout.preferredHeight: contentHeight
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.ethnies
                delegate: LinkButton {
                    text: modelData
                    onClicked: homeView.selectElement("ethnie", modelData)
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            visible: organizationsList.count > 0

            Text {
                font.bold: true
                text: "Organisations"
            }

            ListView {
                id: organizationsList
                Layout.preferredHeight: contentHeight
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.organizations
                delegate: LinkButton {
                    text: modelData
                    onClicked: homeView.selectElement("group", modelData)
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            visible: familiesList.count > 0

            Text {
                font.bold: true
                text: "Familles"
            }

            ListView {
                id: familiesList
                Layout.preferredHeight: contentHeight
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.families
                delegate: LinkButton {
                    text: modelData
                    onClicked: homeView.selectElement("group", modelData)
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            visible: guildsList.count > 0

            Text {
                font.bold: true
                text: "Guildes"
            }

            ListView {
                id: guildsList
                Layout.preferredHeight: contentHeight
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.guilds
                delegate: LinkButton {
                    text: modelData
                    onClicked: homeView.selectElement("group", modelData)
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            visible: groupsList.count > 0

            Text {
                font.bold: true
                text: "Groupes"
            }

            ListView {
                id: groupsList
                Layout.preferredHeight: contentHeight
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.groups
                delegate: LinkButton {
                    text: modelData
                    onClicked: homeView.selectElement("group", modelData)
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            visible: backgroundList.count > 0

            Text {
                font.bold: true
                text: "Background"

            }

            ListView {
                id: backgroundList
                Layout.preferredHeight: contentHeight
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.backgrounds
                delegate: LinkButton {
                    text: modelData
                    onClicked: homeView.selectElement("background", modelData)
                }
            }
        }
    }
}
