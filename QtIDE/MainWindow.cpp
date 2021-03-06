#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QDebug"
#include "QTimer"

#include "../SendToDevice/SendToDevice.h"

const char MainWindow::text1[] = { "Ola mundo{pt}!###\0" };
const char MainWindow::text2[] = { "abc\0" };
char MainWindow::data[2048] = { "CCLK?\0" };

char MainWindow::pilhaDataModem[ 5 ][ 100 ];//{ "CCLK?\0" };
const char MainWindow::MODEM_SEND_COMMAND_GET_RTC[] = { "AT+{ad:3}{fn:0}\r\n\0" };
const char *MainWindow::pModemReceiveRtc = &MODEM_RECEIVE_RTC[ 0 ];
const char MainWindow::SEND_POST_FORM_ONE_DATA[] = { "" };
const char MainWindow::SEND_FORM_BOUNDARY[] = { "----Boundary104491,78989,97301,104729Boundary\0" }; //46



void MainWindow::copy ( const char *p1, char *p2 )
{
  while ( *p1 != 0 )
  {
    *p2 = *p1;

    p1 += 1;
    p2 += 1;

    *p2 = 0;
  }
}

const char MainWindow::MODEM_RECEIVE_RTC[] = { "GET {surl} HTTP/1.1" };
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  pText1 = &MainWindow::text1[ 0 ];
  char t[] = { "GET /index.html HTTP/1.1\r\nHost: 192.168.124.12\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.3; WOW64; rv:40.0) Gecko/20100101 Firefoxurl: $s\r\n\r\n/40.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: pt-BR,pt;q=0.8,en-US;q=0.5,en;q=0.3\r\nAccept-Encoding: gzip, deflate\r\nConnection: keep-alive\r\n\r\n\0" };
  int i = 0;



  MainWindow::pilhaDataModem[ 3 ][ 0 ] = 'C';//{ "CCLK?\0" };
  MainWindow::pilhaDataModem[ 3 ][ 1 ] = 'C';
  MainWindow::pilhaDataModem[ 3 ][ 2 ] = 'L';
  MainWindow::pilhaDataModem[ 3 ][ 3 ] = 'K';
  MainWindow::pilhaDataModem[ 3 ][ 4 ] = '?';
  MainWindow::pilhaDataModem[ 3 ][ 5 ] = 0;



  this->sd = new SendToDevice<const char, char, unsigned char, unsigned char>( 10, 5, 5 );
  //this->sd->setSendFunction( &MainWindow::send );
  this->sd->setSendToDataPointer( &MainWindow::data[ 0 ], 50 );
  this->sd->setOnBufferFullFunction( &MainWindow::bufferFull );
  this->sd->setOnEndFunction( &MainWindow::endEvent );
  this->sd->addPointer( 0, &MainWindow::pilhaDataModem[ 0 ][ 0 ] );
  this->sd->addPointer( 1, &MainWindow::pilhaDataModem[ 1 ][ 0 ] );
  this->sd->addPointer( 2, &MainWindow::pilhaDataModem[ 2 ][ 0 ] );
  this->sd->addPointer( 3, &MainWindow::pilhaDataModem[ 3 ][ 0 ] );
  this->sd->addTransmitData( 0, &MODEM_SEND_COMMAND_GET_RTC[ 0 ] );
  this->sd->addFunctionData( 0, &MainWindow::endEvent );
  this->sd->addReceiveData( 0, 0 );
  this->sd->addTransmitData( 1, 0 );
  this->sd->addReceiveData( 1, 0 );
  this->sd->run();

  for ( int i = 0; i != 50; i += 1 )
  {
    this->sd->infinityLoop();
  }

  while ( t[ i ] != 0 )
  {
    if ( this->sd->testPointer ( &pModemReceiveRtc, &MODEM_RECEIVE_RTC[ 0 ], t[ i ] ) == ( char ) 1 )
    {
      qDebug() << "entrou no if";
      qDebug() << "URL:" << MainWindow::pilhaDataModem[ 0 ];
    }
    i += 1;
  }

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT( update() ));
  timer->start(1);

}

void MainWindow::bufferFull ()
{
  qDebug() << MainWindow::data;
}

void MainWindow::endEvent ()
{
  qDebug() << "Fim do processo!";
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
