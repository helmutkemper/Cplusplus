#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QDebug"
#include "QTimer"

#include "../SendToDevice/SendToDevice.h"

const char MainWindow::text1[] = { "Ola mundo{pt}!###\0" };
const char MainWindow::text2[] = { "abc\0" };
char MainWindow::data[2048];// = { " cruel" };

const char MainWindow::SEND_POST_FORM_ONE_DATA[] = { "POST /teste.php HTTP/1.1\\r\\nHost: www.iotm.io\\r\\nContent-Length: 165\\r\\nCache-Control: no-cache\\r\\nContent-Type: multipart/form-data; boundary=----Boundary104491,78989,97301,104729Boundary\\r\\nUser-Agent: helmut.pt.kemper.at.gmail.pt.com.firmware.code.agent\\r\\nAccept: * / *\\r\\nAccept-Encoding: deflate\\r\\nAccept-Language: en-US,en;q=1,pt-BR;q=1,pt;q=1\\r\\n\\r\\n------Boundary104491,78989,97301,104729Boundary\\r\\nContent-Disposition: form-data; name=\"teste\"\\r\\n\\r\\ntexto enviado\\r\\n------Boundary104491,78989,97301,104729Boundary--\r\n\0" };
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

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  pText1 = &MainWindow::text1[ 0 ];

  this->sd = new SendToDevice<const char, char, unsigned char, unsigned char>( 10, 3 );
  //this->sd->setSendFunction( &MainWindow::send );
  this->sd->setSendToDataPointer( &MainWindow::data[ 0 ], 50 );
  this->sd->setOnBufferFullFunction( &MainWindow::bufferFull );
  this->sd->setOnEndFunction( &MainWindow::endEvent );
  this->sd->addTransmitData( 0, &MainWindow::SEND_POST_FORM_ONE_DATA[ 0 ] );
  this->sd->addReceiveData( 0, 0 );
  this->sd->addTransmitData( 1, 0 );
  this->sd->addReceiveData( 1, 0 );
  this->sd->run();

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
