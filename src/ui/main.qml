import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.3

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

    FileDialog {
        id: settingsFileDialog
        title: "Choose a settings file"
        onAccepted: {
            settingsManager.changeSettings(fileUrl.toString())
        }
    }

    header: ToolBar {
        RowLayout {
            ToolButton {
                text: qsTr("Reload")
                onClicked: { charactersManager.refreshCharacters() }
            }
            ToolButton {
                text: qsTr("Settings")
                onClicked: { settingsFileDialog.open() }
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent

        TabBar {
            id: tabBarView
            width: parent.width
            currentIndex: tabContent.currentIndex
            signal actionOccured(string message)

            Connections {
                target: homeView
                function onElementSelected(elementType, elementName) {
                    tabBarView.addItem(tabComponent.createObject(tabBarView, { text: elementName }))
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
            id: tabContent
            currentIndex: tabBarView.currentIndex

            Connections {
                target: homeView
                function onElementSelected(elementType, elementName) {
                    var tab = tabContentComponent.createObject(tabContent);
                    tab.model = charactersManager.addCollection(elementType, elementName).model
                    tabContent.children.push(tab)
                }
            }

            Item {
                id: homeTab
                HomeView {
                    anchors.fill: parent
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
