#ifndef FLASHSTUDYTAB_H
#define FLASHSTUDYTAB_H
#include <QTabWidget>
#include <flashStudy.h>

class flashStudyTab:public QTabWidget
{
private:
     flashStudy *flashstudy;
public:
     flashStudyTab(QTabWidget *parent=0);
};

#endif // FLASHSTUDYTAB_H
