import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import "MaterialIcons.js" as MdiFont

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
            closeButtonVisible: true

            onClosedTab: {
                var index = TabBar.index;
                tabBarView.removeItem(this)
                tabContentUiCollection.removeGroup(index - 1)
            }
        }
    }

    Component {
        id: tabContentGroupComponent
        GroupView {
        }
    }

    FontLoader {
        id: materialFont
        source: "qrc:/ui/materialdesignicons-webfont.ttf"
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
                text: MdiFont.Icon.sync
                font.family: materialFont.name
                font.pointSize: 14
                ToolTip.text: qsTr("Reload data")
                ToolTip.visible: hovered
                ToolTip.delay: 1000
                onClicked: { charactersManager.refreshCharacters() }
            }

            ToolButton {
                text: MdiFont.Icon.cog
                font.family: materialFont.name
                font.pointSize: 14
                ToolTip.text: qsTr("Load new App Settings File")
                ToolTip.visible: hovered
                ToolTip.delay: 1000
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
                text: MdiFont.Icon.home
                font.family: materialFont.name
                font.pointSize: 14
                closeButtonVisible: false
            }
        }

        StackLayout {
            id: tabContent
            currentIndex: tabBarView.currentIndex

            Connections {
                target: homeView
                function onElementSelected(elementType, elementName) {
                    tabContentUiCollection.addGroup(elementName)
                }
            }

            Item {
                id: homeTab
                HomeView {
                    anchors.fill: parent
                }
            }

            Repeater {
                model: tabContentUiCollection
                delegate: GroupView {
                }
            }
        }
    }
}
