import QtQuick 2.15


Item {
    id: _root
    anchors.fill: parent

    FlyViewMap {
        anchors.fill: parent;
    }

    FlyViewVideo {
        anchors.left: parent.left
        anchors.bottom: parent.bottom
    }
}
