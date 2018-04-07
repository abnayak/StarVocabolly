#include <flashStudyTab.h>

flashStudyTab::flashStudyTab(QTabWidget *parent):QTabWidget(parent)
{
    QStringList tabList;
    tabList << "A" << "B" << "C" << "D" << "E" << "F"
            << "G" << "H" << "I" << "J" << "K" << "L"
            << "M" << "N" << "O" << "P" << "Q" << "R"
            << "S" << "T" << "U" << "V" << "W" << "X"
            << "Y" << "Z";

    for(int i=0;i<tabList.size();i++)
    {
        flashstudy = new flashStudy(tabList[i],this);
        addTab(flashstudy,tabList[i]);
    }


}

