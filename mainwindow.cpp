#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qdebug.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     reply=0;
    this->man=new QNetworkAccessManager();
    //在Header 里面 传递 Cookie到服务器
  QNetworkRequest * request=new QNetworkRequest(QUrl("http://localhost:8829/index.aspx"));
  QList<QNetworkCookie> * listcookie=new QList<QNetworkCookie>();
  listcookie->push_back(QNetworkCookie("testcookie","xx"));
  //Qvariant 存入
  QVariant var;
  var.setValue(*listcookie);
  request->setHeader(QNetworkRequest::CookieHeader,var);
  this->reply= this->man->get(*request);
  //请求完成连接信号槽
  connect(this->reply,SIGNAL(finished()),this,SLOT(fin()));
}

MainWindow::~MainWindow()
{
    this->man->deleteLater();
    delete ui;
}
void MainWindow::fin()
{
    qDebug()<<"请求成功，返回："<<this->reply->readAll();
    //获取服务器上返回的Cookie
    QNetworkCookieJar * jar= this->man->cookieJar();
    QList<QNetworkCookie> list= jar->cookiesForUrl(QUrl("http://localhost:8829/index.aspx"));
    for(int i=0;i<list.length();i++)
    {
         qDebug()<<list[i].name()<<":"<<list[i].value();
    }
}
