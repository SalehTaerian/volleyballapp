#include <QGuiApplication>
#include<QApplication>

#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include<QQmlContext>
#include "user.h"
#include"handleuser.h"
// #include<iostream>
// #include<string>
// #include"info.h"
static handleuser *handleuser_singletontype(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return new handleuser();
}
using namespace std;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    handleuser *HandleUser = handleuser_singletontype(&engine , nullptr);
    HandleUser->readFromDatabase();
    HandleUser->showusers();
    qDebug()<<HandleUser->getNumberOfUser();
    QVector<user> mainusers  =HandleUser->getuser();
    qmlRegisterSingletonInstance<handleuser>("MyApp.HandleUser", 1, 0, "HandleUser" ,HandleUser);
    // info *infopage = new info(mainusers);
    // qmlRegisterSingletonInstance<info>("MyApp.infopage", 1, 0, "infopage" ,infopage);
    // const QUrl url(QStringLiteral("qrc:/volleyball/main.qml"));
    engine.load(QUrl(u"qrc:/volleyball/main.qml"_qs));
    // engine.load(url);
    return app.exec();
}
