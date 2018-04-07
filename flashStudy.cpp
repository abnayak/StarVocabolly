#include <flashStudy.h>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSizePolicy>
#include <QList>
#include <QIcon>
#include <QSize>

allFlashWidget::allFlashWidget(const QString &word,const QString &meaning,QWidget *parent):QWidget(parent){

    flashWidget = new FlashWidget(word,meaning,this);
    nextWord = new QPushButton("&Next");
    nextWord->setIcon(QIcon("icon/next.png"));
    previousWord = new QPushButton("&Previous");
    previousWord->setDisabled(true);
    previousWord->setIcon(QIcon("icon/back.png"));

    wordBrowseLayout = new QHBoxLayout();
    wordBrowseLayout->addWidget(previousWord);
    wordBrowseLayout->addStretch();
    wordBrowseLayout->addWidget(nextWord);

    layout = new QVBoxLayout;
    layout->addWidget(flashWidget);
    layout->addLayout(wordBrowseLayout);

    setLayout(layout);

    connect(nextWord,SIGNAL(clicked()),this,SLOT(nextWordButtonSlot()));
    connect(previousWord,SIGNAL(clicked()),this,SLOT(previousWordButtonSlot()));
}

void allFlashWidget::nextWordButtonSlot()
{
    qDebug()<< "nextWordButtonSlot()";
    emit nextWordButtonClicked();
}
void allFlashWidget::previousWordButtonSlot()
{
    emit previousWordButtonClicked();
}

void allFlashWidget::allDrawFlashWidget(const QString &word)
{
    flashWidget->drawFlashWidget(word);
}

void allFlashWidget::enableNextWordButton()
{
    nextWord->setEnabled(true);
}
void allFlashWidget::enablePreviousButton()
{
    previousWord->setEnabled(true);
}
void allFlashWidget::disableNextWordButton()
{
    nextWord->setDisabled(true);
}
void allFlashWidget::disablePreviousButton()
{
    previousWord->setDisabled(true);
}

flashStudy::flashStudy(QString word, QWidget *parent):QWidget(parent)
{
    QList<int> sizes;
    count =0;
    size=0;
    splitter = new QSplitter(Qt::Vertical);
    description = new QTextEdit(this);

    QString queryString;

    queryString = QString("select word, meaning, description from words where word like '%1%'").arg(word);
    query = new QSqlQuery();

    query->exec(queryString);

    while(query->next())
        size++;

    query->exec(queryString);
    query->next();
    count++;
    allflashWidget = new allFlashWidget(query->value(0).toString(),query->value(1).toString(),this);

    splitter->addWidget(allflashWidget);
    splitter->addWidget(description);
    splitter->setOpaqueResize(true);

    sizes << 99 <<  1;
    splitter->setSizes(sizes);

    layout = new QVBoxLayout();
    layout->addWidget(splitter);

    setLayout(layout);

    connect(allflashWidget,SIGNAL(nextWordButtonClicked()),this,SLOT(showNextFlashWord()));
    connect(allflashWidget,SIGNAL(previousWordButtonClicked()),this,SLOT(showPreviousFlashWord()));

}

void flashStudy::showNextFlashWord()
{
    if (count <= size )
    {
        count++;

        QList<int> sizes;
        query->next();
        allFlashWidget *flash;
        flash = new allFlashWidget(query->value(0).toString(),query->value(1).toString(),this);
        splitter->insertWidget(0,flash);

        connect(flash,SIGNAL(nextWordButtonClicked()),this,SLOT(showNextFlashWord()));
        connect(flash,SIGNAL(previousWordButtonClicked()),this,SLOT(showPreviousFlashWord()));
        delete (allFlashWidget*) splitter->widget(1);
        sizes << 99
              << 1;
        splitter->setSizes(sizes);

        flash->enablePreviousButton();
        if (count == size )
        {
            flash->disableNextWordButton();
        }
    }

}
void flashStudy::showPreviousFlashWord()
{
    count--;

    qDebug() << "count: " << count;
    QList<int> sizes;
    query->previous();
    allFlashWidget *flash;
    flash = new allFlashWidget(query->value(0).toString(),query->value(1).toString(),this);
    splitter->insertWidget(0,flash);

    connect(flash,SIGNAL(nextWordButtonClicked()),this,SLOT(showNextFlashWord()));
    connect(flash,SIGNAL(previousWordButtonClicked()),this,SLOT(showPreviousFlashWord()));
    delete (allFlashWidget*) splitter->widget(1);
    sizes << 99
          << 1;
    splitter->setSizes(sizes);

    flash->enableNextWordButton();
    flash->enablePreviousButton();
    if (count == 1 )
    {
        flash->disablePreviousButton();
    }

}
