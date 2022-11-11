#include "addbook.h"
#include<QVector>
#include"ui_mainwindow.h"
#include"qmessagebox.h"
#include<QMessageBox>
#include"mainwindow.h"
QVector<QString> badd1;
QVector<int> qadd1;

addbook::addbook()
{


}
int addbook::trysearch(QString str)
{
   int cnt1=0;

    for(int i=0;i<badd1.size();i++)
       {
           if(str==badd1[i])
               cnt1++;
       }
       if(cnt1==0)
           return 0;
       else
           return 1;
}

void addbook::copy(QVector<QString>v1, QVector<int>v2)
{
    for(int i=0;i<v1.size();i++)
    {
        badd1.push_back(v1[i]);
        qadd1.push_back(v2[i]);
    }
}

//void addbook::issuesearched(QString book)
//{
//     for(int i=0;i<badd.size();i++)
//     {
//         if(book==badd[i])
//         {
//         if(qadd[i]<=0)
//         {
//             QMessageBox::warning(this,"warning","no more books available in library");
//         }
//         else
//         {
//             qadd[i]=qadd[i]-1;
//         }
//         }
//     }
//}



void addbook::returnsearched(QString book)
{
    for(int i=0;i<badd1.size();i++)
    {
        if(book==badd1[i])
        {
            qadd1[i]=qadd1[i]+1;
        }
    }
}
