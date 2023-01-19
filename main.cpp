#include <QtCore/QUrl>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtWebView/QtWebView>

int main(int argc, char *argv[])
{
    QtWebView::initialize();
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(QCoreApplication::translate("main", "QtWebView Example"));
    QString str = QUuid::createUuid().toString();
    str.remove(QRegularExpression("{|}|-"));
//    qDebug() << str;
//    const QString initialUrl = QStringLiteral("https://meet.jit.si/TestMeet_%1#userInfo.displayName=\"TestUser_1\"").arg(str);

    const QString initialUrl = QStringLiteral("https://lqnlrp8i.kv.koord.live:30560/video#userInfo.displayName=\"thinkpaddan\"").arg(str);

    qInfo() << "URL: " << initialUrl;
    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty(QStringLiteral("initialUrl"), initialUrl);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
