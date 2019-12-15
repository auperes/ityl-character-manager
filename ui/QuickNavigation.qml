import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Character 1.0

Item {
    RowLayout {
        Button {
            text: "Recharger"
            onClicked: { charactersList.refreshCharacters() }
        }

        Text {
            text: "Nations : "
        }

        ComboBox {
            id: nationsComboBox
            textRole: "display"
            implicitWidth: 300
            model: quickNavigation.nations

            onActivated: { charactersList.filterCharacters("nation", currentText) }
            Connections {
                target: quickNavigation
                onResetNations: { nationsComboBox.currentIndex = 0 }
            }

        }

        Text {
            text: "Peuples : "
        }

        ComboBox {
            id: ethniesComboBox
            textRole: "display"
            implicitWidth: 300
            model: quickNavigation.ethnies

            onActivated: { charactersList.filterCharacters("ethnie", currentText) }
            Connections {
                target: quickNavigation
                onResetEthnies: { ethniesComboBox.currentIndex = 0 }
            }
        }

        Text {
            text: "Groupes : "
        }

        ComboBox {
            id: groupsComboBox
            textRole: "display"
            implicitWidth: 300
            model: quickNavigation.groups

            onActivated: charactersList.filterCharacters("group", currentText)
            Connections {
                target: quickNavigation
                onResetGroups: { groupsComboBox.currentIndex = 0 }
            }
        }
    }
}
