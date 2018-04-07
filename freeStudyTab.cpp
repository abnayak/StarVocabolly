#include <freeStudyTab.h>
#include <QStringList>
#include <helper.h>

freeStudyTab::freeStudyTab(QTabWidget *parent):QTabWidget(parent)
{
    QStringList tabList;
    dbConnect();
    tabList << "A" << "B" << "C" << "D" << "E" << "F"
            << "G" << "H" << "I" << "J" << "K" << "L"
            << "M" << "N" << "O" << "P" << "Q" << "R"
            << "S" << "T" << "U" << "V" << "W" << "X"
            << "Y" << "Z";

    model = new QSqlTableModel();
    model->setTable("words");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,tr("Word"));
    model->setHeaderData(1,Qt::Horizontal,tr("Meaning"));

    for(int i=0;i<tabList.size();i++)
    {
        //freestudy = new freeStudy(tabList[i],this);
        //addTab(freestudy,tabList[i]);
        FreeStudyaddTabs(tabList[i]);
    }
}

void freeStudyTab::FreeStudyaddTabs(QString tabString)
{
    QList<int> size;
    filter = new QSortFilterProxyModel;
    filter->setSourceModel(model);
    filter->setDynamicSortFilter(true);
    QString filterCond = QString ("^[%1].*").arg(tabString);
    filter->setFilterRegExp(QRegExp(filterCond, Qt::CaseInsensitive));
    filter->setFilterKeyColumn(0);

    wordTable = new QTableView();
    wordTable->setModel(filter);
    wordTable->hideColumn(2);
    wordTable->horizontalHeader()->setStretchLastSection(true);
    wordTable->setCornerButtonEnabled(false);
    wordTable->setSortingEnabled(true);
    wordTable->sortByColumn(0,Qt::AscendingOrder);

    description = new QTextEdit();

    size << 80 << 20;
    splitter = new QSplitter(Qt::Vertical);
    splitter->addWidget(wordTable);
    splitter->addWidget(description);
    splitter->setSizes(size);

    connect(wordTable,SIGNAL(clicked(QModelIndex)),this,SLOT(wordSelected(QModelIndex)));

    layout = new QVBoxLayout(this);
    //layout->addWidget(splitter);
    addTab(splitter,tabString);
    setLayout(layout);
}

void freeStudyTab::wordSelected(QModelIndex index)
{

    QString string ("select word, meaning, description from words where word=\'");
    string.append(index.data().toString());
    string.append("\'");
    qDebug() << "query is: " << string;
    QSqlQuery query;
    query.exec(string);
    while (query.next())
        description->setPlainText(query.value(2).toString());
}

