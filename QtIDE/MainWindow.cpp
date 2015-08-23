#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QDebug"
#include "QTimer"

#include "../StateMachine/SendToDevice.h"

const char MainWindow::text1[] = { "Ola mundo{pt}!###\0" };
const char MainWindow::text2[] = { "abc\0" };
char MainWindow::data[] = { " cruel" };

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  pText1 = &MainWindow::text1[ 0 ];

  this->sd = new SendToDevice<const char, char, unsigned char, unsigned char, Event::eEvent>( 10, 3 );
  this->sd->setSendFunction( &MainWindow::send );
  this->sd->addPointer( 0, &MainWindow::data[ 0 ] );
  this->sd->addPointer( 1, &MainWindow::data[ 0 ] );
  this->sd->addPointer( 2, &MainWindow::data[ 0 ] );
  this->sd->addTransmitData( 0, &MainWindow::text1[ 0 ] );
  this->sd->addReceiveData( 0, &MainWindow::text2[ 0 ] );
  this->sd->addTransmitData( 1, &MainWindow::text1[ 0 ] );
  this->sd->addReceiveData( 1, 0 );
  this->sd->run();

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT( update() ));
  timer->start(1);

}

void MainWindow::update ()
{
  this->sd->infinityLoop();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::send ( char d )
{
  qDebug() << d;
}

void MainWindow::on_pushButton_clicked()
{
  this->sd->onIncomingData( 'a' );
}

void MainWindow::on_pushButton_2_clicked()
{
  this->sd->onIncomingData( 'b' );
}

void MainWindow::on_pushButton_3_clicked()
{
  this->sd->onIncomingData( 'c' );
}
