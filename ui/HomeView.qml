import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    anchors.fill: parent
    GridLayout {
        anchors.fill: parent
        columns: 6
        // row 0
        Item {
            width: 50
        }
        Frame {
            Text {
                text: qsTr("Askash")
            }
        }
        Frame {
            Text {
                text: qsTr("Hystiam")
            }
        }
        Frame {
            Text {
                text: qsTr("Oskah")
            }
        }
        Frame {
            Text {
                text: qsTr("Saïni")
            }
        }
        Frame {
            Text {
                text: qsTr("Zherkum")
            }
        }

        // row1
        ListModel {
            id: askashRegions
            ListElement {
                name: "Senya, les montagnes interdites"
            }
            ListElement {
                name: "Lhume, l'île des rêves"
            }
            ListElement {
                name: "Jhor, la montagne du tonnerre"
            }
            ListElement {
                name: "Leatsu, le bosquet noir"
            }
            ListElement {
                name: "Les terres brisées"
            }
        }


        Frame {
            Text {
                text: qsTr("Régions")
            }
        }
        Frame {
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            ListView {
                id: askashRegionsList
                anchors.fill: parent
                model: askashRegions
                delegate: Text {
                    text: name
                }
            }
        }
        Frame {
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            ListView {
                id: askashRegionsList2
                anchors.fill: parent
                model: askashRegions
                delegate: Text {
                    text: name
                }
            }
        }
        Frame {
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            ListView {
                id: askashRegionsList3
                anchors.fill: parent
                model: askashRegions
                delegate: Text {
                    text: name
                }
            }
        }
        Frame {
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            ListView {
                id: askashRegionsList4
                anchors.fill: parent
                model: askashRegions
                delegate: Text {
                    text: name
                }
            }
        }
        Frame {
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            ListView {
                id: askashRegionsList5
                anchors.fill: parent
                model: askashRegions
                delegate: Text {
                    text: name
                }
            }
        }
    }
}
