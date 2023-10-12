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

        }

        onWindowAboutToClose: {

        }

        onStateChanged: {

        }
    }

}
