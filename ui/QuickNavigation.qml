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
            textRole: "display"
            implicitWidth: 300
            model: quickNavigation.nations

            onActivated: { charactersList.filterCharacters("nation", currentText) }
        }

        Text {
            text: "Peuples : "
        }

        ComboBox {
            textRole: "display"
            implicitWidth: 300
            model: quickNavigation.ethnies

            onActivated: { charactersList.filterCharacters("ethnie", currentText) }
        }

        Text {
            text: "Groupes : "
        }

        ComboBox {
            textRole: "display"
            implicitWidth: 300
            model: quickNavigation.groups

            onActivated: charactersList.filterCharacters("group", currentText)
        }
    }
}
