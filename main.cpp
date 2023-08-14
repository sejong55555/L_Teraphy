#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "Viewer.h"
#include "Viewer1.h"
#include "Viewer2.h"
#include "Viewer3.h"
#include "Viewer4.h"
#include "cvtopng.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<Viewer>("Viewer", 1, 0, "Viewer");
    qmlRegisterType<Viewer1>("Viewer1", 1, 0, "Viewer1");
    qmlRegisterType<Viewer2>("Viewer2", 1, 0, "Viewer2");
    qmlRegisterType<Viewer3>("Viewer3", 1, 0, "Viewer3");
    qmlRegisterType<Viewer4>("Viewer4", 1, 0, "Viewer4");
    CVtoPNG png; //temp

    QQmlApplicationEngine engine;


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
