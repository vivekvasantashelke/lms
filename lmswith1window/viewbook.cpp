#include "viewbook.h"
#include"mainwindow.h"
#include"ui_mainwindow.h"
#include"addbook.h"
viewbook::viewbook()
{

}
void viewbook::showdata(QVector<QString> v1,QVector<int> v2, int cnt)
{
    MainWindow mwobj;
    int k=0;
         QTableWidget *table=new QTableWidget();

            table->setRowCount(cnt);//
            table->setColumnCount(2);//
            table->setFocus();
            QStringList hlablels;
            hlablels<<"Books Name"<<"Quantity";
            table->setHorizontalHeaderLabels(hlablels);

            for(int i=0;i<table->rowCount();i++)
            {
                QTableWidgetItem *item;

                for(int j=0;j<table->columnCount();j++)
                {
                    item=new QTableWidgetItem();
                    if(j==0)
                item->setText(v1[i]);
                    if((j==1)&&(v2[i]!=0))

                 item->setData(0,v2[i]);
                table->setItem(i,j,item);
                k++;
                }

            }

//        QListWidgetItem *item =mwobj.ui->listWidget->currentItem();
//        //item=new QListWidgetItem();
//        for( int i=0;i<cnt;i++)
//        {
//            //item->setText(v2[i]);
////           mwobj.ui->listWidget->addItem(v2[i]);
//            mwobj.ui->listWidget->addItem(v1[i]);
//        }
}
