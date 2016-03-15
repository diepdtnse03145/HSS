import QtQuick 2.3
import QtQuick.Controls 1.2
import QtWebView 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    WebView {
        id: webview
        url: "http://admin1:admin2@192.168.125.51/ViewerFrame?Resolution=320x240&Quality=Standard&Size=STD&Language=0&Sound=Enable&Mode=JPEG&RPeriod=65535&SendMethod=1&View=Full"
        anchors.fill: parent
    }

}
