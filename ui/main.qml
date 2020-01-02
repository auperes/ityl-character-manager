import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow
    visible: true
    visibility: Window.Maximized
    minimumWidth: 1300
    minimumHeight: 500
    title: qsTr("Ityl characters viewer")

    header: ToolBar {
        RowLayout {
            ToolButton {
                text: qsTr("Search")
            }
            ToolButton {
                text: qsTr("Compact")
            }
            ToolButton {
                text: qsTr("Detailed")
            }
            ToolButton {
                text: qsTr("Notifications")
            }
            ToolButton {
                text: qsTr("Options")
            }
            ToolButton {
                text: qsTr("About")
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent

        TabBar {
            id: tabBar
            width: parent.width
            TabButton {
                width: implicitWidth
                text: qsTr("Home")
            }
            TabButton {
                width: implicitWidth
                text: qsTr("All characters")
            }
        }

        StackLayout {
            currentIndex: tabBar.currentIndex

            Item {
                id: homeTab
                HomeView {
                    anchors.fill: parent
                }
            }

            Item {
                id: allCharactersTab
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
        }
    }
}
