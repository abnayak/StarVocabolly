#include <MainWindow.h>
#include <QSize>
#include <QIcon>
#include <QVBoxLayout>
#include <QDebug>
#include <helper.h>

MainWindow::MainWindow(QMainWindow *parent):QMainWindow(parent)
{
    setMenuBar();
    setToolBar();

    //Setup the dock Window.
    dockButton = new DockButton(this);
    dock = new QDockWidget();
    dock->setWidget(dockButton);
    dock->setFloating(false);
    dock->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable );
    addDockWidget(Qt::LeftDockWidgetArea,dock);

    //setup Central widgets
    freestudytab = new freeStudyTab(); // Check the parent of this widget
    flashstudytab = new flashStudyTab(); // Check the parent of this widget

    connect(dockButton,SIGNAL(freeStudyButtonClicked(int)),this,SLOT(freeStudyAction(int)));
    connect(dockButton,SIGNAL(flashStudyButtonClicked(int)),this,SLOT(flashStudyAction(int)));

    //set central widget
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(freestudytab);
    stackedWidget->addWidget(flashstudytab);
    setCentralWidget(stackedWidget);

    setWindowTitle("Star Vocaboly");
    setWindowIcon(QIcon("icon/star.png"));
    resize(900,600);
}

void MainWindow::setMenuBar()
{

    fileMenu = menuBar()->addMenu(tr("&File"));
    addDatabase = new QAction(this);
    addDatabase->setIcon(QIcon("icon/db.png"));
    addDatabase->setText("Add Word List");
    addDatabase->setShortcut(tr("Ctrl+A"));
    fileMenu->addAction(addDatabase);


    exitAction = new QAction(tr("&Exit"),this);
    exitAction->setIcon(QIcon("icon/exit.png"));
    exitAction->setShortcut(tr("Ctrl+Q"));
    fileMenu->addAction(exitAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));

    Help = new QAction(tr("&Help"),this);
    helpMenu->addAction(Help);
    helpMenu->addSeparator();

    about = new QAction(tr("&About..."),this);
    about->setIcon(QIcon("icon/about.png"));
    helpMenu->addAction(about);
    aboutQt = new QAction(tr("About &Qt..."),this);
    aboutQt->setIcon(QIcon("icon/aboutQt.png"));
    helpMenu->addAction(aboutQt);

    connect(exitAction,SIGNAL(triggered()),this,SLOT(closeVocabolly()));
    connect(aboutQt,SIGNAL(triggered()),qApp,SLOT(aboutQt ()));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(closeVocabolly()));
}
void MainWindow::setToolBar()
{
    toolBar = addToolBar(tr("Main Tools"));
    verticalView = new QToolButton(this);
    verticalView->setIcon((QIcon("icon/vertical.png")));
    horizontalView = new QToolButton(this);
    horizontalView->setIcon(QIcon("icon/horizontal.png"));
    toolBar->addAction(addDatabase);
    toolBar->addWidget(verticalView);
    toolBar->addWidget(horizontalView);

}

void MainWindow::closeVocabolly()
{
    db.commit();
    db.close();
    close();
}

void MainWindow::freeStudyAction(int window)
{
    qDebug() << "Free study button clicked";
    stackedWidget->setCurrentIndex(window);
}

void MainWindow::flashStudyAction(int window)
{
    qDebug() << "Flash study button clicked";
    stackedWidget->setCurrentIndex(window);
}
