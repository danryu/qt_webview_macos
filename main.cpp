
#include <QtCore/QUrl>
#include <QGuiApplication>
#include <QStyleHints>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtWebView/QtWebView>
//#include <QSslSocket>

class Utils : public QObject {
    Q_OBJECT
public:
    Utils(QObject *parent = nullptr) : QObject(parent) { }
};

#include "main.moc"

int main(int argc, char *argv[])
{
//! [0]
    QtWebView::initialize();
    QGuiApplication app(argc, argv);
//! [0]
    QGuiApplication::setApplicationDisplayName(QCoreApplication::translate("main", "QtWebView Example"));
    QString str = QUuid::createUuid().toString();
    str.remove(QRegularExpression("{|}|-"));
    qDebug() << str;

    const QString initialUrl = QStringLiteral("https://meet.jit.si/TestMeet_%1#userInfo.displayName=\"TestUser_1\"").arg(str);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty(QStringLiteral("initialUrl"), initialUrl);

//    qDebug() << "Support SSL:  " << QSslSocket::supportsSsl()
//            << "\nLib Version Number: " << QSslSocket::sslLibraryVersionNumber()
//            << "\nLib Version String: " << QSslSocket::sslLibraryVersionString()
//            << "\nLib Build Version Number: " << QSslSocket::sslLibraryBuildVersionNumber()
//            << "\nLib Build Version String: " << QSslSocket::sslLibraryBuildVersionString();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
