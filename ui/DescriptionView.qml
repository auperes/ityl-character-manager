import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Component {
    ScrollView {
        clip: true
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        Text {
            width: detailedView.width
            text: model.display.description
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignJustify
        }
    }
}
