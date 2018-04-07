#include <DockButton.h>
#include <QApplication>

DockButton::DockButton(QWidget *parent):QWidget(parent)
{
    layout = new QVBoxLayout();

    freeStudyButton = new QToolButton();
    freeStudyButton->setIcon(QIcon("icon/list.png"));
    freeStudyButton->setIconSize(QSize(30,30));
    freeStudyButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    freeStudyButton->setText("Words");
    freeStudyButton->setFixedWidth(83);

    flashStudyButton = new QToolButton();
    flashStudyButton->setIcon(QIcon("icon/flash.png"));
    flashStudyButton->setIconSize(QSize(30,30));
    flashStudyButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    flashStudyButton->setText("Flash Card");
    flashStudyButton->setFixedWidth(83);

    exitButton = new QToolButton();
    exitButton->setText("Exit");
    exitButton->setIcon(QIcon("icon/exit.png"));
    exitButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    exitButton->setIconSize(QSize(30,30));
    exitButton->setFixedWidth(83);

    layout->addWidget(freeStudyButton);
    layout->addWidget(flashStudyButton);
    layout->addStretch();
    layout->addWidget(exitButton);
    setLayout(layout);

    connect(freeStudyButton,SIGNAL(clicked()),this,SLOT(freeStudyButtonSlot()));
    connect(flashStudyButton,SIGNAL(clicked()),this,SLOT(flashStudyButtonSlot()));
    connect(exitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void DockButton::freeStudyButtonSlot()
{
    if(flashStudyButton->isDown())
        flashStudyButton->setDown(false);
    freeStudyButton->setDown(true);

    emit freeStudyButtonClicked(0);
}

void DockButton::flashStudyButtonSlot()
{
    if(freeStudyButton->isDown())
        freeStudyButton->setDown(false);
    flashStudyButton->setDown(true);
    emit flashStudyButtonClicked(1);
}
