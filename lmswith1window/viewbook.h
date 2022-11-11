#ifndef VIEWBOOK_H
#define VIEWBOOK_H

#include<QTableWidget>
#include<QTableWidgetItem>
class viewbook
{
public:
    viewbook();
    void showdata(QVector<QString> ,QVector<int> , int );
};

#endif // VIEWBOOK_H
