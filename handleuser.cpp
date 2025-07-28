#include "handleuser.h"
#include<QDir>
#include<QStandardPaths>
#include<QCoreApplication>
handleuser::handleuser() {
    if (!QSqlDatabase::contains("main_connection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
        QString path = QCoreApplication::applicationDirPath();
        QString dbPath = path + "/userdb.db";

        QDir pathtemp;
        if (!pathtemp.exists(path)) {
            qDebug() << "moshkel masir!" << path;
        }

        db.setDatabaseName(dbPath);
        if (!db.open()) {
            qDebug() << "db didn't open!" << db.lastError().text();
            return;
        }
        QSqlQuery q(db);
        bool ok = q.exec(R"(
            CREATE TABLE IF NOT EXISTS userdatabase (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                firstname   TEXT NOT NULL COLLATE NOCASE,
                lastname    TEXT NOT NULL COLLATE NOCASE,
                phonenumber TEXT NOT NULL COLLATE NOCASE,
                date        TEXT NOT NULL COLLATE NOCASE,
                sessions    INTEGER NOT NULL COLLATE NOCASE
            )
        )");
        if (!ok) {
            qDebug() << "Failed to (re)create table:" << q.lastError().text();
        }
    }
}
void handleuser::addUser(QString firstname , QString lastname , QString phonenumber , QString date , int sessions)
{
    user userobj(firstname , lastname , phonenumber , date , sessions);
    users.push_back(userobj);
}
void handleuser::deleteUser(user& userobj)
{
    users.removeOne(userobj);
}
// void handleuser::editUser(user userobj)
// {
    
// }
// void handleuser::connectToDb()
// {
//     QSqlDatabase db = QSqlDatabase::addDatabase("SQLITE");
//     QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
//     QString dbPath = path + "/userdb.db";
//     db.setDatabaseName(dbPath);
//     if(!db.open())
//     {
//         qDebug()<<"db didn't open!";
//     }
// }
void handleuser::inserttodb()
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    if (!db.isOpen()) {
        qDebug() << "DB did not open!";
        return;
    }
    QString firstname =users.last().getfirstname();
    QString lastname =users.last().getlastname();
    QString phonenumber =users.last().getphonenumber();
    QString date =users.last().getnewdate();
    int sessions =users.last().getsessions();
    QSqlQuery query(db);
    query.prepare("INSERT INTO userdatabase(firstname, lastname , phonenumber , date , sessions) VALUES(:firstname, :lastname , :phonenumber , :date , :sessions)");
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    query.bindValue(":phonenumber", phonenumber);
    query.bindValue(":date", date);
    query.bindValue(":sessions", sessions);
    if (!query.exec())
    {
        qDebug() << "Insert error:" << query.lastError().text()<<firstname<<lastname<<date<<phonenumber<<sessions;
    }
    else
    {
        qDebug() << "Insert success!";
    }
}
void handleuser::showusers()
{
    readFromDatabase();
    for(auto it = users.begin();it!=users.end();it++)
    {
        qDebug()<<it->getfirstname();
        qDebug()<<it->getlastname();
        qDebug()<<it->getphonenumber();
        qDebug()<<it->getnewdate();
        qDebug()<<it->getsessions();
    }
}
void handleuser::readFromDatabase()
{
    users.clear();
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    if(!query.exec("SELECT firstname, lastname, phonenumber, date, sessions FROM userdatabase"))
    {
        qDebug()<<"could'nt excute!";
    }
    while(query.next())
    {
        QString firstname = query.value(0).toString();
        QString lastname = query.value(1).toString();
        QString phonenumber = query.value(2).toString();
        QString date = query.value(3).toString();
        int sessions = query.value(4).toInt();
        users.push_back(user(firstname , lastname , phonenumber , date , sessions));
    }
}
