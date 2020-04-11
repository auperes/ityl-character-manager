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

    Component {
        id: tabComponent
        TabBarComponent {

        }
    }

    Component {
        id: tabContentComponent
        CharacterListView {
            anchors.fill: parent
            leftMargin: 20
            rightMargin: 20
        }
    }

    header: ToolBar {
        RowLayout {
            ToolButton {
                text: qsTr("Reload")
                onClicked: { charactersManager.refreshCharacters() }
            }

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
            id: tabBarView
            width: parent.width
            currentIndex: tabs.currentIndex
            signal actionOccured(string message)

            Connections {
                target: tabBarView
                function onActionOccured(message) {
                    tabBarView.addItem(tabComponent.createObject(tabBarView, { text: message }))
                    tabBarView.setCurrentIndex(tabBarView.count - 1)
                }
            }

            TabBarComponent {
                text: qsTr("Home")
            }
            TabBarComponent {
                text: qsTr("All characters")
            }
        }

        StackLayout {
            id: tabs
            currentIndex: tabBarView.currentIndex
            signal actionOccured(string message)
            signal addEthnieTabOccured(string ethnie)

            Connections {
                target: tabs
                function onActionOccured(message) {
                    tabs.children.push(tabContentComponent.createObject(tabs))
                }
                function onAddEthnieTabOccured(ethnie) {
                    var tab = tabContentComponent.createObject(tabs);
                    tab.model = charactersManager.addCollection("ethnie", ethnie).model
                    tabs.children.push(tab)
                }
            }

            Item {
                id: homeTab
                HomeView {
                    anchors.fill: parent
                    Component.onCompleted: {
                        doSomething.connect(tabBarView.actionOccured)
                        doSomething.connect(tabs.actionOccured)
                        addEthnieTab.connect(tabBarView.actionOccured)
                        addEthnieTab.connect(tabs.addEthnieTabOccured)
                    }
                }
            }

            Item {
                id: allCharactersTab
                CharacterListView {
                    anchors.fill: parent
                    leftMargin: 20
                    rightMargin: 20
                    model: charactersManager.addCollection("Tous", "").model
                }
            }
        }
    }
}
