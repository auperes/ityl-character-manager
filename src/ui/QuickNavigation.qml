import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Character 1.0

Item {
    RowLayout {
        Text {
            text: "Peuples : "
        }

        ComboBox {
            implicitWidth: 300
            model: ethniesList

            onActivated: { charactersList.filterCharacters("ethnie", currentText) }
        }

        Text {
            text: "Groupes : "
        }

        ComboBox {
            implicitWidth: 300
            model: groupsList

            onAccepted: charactersList.filterCharacters("group", currentText)
        }
    }
}
