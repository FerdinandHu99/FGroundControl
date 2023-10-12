import QtQuick 2.15
import QtWebEngine 1.9

import Controls 1.0

Item {
    id: _root
    property Item pipState: _pipState
    FGCPipState {
        id:         _pipState
        pipOverlay: _pipOverlay
    }
    WebEngineView {
        id: webView
        anchors.fill: parent // 填充整个父项
        url: "file:///D:/Qt_Projects/FGroundControl/map.html"
    }
}
