#include <freeStudyTab.h>
#include <MainWindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    /*freeStudyTab *freestudytab;
    freestudytab =  new freeStudyTab();
    freestudytab->show();*/
    MainWindow *mainWindow;
    mainWindow = new MainWindow();
    mainWindow->show();

    return app.exec();
}
