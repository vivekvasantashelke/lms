#ifndef ADDBOOK_H
#define ADDBOOK_H


#include<QString>
#include<QVector>

class addbook
{
public:
    addbook();
    void returnsearched(QString);
    void on_pushButton_add_clicked();
    int trysearch(QString);
    void issuesearched(QString);
    void copy(QVector<QString>,QVector<int>);
};

#endif // ADDBOOK_H
