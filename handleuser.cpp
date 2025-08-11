#include "handleuser.h"
#include<QDir>
#include<QStandardPaths>
#include<QCoreApplication>
#include<QCalendar>
handleuser::handleuser()
{
    holidays = {
        "1404/01/02",
        "1404/01/03",
        "1404/01/04",
        "1404/01/11",
        "1404/01/12",
        "1404/01/13",
        "1404/02/04",
        "1404/03/14",
        "1404/03/15",
        "1404/03/24",
        "1404/04/14",
        "1404/04/15",
        "1404/05/23",
        "1404/05/31",
        "1404/06/02",
        "1404/06/10",
        "1404/06/19",
        "1404/09/03",
        "1404/10/13",
        "1404/10/27",
        "1404/11/15",
        "1404/11/22",
        "1404/12/20"
    };
    if (!QSqlDatabase::contains("main_connection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
        QString path = QCoreApplication::applicationDirPath();
        QString dbPath = path + "/userdb.db";

        QDir pathtemp;
        if (!pathtemp.exists(path)) {
            qDebug() << "moshkel masir!" << path;
        }
        qDebug()<<path;
        db.setDatabaseName(dbPath);
        if (!db.open()) {
            qDebug() << "db didn't open!" << db.lastError().text();
            return;
        }
        QSqlQuery q(db);
        bool ok = q.exec(R"(
            CREATE TABLE IF NOT EXISTS userdatabase (
                id INTEGER PRIMARY KEY,
                firstname   TEXT NOT NULL COLLATE NOCASE,
                lastname    TEXT NOT NULL COLLATE NOCASE,
                phonenumber TEXT NOT NULL COLLATE NOCASE,
                firstsession TEXT NOT NULL COLLATE NOCASE,
                date        TEXT NOT NULL COLLATE NOCASE,
                sessions    INTEGER NOT NULL COLLATE NOCASE,
                days        INTEGER NOT NULL
            )
        )");
        if (!ok) {
            qDebug() << "Failed to (re)create table:" << q.lastError().text();
        }
    }
}
int handleuser::whichDay(QDate date)
{
    int roozHafteh =date.dayOfWeek();
    return roozHafteh;
}
QDate handleuser::convertToQDate(QString date)
{
    QString sYear = date.mid(0 ,4);
    QString sMonth = date.mid(5 ,2);
    QString sDay = date.mid(8 ,2);
    int year = sYear.toInt();
    int month = sMonth.toInt();
    int day = sDay.toInt();
    QCalendar jalali(QCalendar::System::Jalali);
    QDate Date = jalali.dateFromParts(year, month , day);
    return Date;
}
QVector<user> handleuser::getuser()
{
    return users;
}
void handleuser::addUser(QString firstname , QString lastname , QString phonenumber ,QString firstsession , QString date , int sessions ,int days)
{
    user userobj(firstname , lastname , phonenumber , firstsession ,  date , sessions , days);
    users.push_back(userobj);
}
int handleuser::deleteUser(QString firstname , QString lastname)
{
    int flag=0;
    for (auto it = users.begin();it!=users.end();)
    {
        if(it->getfirstname()==firstname)
        {
            if(it->getlastname()==lastname)
            {
            it = users.erase(it);
            deleteUserFromDb(it->getphonenumber());
            flag=1;
            }
        }
        else
        {
            it++;
        }
    }
    return flag;
}
void handleuser::deleteUserFromDb(QString phonenumber)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return;
    }
    QSqlQuery query(db);
    query.prepare("DELETE FROM userdatabase WHERE phonenumber = :phonenumber");
    query.bindValue(":phonenumber", phonenumber);
    if (!query.exec()) {
        qDebug() << "Delete error:" << query.lastError().text();
    } else {
        qDebug() << "User with phone number" << phonenumber << "deleted.";
    }
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
void handleuser::inserttodb(QString firstname , QString lastname , QString phonenumber ,QString firstsession , QString date , int sessions ,int days)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    if (!db.isOpen()) {
        qDebug() << "DB did not open!";
        return;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO userdatabase(firstname, lastname , phonenumber , firstsession , date , sessions , days) VALUES(:firstname, :lastname , :phonenumber , :firstsession , :date , :sessions , :days)");
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    query.bindValue(":phonenumber", phonenumber);
    query.bindValue(":firstsession", firstsession);
    query.bindValue(":date", date);
    query.bindValue(":sessions", sessions);
    query.bindValue(":days", days);
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
    // readFromDatabase();
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
    if(!query.exec("SELECT firstname, lastname, phonenumber, firstsession , date, sessions , days FROM userdatabase"))
    {
        qDebug()<<"could'nt excute!";
    }
    while(query.next())
    {
        QString firstname = query.value(0).toString();
        QString lastname = query.value(1).toString();
        QString phonenumber = query.value(2).toString();
        QString firstsession = query.value(3).toString();
        QString date = query.value(4).toString();
        int sessions = query.value(5).toInt();
        int days = query.value(6).toInt();
        users.push_back(user(firstname , lastname , phonenumber , firstsession ,  date , sessions , days));
    }
    query.clear();
}
QString handleuser::getUser(int index  , int item)
{
    if(item==0)
    {
        return users[index].getfirstname();
    }
    else if(item==1)
    {
        return users[index].getlastname();
    }
    else if(item==2)
    {
        return users[index].getfirstsession();
    }
    else if(item==3)
    {
        return users[index].getnewdate();
    }
    else if(item==4)
    {
        return users[index].getdays();
    }
}
int handleuser::getNumberOfUser()
{
    return users.size();
}
QString handleuser::convertToLastDatDay1(QString firstDate , int sessions)
{
    QString sYear = firstDate.mid(0 ,4);
    QString sMonth = firstDate.mid(5 ,2);
    QString sDay = firstDate.mid(8 ,2);
    int year = sYear.toInt();
    int month = sMonth.toInt();
    int day = sDay.toInt();
    QCalendar jalali(QCalendar::System::Jalali);
    QDate firstStep = jalali.dateFromParts(year, month , day);
    QDate firstSession = firstSundayOrTuesday(firstStep);
    // 26 baraye sishanbeh
    // 23 baraye yeshabeh
    int roozHafteh = firstSession.dayOfWeek();
    QDate lastSession;
    if(sessions!=1)
    {
    if(roozHafteh==2)
    {
        int dayAfter=0;
        if(sessions%2==0)
        {
            dayAfter  = (sessions/2)*7-2;
        }
        else
        {
            dayAfter  = (sessions/2)*7;
        }
        lastSession = firstSession.addDays(dayAfter);
    }
    else if(roozHafteh==7)
    {
        int dayAfter=0;
        if(sessions%2==0)
        {
            dayAfter  = (sessions/2)*7-5;
        }
        else
        {
            dayAfter  = (sessions/2)*7;
        }
        lastSession = firstSession.addDays(dayAfter);
    }
    }
    else
    {
        lastSession = firstSession;
    }
    int numberOfHolidays =0;
    for (int i=0;i<holidays.size();i++)
    {
        QDate Holday = convertToQDate(holidays[i]);
        if(Holday>=firstSession && Holday<=lastSession)
        {
            if(whichDay(Holday)==7 || whichDay(Holday)==2)
            {
                numberOfHolidays++;
            }
        }
    }
    for (int i=0;i<numberOfHolidays;i++)
    {
        lastSession = lastSession.addDays(1);
        lastSession = firstSundayOrTuesday(lastSession);
    }
    QCalendar shamsi(QCalendar::System::Jalali);
    QCalendar::YearMonthDay ymd = shamsi.partsFromDate(lastSession);
    year = ymd.year;
    month = ymd.month;
    day = ymd.day;
    sYear  = QString::number(year);
    sMonth = QString::number(month);
    sDay  = QString::number(day);
    if(month<10)
    {
        sMonth = "0"+sMonth;
    }
    if(day<10)
    {
        sDay = "0"+sDay;
    }
    QString finalDate = sYear+"/" + sMonth +"/"+ sDay;
    return finalDate;
}
QString handleuser::convertToLastDatDay3(QString firstDate , int sessions)
{
    QString sYear = firstDate.mid(0 ,4);
    QString sMonth = firstDate.mid(5 ,2);
    QString sDay = firstDate.mid(8 ,2);
    int year = sYear.toInt();
    int month = sMonth.toInt();
    int day = sDay.toInt();
    QCalendar jalali(QCalendar::System::Jalali);
    QDate firstStep = jalali.dateFromParts(year, month , day);
    QDate firstSession = firstThursdayOrTuesday(firstStep);
    int roozHafteh = firstSession.dayOfWeek();
    QDate lastSession;
    if(sessions!=1)
    {
        if(roozHafteh==2)
        {
            int dayAfter=0;
            if(sessions%2==0)
            {
                dayAfter  = (sessions/2)*7-5;
            }
            else
            {
                dayAfter  = (sessions/2)*7;
            }
            lastSession = firstSession.addDays(dayAfter);
        }
        else if(roozHafteh==4)
        {
            int dayAfter=0;
            if(sessions%2==0)
            {
                dayAfter  = (sessions/2)*7-2;
            }
            else
            {
                dayAfter  = (sessions/2)*7;
            }
            lastSession = firstSession.addDays(dayAfter);
        }
    }
    else
    {
        lastSession = firstSession;
    }
    int numberOfHolidays =0;
    for (int i=0;i<holidays.size();i++)
    {
        QDate Holday = convertToQDate(holidays[i]);
        if(Holday>=firstSession && Holday<=lastSession)
        {
            if(whichDay(Holday)==2 || whichDay(Holday)==4)
            {
                numberOfHolidays++;
            }
        }
    }
    for (int i=0;i<numberOfHolidays;i++)
    {
        lastSession = lastSession.addDays(1);
        lastSession = firstThursdayOrTuesday(lastSession);
    }
    QCalendar shamsi(QCalendar::System::Jalali);
    QCalendar::YearMonthDay ymd = shamsi.partsFromDate(lastSession);
    year = ymd.year;
    month = ymd.month;
    day = ymd.day;
    sYear  = QString::number(year);
    sMonth = QString::number(month);
    sDay  = QString::number(day);
    QString finalDate = sYear+ "/" + sMonth+ "/" + sDay;
    return finalDate;
}
QString handleuser::convertToLastDatDay2(QString firstDate , int sessions)
{
    QString sYear = firstDate.mid(0 ,4);
    QString sMonth = firstDate.mid(5 ,2);
    QString sDay = firstDate.mid(8 ,2);
    int year = sYear.toInt();
    int month = sMonth.toInt();
    int day = sDay.toInt();
    QCalendar jalali(QCalendar::System::Jalali);
    QDate firstStep = jalali.dateFromParts(year, month , day);
    QDate firstSession = firstSundayOrThursday(firstStep);
    int roozHafteh = firstSession.dayOfWeek();
    QDate lastSession;
    if(sessions!=1)
    {
        if(roozHafteh==4)
        {
            int dayAfter=0;
            if(sessions%2==0)
            {
                dayAfter  = (sessions/2)*7-4;
            }
            else
            {
                dayAfter  = (sessions/2)*7;
            }
            lastSession = firstSession.addDays(dayAfter);
        }
        else if(roozHafteh==7)
        {
            int dayAfter=0;
            if(sessions%2==0)
            {
                dayAfter  = (sessions/2)*7-3;
            }
            else
            {
                dayAfter  = (sessions/2)*7;
            }
            lastSession = firstSession.addDays(dayAfter);
        }
    }
    else
    {
        lastSession = firstSession;
    }
    int numberOfHolidays =0;
    for (int i=0;i<holidays.size();i++)
    {
        QDate Holday = convertToQDate(holidays[i]);
        if(Holday>=firstSession && Holday<=lastSession)
        {
            if(whichDay(Holday)==7 || whichDay(Holday)==4)
            {
                numberOfHolidays++;
            }
        }
    }
    for (int i=0;i<numberOfHolidays;i++)
    {
        lastSession = lastSession.addDays(1);
        lastSession = firstSundayOrThursday(lastSession);
    }
    QCalendar shamsi(QCalendar::System::Jalali);
    QCalendar::YearMonthDay ymd = shamsi.partsFromDate(lastSession);
    year = ymd.year;
    month = ymd.month;
    day = ymd.day;
    sYear  = QString::number(year);
    sMonth = QString::number(month);
    sDay  = QString::number(day);
    QString finalDate = sYear + "/" + sMonth+ "/" + sDay;
    return finalDate;
}
QDate handleuser::firstSundayOrTuesday(QDate &firstStep)
{
    QDate start = firstStep;
    while (true)
    {
        int roozHafteh = start.dayOfWeek();
        if(roozHafteh==2 || roozHafteh==7)
        {
            return start;
        }
        start = start.addDays(1);
    }
}
QDate handleuser::firstSundayOrThursday(QDate &firstStep)
{
    QDate start = firstStep;
    while (true)
    {
        int roozHafteh = start.dayOfWeek();
        if(roozHafteh==4 || roozHafteh==7)
        {
            return start;
        }
        start = start.addDays(1);
    }
}
QDate handleuser::firstThursdayOrTuesday(QDate &firstStep)
{
    QDate start = firstStep;
    while (true)
    {
        int roozHafteh = start.dayOfWeek();
        if(roozHafteh==2 || roozHafteh==4)
        {
            return start;
        }
        start = start.addDays(1);
    }
}
int handleuser::searchUser(QString firstname , QString lastname)
{
    for (int i= 0;i< users.size();i++)
    {
        if(users[i].getfirstname()==firstname && users[i].getlastname()==lastname)
        {
             return i;
        }
    }
    return -1;
}
