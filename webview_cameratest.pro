TEMPLATE = app
TARGET = webview_cameratest

QT += qml quick webview

SOURCES += main.cpp

RESOURCES += qml.qrc

macos:QMAKE_INFO_PLIST = macos/Info.plist
#ios:QMAKE_INFO_PLIST = ios/Info.plist

target.path = $HOME/webview_cameratest
INSTALLS += target
