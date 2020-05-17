import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    implicitHeight: groupPartsList.implicitHeight
    implicitWidth:  parent.width

    ListView {
        id: groupPartsList
        model: display.parts
        anchors.fill: parent
        implicitHeight: contentHeight
        implicitWidth: parent.width
        spacing: 30
        delegate: GroupPartView {}
    }
}
