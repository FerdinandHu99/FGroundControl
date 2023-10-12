import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtWebEngine 1.9

import FGroundControl 1.0
import FlightDisplay 1.0

ApplicationWindow {
    width: Math.min(250 * Screen.pixelDensity, Screen.width)
    height: Math.min(150 * Screen.pixelDensity, Screen.height)
    visible: true
    title: qsTr("FGroundControl")
    Component.onCompleted: {
        console.log(width, height)
        console.log(FGroundControl.appName)
    }
    header: Item {
        height: 40
    }

    FlyView {

    }
}

