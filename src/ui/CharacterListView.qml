import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Character 1.0

ListView {
    implicitWidth: 1500
    implicitHeight: 880
    clip: true

    model: charactersList.model

    delegate: CharacterView {}
}
