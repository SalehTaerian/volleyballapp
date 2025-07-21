#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include<QQmlContext>
#include "user.h"
// #include<iostream>
// #include<string>
using namespace std;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    user userobj;
    const QUrl url(QStringLiteral("qrc:/volleyball/main.qml"));
    engine.rootContext()->setContextProperty("userfunc" , &userobj);
    engine.load(QUrl(u"qrc:/volleyball/main.qml"_qs));
    // engine.load(url);
    return app.exec();
}
