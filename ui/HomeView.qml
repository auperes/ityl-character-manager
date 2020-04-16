import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: homeViewUi
    anchors.fill: parent
    signal doSomething(string message)
    signal addEthnieTab(string ethnie)

    RowLayout {
        anchors.fill: parent

        Rectangle {
            color: "gray"
            Layout.fillHeight: true
            Layout.preferredWidth: 160

            ColumnLayout {
                anchors.fill: parent

                ListView {
                    id: navigation
                    Layout.preferredHeight: navigation.count
                    Layout.fillHeight: true
                    Layout.minimumWidth: 120
                    Layout.alignment: Qt.AlignCenter
                    Layout.topMargin: 20

                    model: homeView.categoryNames
                    delegate: Button {
                        implicitWidth: 120
                        text: modelData
                    }
                }
            }
        }

        HomeCategoryView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.topMargin: 20
            Layout.leftMargin: 20
        }
    }
}
