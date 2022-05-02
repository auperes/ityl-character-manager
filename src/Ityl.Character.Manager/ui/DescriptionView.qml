import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Component {
    ScrollView {
        id: descriptionView
        clip: true
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Flickable {
            contentHeight: descriptionContent.height
            clip: true
        Text {
            id: descriptionContent
            width: detailedView.width
            text: model.display.description
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignJustify
        }
        }
    }
}
