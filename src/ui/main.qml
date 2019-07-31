import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Window {
    visible: true
    visibility: Window.Maximized
    minimumWidth: 1300
    minimumHeight: 920
    title: qsTr("Ityl characters viewer")

    CharacterListView {
        anchors.centerIn: parent
        anchors.fill: parent
    }
}
