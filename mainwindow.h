#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QNetworkAccessManager>
#include<QNetworkCookie>
#include<QNetworkCookieJar>
#include<qnetworkreply.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public :
    QNetworkAccessManager * man;
    QNetworkReply  * reply;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void fin();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
