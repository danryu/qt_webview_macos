import QtQuick
import QtQuick.Controls
import QtWebView
import QtWebEngine

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: webView.title

    WebEngineView {
        id: webView
        anchors.fill: parent
        url: initialUrl
        onLoadingChanged: function(loadRequest) {
            if (loadRequest.errorString)
                console.error(loadRequest.errorString);
        }
        onFeaturePermissionRequested: {
            grantFeaturePermission(securityOrigin, feature, true);
        }
    }
}
