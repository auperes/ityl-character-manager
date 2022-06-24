import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: avatarView
    property url source
    RowLayout {
        Image {
            source: avatarView.source
            Layout.preferredHeight: avatarView.height
            Layout.preferredWidth: avatarView.width
            clip: true
            fillMode: Image.PreserveAspectCrop
        }
    }
}
