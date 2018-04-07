#include <QtSql>
#include <QMessageBox>
#include <QObject>

QSqlDatabase db;

bool dbConnect(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db/vocabolly");

    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Connection Error"),
                              QObject::tr("Failed to connect to the database"),
                              QMessageBox::Cancel
                              );
        return false;
    }
    return true;
}
