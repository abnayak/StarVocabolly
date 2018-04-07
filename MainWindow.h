#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <freeStudyTab.h>
#include <flashStudyTab.h>
#include <DockButton.h>
#include <QMainWindow>
#include <QDockWidget>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QObject>
#include <QStackedWidget>
#include <QToolBar>
#include <QToolButton>

class MainWindow:public QMainWindow
{
    Q_OBJECT
private:
    QStackedWidget *stackedWidget;
    freeStudyTab *freestudytab;
    flashStudyTab *flashstudytab;
    QDockWidget *dock;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *exitAction;
    QAction *about;
    QAction *aboutQt;
    QAction *Help;
    QToolBar *toolBar;
    QAction *addDatabase;
    QToolButton *verticalView;
    QToolButton *horizontalView;
    DockButton *dockButton;

public:
    MainWindow(QMainWindow *parent=0);
    void setMenuBar();
    void setToolBar();
private slots:
    void closeVocabolly();
    void freeStudyAction(int);
    void flashStudyAction(int);
};

#endif // MAINWINDOW_H
