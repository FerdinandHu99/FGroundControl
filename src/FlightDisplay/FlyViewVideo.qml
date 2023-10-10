import QtQuick 2.15

Item {
    id: _root
    width: 200
    height: width * 9 / 16
    Image {
        id:             noVideo
        anchors.fill:   parent
        source:         "qrc:/res/NoVideoBackground.jpg"
        fillMode:       Image.PreserveAspectCrop
    }
}
