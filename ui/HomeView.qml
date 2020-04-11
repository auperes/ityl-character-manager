import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: homeView
    anchors.fill: parent
    signal doSomething(string message)
    signal addEthnieTab(string ethnie)

    ListModel {
        id: askash
        ListElement {
            region: "Senya, les montagnes interdites"
            ethnie: "Les perfectionnistes inaltérables"
        }
        ListElement {
            region: "Lhume, l'île des rêves"
            ethnie: "Les tisseurs de rêves"
        }
        ListElement {
            region: "Jhor, la montagne du tonnerre"
            ethnie: "Le peuple foudroyant"
        }
        ListElement {
            region: "Leatsu, le bosquet noir"
            ethnie: "Les quêteurs mystiques"
        }
        ListElement {
            region: "Les terres brisées"
            ethnie: "Les esthètes de l'absolu"
        }
    }

    ListModel {
        id: askashOrganisations
        ListElement {
            organisation: "Les Ednys"
        }
        ListElement {
            organisation: "Les Ednys Izyldrìn"
        }
        ListElement {
            organisation: "Les Ednys Aaliyah"
        }
        ListElement {
            organisation: "Les Ednys Emelren"
        }
        ListElement {
            organisation: "Les Ednys Urùtiem"
        }
        ListElement {
            organisation: "Les Ednys Ordyanôr"
        }
        ListElement {
            organisation: "Les Ednys Hallvardr"
        }
        ListElement {
            organisation: "Les Vahlùrr"
        }
        ListElement {
            organisation: "Cour royale d'Askash"
        }
        ListElement {
            organisation: "Armée d'Askash"
        }
        ListElement {
            organisation: "Les esprits danseurs"
        }
    }

    ListModel {
        id: askashFamilies
        ListElement {
            family: "Lignée Edethiel"
        }
    }

    RowLayout {
        anchors.fill: parent

        Rectangle {
            color: "gray"
            Layout.fillHeight: true
            Layout.preferredWidth: 160

            ColumnLayout {
                id: navigation
                anchors.fill: parent

                Button {
                    Layout.topMargin: 20
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 120
                    text: "Askash"
                }
                Button {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 120
                    text: "Hystiam"
                }
                Button {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 120
                    text: "Oskah"
                }
                Button {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 120
                    text: "Saïni"
                }
                Button {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 120
                    text: "Zherkum"
                }
                Button {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 120
                    text: "Autre"
                }

                Item {
                    Layout.fillHeight: true
                }
            }
        }

        ColumnLayout {
            Layout.topMargin: 20
            Layout.leftMargin: 20
            Layout.alignment: Qt.AlignTop
            RowLayout {
                Layout.bottomMargin: 10

                ColumnLayout {
                    Text {
                        font.bold: true
                        text: "Régions"
                    }

                    ListView {
                        id: askashRegionsList
                        Layout.preferredHeight: contentHeight
                        Layout.preferredWidth: 300
                        spacing: 5
                        model: askash
                        delegate: LinkButton {
                            text: region
                            Component.onCompleted: buttonClicked.connect(homeView.doSomething)
                        }
                    }
                }
                ColumnLayout {
                    Text {
                        font.bold: true
                        text: "Peuples"
                    }

                    ListView {
                        id: askashEthniesList
                        Layout.preferredHeight: contentHeight
                        spacing: 5
                        model: askash
                        delegate: LinkButton {
                            text: ethnie
                            Component.onCompleted: buttonClicked.connect(homeView.addEthnieTab)
                        }
                    }
                }
            }

            Text {
                font.bold: true
                text: "Organisations"
            }

            ListView {
                id: askashOrganisationsList
                Layout.preferredHeight: contentHeight
                Layout.bottomMargin: 10
                spacing: 5
                model: askashOrganisations
                delegate: Text {
                    text: organisation
                }
            }

            Text {
                font.bold: true
                text: "Familles"
            }

            ListView {
                id: askashFamiliesList
                Layout.preferredHeight: contentHeight
                spacing: 5
                model: askashFamilies
                delegate: Text {
                    text: family
                }
            }
        }

        Item {
            Layout.fillWidth: true
        }
    }
}
