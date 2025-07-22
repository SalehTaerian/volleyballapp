#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include<QQmlContext>
// #include "user.h"
#include"handleuser.h"
// #include<iostream>
// #include<string>
static QObject *handleuser_singletontype(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return new handleuser();  // فقط یک شی ساخته می‌شود
}
using namespace std;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    qmlRegisterSingletonType<handleuser>("MyApp.HandleUser", 1, 0, "HandleUser", handleuser_singletontype);
    // const QUrl url(QStringLiteral("qrc:/volleyball/main.qml"));
    engine.load(QUrl(u"qrc:/volleyball/main.qml"_qs));
    // engine.load(url);
    return app.exec();
}
