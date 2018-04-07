#ifndef FLASHSTUDY_H
#define FLASHSTUDY_H
#include <QSplitter>
#include <QTextEdit>
#include <QPushButton>
#include <QSqlQuery>
#include <FlashWidget.h>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlRecord>

class allFlashWidget:public QWidget
{
    Q_OBJECT
private:
    FlashWidget *flashWidget;
    QPushButton *nextWord;
    QPushButton *previousWord;
    QHBoxLayout *wordBrowseLayout;
    QVBoxLayout *layout;

public:
    allFlashWidget(const QString &word,const QString &meaning, QWidget *parent=0);
    void allDrawFlashWidget(const QString &);
    void disableNextWordButton();
    void enableNextWordButton();
    void disablePreviousButton();
    void enablePreviousButton();
signals:
    void nextWordButtonClicked();
    void previousWordButtonClicked();
private slots:
    void nextWordButtonSlot();
    void previousWordButtonSlot();
};

class flashStudy:public QWidget
{
    Q_OBJECT
private:
    int count;
    int size;
    allFlashWidget *allflashWidget;
    QSplitter *splitter;
    QTextEdit *description;
    QVBoxLayout *layout;
    QSqlQuery *query;
public:
    flashStudy(QString word,QWidget *parent=0);
private slots:
    void showNextFlashWord();
    void showPreviousFlashWord();

};

#endif // FLASHSTUDY_H
