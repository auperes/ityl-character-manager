import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

ApplicationWindow {
    id: mainWindow
    visible: true
    visibility: Window.Maximized
    minimumWidth: 1300
    minimumHeight: 500
    title: qsTr("Ityl characters viewer")

    Component {
        id: tabComponent
        TabBarComponent {}
    }

    Component {
        id: tabContentCharacterComponent
        CharacterListView {
            leftMargin: 20
            rightMargin: 20
        }
    }

    Component {
        id: tabContentGroupComponent
        GroupView {
        }
    }

    FileDialog {
        id: settingsFileDialog
        title: "Choose a settings file"
        onAccepted: {
            settingsManager.changeSettings(selectedFile.toString())
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
                    var groupUiView = groupsManager.addGroup(elementName);
                    var tab =  groupUiView === null
                            ? tabContentCharacterComponent.createObject(tabContent, { model: charactersManager.addCollection(elementType, elementName).model })
                            : tabContentGroupComponent.createObject(tabContent, { groupUiView: groupUiView });
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
