import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 1300
    height: 920
    title: qsTr("Hello World")

    CharacterListView {
        anchors.centerIn: parent
    }
}
