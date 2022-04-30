import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    ColumnLayout {
        AvatarView {
            Layout.preferredHeight: 100
            Layout.preferredWidth: 100
            source: model.display.miniAvatar
        }

        //TODO: link button to handle event (new tab with character details)
        Text {
            text: model.display.fullName
        }
    }
}
