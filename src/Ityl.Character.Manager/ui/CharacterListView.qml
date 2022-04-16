import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ListView {
    clip: true
    spacing: 10
    ScrollBar.vertical: ScrollBar {
        policy: "AlwaysOn"
    }

    delegate: CharacterView {}
}
