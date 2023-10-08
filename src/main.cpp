#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine/QtWebEngine>

#include "FGroundControlQmlGlobal.h"

static QObject* fgroundcontrolQmlGlobalSingletonFactory(QQmlEngine*, QJSEngine*);

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("FGroundControl");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QtWebEngine::initialize();
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<FGroundControlQmlGlobal>("FGroundControl", 1, 0, "FGroundControl", fgroundcontrolQmlGlobalSingletonFactory);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/src/main.qml")));


    return app.exec();
}

static QObject* fgroundcontrolQmlGlobalSingletonFactory(QQmlEngine*, QJSEngine*)
{
    FGroundControlQmlGlobal* qmlGlobal = new FGroundControlQmlGlobal();
    return qmlGlobal;
}
