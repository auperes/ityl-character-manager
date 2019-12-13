import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

import Character 1.0

Item {
    RowLayout {
        Image {
            source: model.display.avatar
        }
    }
}
