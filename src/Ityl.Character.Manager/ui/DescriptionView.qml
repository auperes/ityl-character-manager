import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
