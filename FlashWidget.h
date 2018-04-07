#ifndef FLASHWIDGET_H
#define FLASHWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QString>

class FlashWidget:public QWidget
{
    Q_OBJECT
private:
    QString Word;
    QString Old_word;
    QString Meaning;
    int face;
    QPainter *painter;
public:
    FlashWidget(const QString &word,const QString &meaning,QWidget *parent=0);
    void paintEvent(QPaintEvent *);
public slots:
    void drawFlashWidget(const QString &word);
protected:
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // FLASHWIDGET_H
