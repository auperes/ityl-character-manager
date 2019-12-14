import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Window {
    id: mainWindow
    visible: true
    visibility: Window.Maximized
    minimumWidth: 1300
    minimumHeight: 500
    title: qsTr("Ityl characters viewer")

    ColumnLayout {
        anchors.fill: parent

        QuickNavigation {
            Layout.leftMargin: 20
            Layout.fillWidth: true
            Layout.preferredHeight: 50
        }

        CharacterListView {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 20
            Layout.rightMargin: 20
        }
    }
}
