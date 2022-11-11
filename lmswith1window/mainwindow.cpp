#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QSet>
#include<QFile>
#include<QTextStream>
#include<QTextEdit>
#include<QDebug>
#include<QStringList>
#include <QValidator>
#include <iostream>
#include <string>
#include<cstring>
#include <Qt>
#include <QFile>
#include<QContextMenuEvent>
#include <QRegularExpressionValidator>
using namespace std;
int serching_student_name(QString );

QSet <QString> user1,user12,user123;
QSet<QString> email;
QSet <QString> user,mono;
QVector<QString> badd,sample;
QVector<int> qadd;
QList<QString> value;
QMultiMap<QString,QString> mmp;
QStringList sl,sl1;
QString text1, password,username,repassword,text,u,line;
int cnt=0,cnt1=0,cnt2=0,i;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_mono->setValidator(new QIntValidator(0,9999999999,this));
   //QRegExp rx1("[a-z-@-.\\.\\- 0-9]{0,30}");
 //  QValidator *validator7 = new QRegExpValidator(rx1, this);
 //   ui->lineEdit_email->setValidator(validator7);


//    QPixmap pix("C:/he8v3/icon/delta_pic");
//       int w=ui->label_pic->width();
//       int h=ui->label_pic->height();
//       ui->label_pic->setPixmap(pix.scaled(w+30,h+30,Qt::KeepAspectRatio));


}



void MainWindow::filldetails(QString book, QString student)
{

    if(trysearch(book))
    {
    mmp.insert(student,book);
    }

}

int MainWindow::trystudent(QString student)
{
    if(user.contains(student))
    {
        return 1;
    }
    else
        return 0;
}

void MainWindow::issuesearched(QString book)
{
    for(int i=0;i<badd.size();i++)
    {
        if(book==badd[i])
        {
        if(qadd[i]<=0)
        {
            QMessageBox::warning(this,"warning","no more books available in library");
        }
        else
        {
            qadd[i]=qadd[i]-1;
        }
        }
    }
}
int j=0;
int MainWindow::trysearch(QString str)
{
    /**********************previous code ************************************************/

//    cnt1=0;

//    for(int i=0;i<badd.size();i++)
//       {
//           if(str==badd[i])
//               cnt1++;
//       }
//       if(cnt1==0)
//           return 0;
//       else
//           return 1;

    /**********************previous code ************************************************/

  //  QFile file("ADDBOOKdata.xls");
    QFile file("ADDBOOKdata1.xls");
    if(!file.open(QFile::ReadOnly)){

        QMessageBox::warning(this," ","File not found");
    }
    else
    {
    QTextStream In(&file);
    while(!In.atEnd())
    {
        QString line=In.readLine();
//        qDebug()<<line<<endl;


        sl=line.split("\t");
//        QString astr=line.section("\t",1,1,QString::SectionSkipEmpty).trimmed();
//        int a=astr.toInt();
        //qDebug()<<sl<<endl;
//        file.open(QFile::WriteOnly);
//        QTextStream out2(&file);
//        out2<<sl<<"\t"<<a<<endl;
        QList<QString> ls;
        ls.push_back(line);



                if(sl.contains(str))
        {
                    qDebug()<<file.pos();

            QString astr=line.section("\t",1,1,QString::SectionSkipEmpty).trimmed();
            qDebug()<<astr<<"\n";
            QString astr2=astr;
            int a=astr.toInt();
            a=a-1;

            astr=QString::number(a);

             qDebug()<<astr<<"\n";
                               //     QRegExp rx(astr);
       // QString str1=line.section(rx,1,1);

       // qDebug()<<str1;
        //  if(!sl.isEmpty())
             //{
             //    context[sl.at(file.pos()).trimmed()].append(astr);
             //}
  //  astr.replace(rx,astr);
    //for(int i=0;str.indexOf(astr)!=-1;i++)
  //      str.replace(str.indexOf(astr),1,"%"+QString::number(i));
            //line.section("\t",1,1,QString::SectionSkipEmpty).trimmed()=astr;
          //  sl.replaceInStrings(astr1);
            sl.join("\t");
            //file.pos()
            return 1;
        }

        }
    }
    return 0;

}

