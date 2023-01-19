
import QtQuick
import QtQuick.Controls
import QtWebView
import QtQuick.Layouts


ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: webView.title

    WebView {
        id: webView
        anchors.fill: parent
        url: initialUrl
        onLoadingChanged: function(loadRequest) {
            if (loadRequest.errorString)
                console.error(loadRequest.errorString);
        }
    }
}
