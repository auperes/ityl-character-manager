import QtQuick 2.0
import QtQuick.Layouts 1.12

Item {
    GridLayout {
        columns: 2

        ColumnLayout {
            Text {
                font.bold: true
                text: "Régions"
            }

            ListView {
                id: regionsList
                Layout.preferredHeight: contentHeight
                Layout.fillHeight: true
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.regions
                delegate: LinkButton {
                    text: modelData
//                    Component.onCompleted: buttonClicked.connect(homeViewUi.doSomething)
                }
            }
        }

//        ColumnLayout {
//            Text {
//                font.bold: true
//                text: "Peuples"
//            }

//            ListView {
//                id: ethniesList
//                Layout.preferredHeight: contentHeight
//                Layout.preferredWidth: 300
//                spacing: 5
//                model: homeView.selectedCategory.ethnies
//                delegate: LinkButton {
//                    text: modelData
////                    Component.onCompleted: buttonClicked.connect(homeViewUi.doSomething)
//                }
//            }
//        }

        ColumnLayout {
            Text {
                font.bold: true
                text: "Organisations"
            }

            ListView {
                id: organizationsList
                Layout.preferredHeight: contentHeight
                Layout.preferredWidth: 300
                spacing: 5
                model: homeView.selectedCategory.organizations
                delegate: LinkButton {
                    text: modelData
//                    Component.onCompleted: buttonClicked.connect(homeViewUi.doSomething)
                }
            }
        }
    }
}
