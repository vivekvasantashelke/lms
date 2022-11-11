#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
     void filldetails(QString,QString);
     int trystudent(QString);
     void issuesearched(QString);
     int trysearch(QString);
     int fileread(QString);
     int checkrepeatuser(QString);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_6_ab_clicked();

    void on_pushButton_abback_clicked();

    void on_pushButton_vbback_clicked();

    void on_pushButton_asback_clicked();

    void on_pushButton_vuback_clicked();

    void on_pushButton_ibback_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_vb_clicked();

    void on_pushButton_2_vu_clicked();

    void on_pushButton_3_sb_clicked();

    void on_pushButton_5_au_clicked();

    void on_pushButton_rb_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_addstudent_clicked();

    void on_pushButton_issue_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_sample_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
