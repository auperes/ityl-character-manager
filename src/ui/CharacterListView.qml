import QtQuick 2.12
import QtQuick.Controls 2.12

import Character 1.0

ListView {
    implicitWidth: 1500
    implicitHeight: 880
    anchors.fill: parent
    clip: true

    model: CharacterModel {
        characters: charactersList
    }

    delegate: CharacterView {}
}
