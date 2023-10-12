import QtQuick 2.15
import Controls 1.0

Item {
    id: _root
    anchors.fill: parent

    FlyViewMap {
        id: mapControl
    }

    FlyViewVideo {
        id: videoControl
    }

    FGCPipOverlay {
        id:                     _pipOverlay
        anchors.left:           parent.left
        anchors.bottom:         parent.bottom
        anchors.margins:        8
        item1:                  mapControl
        item2:                  videoControl
        fullZOrder:             0
        pipZOrder:              1
        show:                   true
    }
}
