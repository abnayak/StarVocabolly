#ifndef FREESTUDYTAB_H
#define FREESTUDYTAB_H

#include <QTabWidget>
#include <QSqlTableModel>
#include <QtSql>
#include <QSplitter>
#include <QTableView>
#include <QSqlTableModel>
#include <QTextEdit>
#include <QWidget>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QSortFilterProxyModel>
#include <QHeaderView>
//#include <freeStudy.h>

class freeStudyTab:public QTabWidget
{
    Q_OBJECT
private:
     //freeStudy *freestudy;
     QSqlTableModel *model;
     QSplitter *splitter;
     QTextEdit *description;
     QTableView *wordTable;
     QVBoxLayout *layout;
     QSortFilterProxyModel *filter;

      void FreeStudyaddTabs(QString);
private slots:
      void wordSelected(QModelIndex );
public:
     freeStudyTab(QTabWidget *parent=0);
};

#endif // FREESTUDYTAB_H