int MainWindow::fileread(QString str)
{
    QFile file("SignInData.txt");
    file.open(QFile::ReadOnly);
            QTextStream in(&file);
            while(!in.atEnd())
            {
            text1=in.readLine();

                if(text1==str)
                {
                    return 1;

                }
            }
            return 0;
}

int MainWindow::checkrepeatuser(QString str)
{
    QFile file1("SignInData.xls");
    file1.open(QFile::ReadOnly);
    QTextStream in1(&file1);
    while(!in1.atEnd())
    {
        int j=0;
        j++;

        line=in1.readLine();

        sl1=line.split("\t");
        if(sl1.contains(str))
            return 1;

    }
        return 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
/**********************previous code ************************************************/

//    QString username =ui->lineEdit ->text();
//    QString password =ui->lineEdit_2->text();

//    if((username=="dtiot")&&(password=="1234"))
//    {
//        ui->stackedWidget->setCurrentIndex(1);

//    }
//        else {
//       QMessageBox::warning(this,"Login","incorrect ID or Password");
//    }

//    QString test=username + password;
//    if(){
//        QMessageBox::warning(this,"","LogIn Failed");
//    }
//    else{
  /**********************previous code ************************************************/



        QFile file("SignInData.txt");
        if(!file.open(QFile::ReadOnly)){
            QMessageBox::warning(this," ","File not found");
        }
        else
        {
        QTextStream In(&file);
        username=ui->lineEdit->text();
        password=ui->lineEdit_2->text();
        QString text2=username+password;
//        while(In.atEnd())
//        {
//            text=In.readLine();
//        }
        if(fileread(text2))
            ui->stackedWidget->setCurrentIndex(1);
        else
            QMessageBox::warning(this,"warning","username or password is incrorrect");

        file.flush();
        file.close();
    }

}

void MainWindow::on_pushButton_logout_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,
                                                            "Logout","Are you sure? you want to logout"
                                                            ,QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    ui->stackedWidget->setCurrentIndex(0);
    else
        ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_pushButton_vb_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

   QFile file("ADDBOOKdata1.xls");
    if(!file.open(QFile::ReadOnly)){
        QMessageBox::warning(this," ","File Not open");
    }
    else
    {

    QTextStream In(&file);

    QString view = In.readAll();

    ui->textEdit->setLineWidth(10);
    ui->textEdit->setText(view);
    }

    file.close();
}

void MainWindow::on_pushButton_2_vu_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
//    QListWidgetItem *item = ui->listWidget->currentItem();
//    item=new QListWidgetItem();
//    //QSet<QString>
//    for( auto str:user)
//    {
//        item->setText(str);
//        ui->listWidget->addItem(str);
//    }


    QFile file("adduser.xls");
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::warning(this,"WARNING","File NOt Open");
    }
    if(file.pos()==0)
    {
        QTextStream out(&file);
        QString text1= "Name";
        QString text2= "E-mail";
        QString text3= "MO.No";
        out<<text1<<"\t"<<text2<<"\t"<<text3<<"\n";

    QString view = out.readAll();
//       ui->textEdit->setText(view);
    ui->textEdit_viewuser->setText(view);

    }

file.close();
}

