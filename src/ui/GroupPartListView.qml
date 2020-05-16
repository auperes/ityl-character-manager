import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    implicitHeight: groupPartsList.implicitHeight
    ListView {
        id: groupPartsList
        model: display.parts
        implicitHeight: contentHeight
        spacing: 30
        delegate: GroupPartView {}
    }
}
