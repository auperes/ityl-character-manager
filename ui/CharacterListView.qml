import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Character 1.0

ListView {
    clip: true
    spacing: 10
    ScrollBar.vertical: ScrollBar {
        policy: "AlwaysOn"
    }

    model: charactersList.model

    delegate: CharacterView {}
}
