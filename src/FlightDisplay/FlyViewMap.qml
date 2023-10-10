import QtQuick 2.15
import QtWebEngine 1.9

Item {
    WebEngineView {
        id: webView
        anchors.fill: parent // 填充整个父项
        url: "file:///D:/Qt_Projects/FGroundControl/map.html"
    }
}