void MainWindow::on_pushButton_3_sb_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
/*****************previous code ************************************************
    for(auto &u: user)
    {
    ui->comboBox_student->addItem(u);
    }
*****************previous code *************************************************/
    QString s1;

            QFile fileuser("adduser.xls");
            if(!fileuser.open(QFile::ReadOnly))
            {
             QMessageBox::warning(this,"Warnig","file Not Open");
            }

                 if(fileuser.pos()==0)
            {


                    QTextStream out(&fileuser);
                 while(!out.atEnd())
                      {
                       QString view = out.readLine();
                       sl=view.split("\t");
                       s1=sl.at(0);
                  ui->comboBox_student->addItem(s1);

                  }




}

}
void MainWindow::on_pushButton_add_clicked()
{
    cnt2=0;
    u=ui->lineEdit_book->text();


    i=ui->comboBox_addbook->currentIndex();


    if(u==""||i==0)
    {
       QMessageBox::warning(this,"Warning","First add book and quantity ");

    }
    else
    {
        QFile file("ADDBOOKdata1.xls");

        if(!file.open(QFile::ReadOnly | QFile::Append))
        {
            QMessageBox::warning(this,"Warning","File Not open");
        }
        else
        {
            /**********************previous code ************************************************/

//        badd.push_back(u);
//    qadd.push_back(i);
//    cnt++;
//    ui->lineEdit_book->clear();
//    //ui->comboBox_addbook->clearEditText();
            /**********************previous code ************************************************/

        if(file.pos()==0){
            QTextStream Out(&file);
            QString text = "Name of the Book";
            QString text1 = "Book Quantity";
            //text.size()==12;
            Out<<text<<"\t"<<text1<<"\n";
//            sl<<text<<text1;
        }
        else
        {
        QTextStream Out(&file);
        Out<<u<<"\t"<<i<<"\n";

        ui->comboBox_addbook->setCurrentIndex(0);
        ui->lineEdit_book->clear();
        cnt2++;
        file.close();
    }
    }
    }

}





int serching_student_name(QString s)

{
    QString s2;
    QFile file("adduser.xls");
    if(!file.open(QFile::ReadOnly))
    {
       return 0;
    }

         if(file.pos()==0)
    {


            QTextStream out(&file);
         while(!out.atEnd())
              {
               QString view = out.readLine();
               sl=view.split("\t");
               s2=sl.at(0);
           if((s)==s2)
                 {
           return 1;

                 }
           }

    }


file.close();

 return 0;
}





void MainWindow::on_pushButton_addstudent_clicked()
{
    /**********************previous code ************************************************/

//    QString u=ui->lineEdit_addstudent->text();
//     user.insert(u);
//     email.insert(ui->lineEdit_addemail->text());
//     mono.insert(ui->lineEdit_addmo->text());

//     ui->lineEdit_addstudent->clear();
//     ui->lineEdit_addmo->clear();
//     ui->lineEdit_addemail->clear();

    /**********************previous code ************************************************/



    int j,p,q,i,k,n,l,cnt=0,l2,l3;
        string str;
        QString u,str2,u2;
       u2=ui->lineEdit_addstudent->text();


       if(serching_student_name(u2))
       {

             QMessageBox::warning(this,"WARNING","This Nmae Present Use Unic Name");

         }
       else
       {
           ++cnt;
       }




         u=ui->lineEdit_mono->text();
         str2 = ui->lineEdit_email->text();

       l3=u2.length();

       if(l3>3)
       {
           user1.insert(u2);
           ++cnt;
       }
       else
       {
           QMessageBox::warning(this,"WARNING","Please ADD FULL NAME");
                    ui->lineEdit_addstudent->clear();

       }

    l2=str2.length();
         str = str2.toStdString();
         j=str.find_last_of(".");
          i=str.find_last_of("@");
            p=str.find_last_of("@g");
             q=str.find_last_of('m');
           n=str.find_last_of("com");
           k=str.find_last_of("@gmail.com");


         if((j<0) || (i<0)|| (p<0) || (k<0)||(q<0) ||(n<0) || l2<10)
        {

             QMessageBox::warning(this,"Email","Re-Enter Email");
       ui->lineEdit_email->clear();
        }
        else
         {
           user12.insert(str2);
            ++cnt;
         }

         l= u.length();
             if(l<10 )
          {

              QMessageBox::warning(this,"MOBILE","Re-Enter MO.NO");
               ui->lineEdit_mono->clear();
          }
          else {


              user123.insert(u);
              ++cnt;
          }



             QFile file("adduser.xls");
             if(!file.open(QFile::ReadOnly))
             {
                 QMessageBox::warning(this,"WARNING","File NOt Open");
             }

                  if(file.pos()==0)
             {


                     QTextStream out(&file);
                  while(!out.atEnd())
                       {
                        QString view = out.readLine();
                    if((u2+"\t"+str2+"\t"+u)==view)
                          {
                             QMessageBox::warning(this,"warning","Alearedy exixsting");
                               ui->lineEdit_addstudent->clear();
                             ++cnt;
                          }
                       }

             }


         file.close();

    if(cnt==4)
    {
                QFile file("adduser.xls");
          if(!file.open(QFile::WriteOnly|QFile::Append))
          {
              QMessageBox::warning(this,"WARNING","File not Open");
          }
          else
          {

              QTextStream Out(&file);
              Out<<u2<<"\t"<<str2<<"\t"<<u<<"\n";
              file.close();

          }
          QMessageBox::information(this,"ADD","STUDENTS ADDED");
          cnt=0;
    }
    else{
            cnt=0;
    }
//         ui->lineEdit_addstudent->clear();
//          ui->lineEdit_email->clear();
//           ui->lineEdit_mono->clear();
}

