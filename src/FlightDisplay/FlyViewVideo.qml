import QtQuick 2.15
import Controls 1.0

Item {
    id: _root
    width: 200
    height: width * (9/16)

    property Item pipState: videoPipState
    FGCPipState {
        id:         videoPipState
        pipOverlay: _pipOverlay
        isDark:     true

        onWindowAboutToOpen: {
//            QGroundControl.videoManager.stopVideo()
//            videoStartDelay.start()
        }

        onWindowAboutToClose: {
//            QGroundControl.videoManager.stopVideo()
//            videoStartDelay.start()
        }

        onStateChanged: {
//            if (pipState.state !== pipState.fullState) {
//                QGroundControl.videoManager.fullScreen = false
//            }
        }
    }

    Image {
        id:             noVideo
        anchors.fill:   parent
        source:         "qrc:/res/NoVideoBackground.jpg"
        fillMode:       Image.PreserveAspectCrop
    }
}
