// #include "info.h"
// #include "ui_info.h"
// info::info(QVector<user>& users ,QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::info)
// {
//     ui->setupUi(this);
//     ui->tableWidget->setRowCount(users.size());
//     for (int i=0 ;i<users.size();i++)
//     {
//         ui->tableWidget->setItem(i , 0 , new QTableWidgetItem(users[i].getfirstname()));
//         ui->tableWidget->setItem(i , 1 , new QTableWidgetItem(users[i].getlastname()));
//         ui->tableWidget->setItem(i , 2 , new QTableWidgetItem(users[i].getphonenumber()));
//         ui->tableWidget->setItem(i , 3 , new QTableWidgetItem(users[i].getsessions()));
//     }
// }

// info::~info()
// {
//     delete ui;
// }
