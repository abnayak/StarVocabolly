#ifndef DOCKBUTTON_H
#define DOCKBUTTON_H
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QToolButton>

class DockButton:public QWidget
{
    Q_OBJECT
private:
    QToolButton *freeStudyButton;
    QToolButton *flashStudyButton;
    QToolButton *exitButton;
    QVBoxLayout *layout;
public:
    DockButton(QWidget *parent=0);
signals:
    void freeStudyButtonClicked(int);
    void flashStudyButtonClicked(int);
private slots:
    void freeStudyButtonSlot();
    void flashStudyButtonSlot();
};

#endif // DOCKBUTTON_H
