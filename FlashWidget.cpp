#include <FlashWidget.h>
#include <QPainter>
#include <QColor>
#include <QDebug>

FlashWidget::FlashWidget(const QString &word, const QString &meaning, QWidget *parent):QWidget(parent)
{
    Meaning = meaning;
    Word = word;
    face=1;
}

void FlashWidget::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
    int Rwidth=400;
    int Rheight=200;

    painter = new QPainter(this);

    //QColor outLine(127, 0, 127);

    /* Draw background */
    painter->save();
    painter->setBrush(QColor(255,255,255));
    painter->setPen(Qt::NoPen);
    painter->drawRect(0,0,width(),height());
    painter->restore();

    /* Draw Flash Box */
    QBrush Brush(QColor(32,178,170));
    painter->save();
    painter->setBrush(Brush);
    painter->setPen(Qt::NoPen);
    //painter->drawRect((width()/2)-(Rwidth/2),(height()/2)-(Rheight/2),Rwidth,Rheight);
    painter->drawRect(((width()/2)-(Rwidth/2))-5,((height()/2)-(Rheight/2))-5,Rwidth+10,Rheight+10);
    painter->restore();

    /* Draw inner Flash Grey color */
    //QBrush FlashBrush(QColor(0, 127, 127, 191));
    QBrush FlashBrush(QColor(240,248,255,191));
    painter->save();
    painter->setBrush(FlashBrush);
    painter->setPen(Qt::NoPen);
    painter->drawRect((width()/2)-(Rwidth/2),(height()/2)-(Rheight/2),Rwidth,Rheight);
    painter->restore();

    /* Draw the inner word */
    QBrush WordBrush(QColor(255,255,255),Qt::NoBrush);
    painter->save();
    painter->setBrush(WordBrush);
    painter->setPen(Qt::SolidLine | Qt::RoundCap);
    painter->setRenderHint(QPainter::Antialiasing); //Make writting Smoother
    QRect rectangle((width()/2)-(Rwidth/2),(height()/2)-(Rheight/2),Rwidth,Rheight);
    painter->drawText(rectangle,Qt::AlignCenter|Qt::TextWordWrap,Word);
    painter->restore();
}

void FlashWidget::drawFlashWidget(const QString &word)
{
    Word = word;
    paintEvent(0);
}

void FlashWidget::mouseReleaseEvent(QMouseEvent *)
{
    if(face == 1)
    {
        Old_word = Word;
        Word = Meaning;
        face=0;
    }
    else
    {
        face=1;
        Word = Old_word;
    }
    repaint();
    qDebug() << " mouse release";
}