void MainWindow::on_pushButton_issue_clicked()
{
    QString book=ui->lineEdit_bookname->text();
    QString student=ui->comboBox_student->currentText();
    QDate d1=ui->dateEdit->date();
    /**********************previous code ************************************************/
//    addbookss ab;
//    if(ab.trysearch(book))
//    {
//   filldetails(book,student);
//    if(student=="Select student")
//        QMessageBox::warning(this,"warning","student is not selected ");
//    else
//    {
//        if(trysearch(book))
//        {
//            issuesearched(book);
//        QMessageBox::information(this,"succesffull","book is issued");
//        }
//                else
//          QMessageBox::warning(this,"warning","book is not available");


//        ui->lineEdit_bookname->clear();
//        ui->comboBox_student->setCurrentIndex(0);

//    }
    /**********************previous code ************************************************/

    if(trysearch(book))//&&(ui->comboBox_selectbook->currentText()!="select book"))
    {
//        QFile modifyfile("ADDBOOKdata.xls");
//       modifyfile.open(QFile::WriteOnly);

////       modifyfile.write()

    QMessageBox::information(this,"          ","Book is issued");

    }
    else
    {
     QMessageBox::warning(this,"warning","Book is not available");
    }
    ui->lineEdit_bookname->clear();
    ui->comboBox_selectbook->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_signup_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
        QFile file("SignInData.txt");
        QFile file1("SignInData.xls");
        if(!file.open(QFile::WriteOnly |QFile::Append))
            QMessageBox::warning(this,"warning","file not create/open");
        else
        {
            QTextStream out(&file);
            username =ui->lineEdit_signupuser->text();
            password =ui->lineEdit_signuppass->text();
            repassword=ui->lineEdit_signuprepass->text();
            if(password!=repassword)
            {
                QMessageBox::warning(this,"warning","Both passwords need to be same");
            }
            else if(checkrepeatuser(username))
            {
                QMessageBox::warning(this,"warning","user is already registered");
            }
            else
            {
                file1.open(QFile::WriteOnly|QFile::Append);
                QTextStream out1(&file1);
                out1<<username<<"\t"<<password<<"\n";
                text1=username+password;
                QTextStream out(&file);
                out<<text1<<"\n";
                file.flush();
                file.close();
            }

}
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_6_ab_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_abback_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_vbback_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_asback_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_addstudent->clear();
     ui->lineEdit_email->clear();
      ui->lineEdit_mono->clear();
}

void MainWindow::on_pushButton_vuback_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ibback_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_bookname->clear();
    ui->comboBox_selectbook->setCurrentIndex(0);

}

void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_5_au_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_rb_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}
