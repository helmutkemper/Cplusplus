#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QDebug"
#include "QTimer"

#include "../SendToDevice/SendToDevice.h"

//TODO: COLOCAR OS PONTEIROS DE FUNÇÃO DENTRO DO TEMPLATE

const char MainWindow::text1[] = { "Ola mundo{pt}!###\0" };
const char MainWindow::text2[] = { "abc\0" };
char MainWindow::data[2048] = { "CCLK?\0" };

char MainWindow::pilhaDataModem[ 5 ][ 100 ];//{ "CCLK?\0" };
const char MainWindow::MODEM_SEND_COMMAND_GET_RTC[] = { "AT+{ad:3}{fn:0}\r\n\0" };
const char *MainWindow::pModemReceiveRtc = &MODEM_RECEIVE_RTC[ 0 ];
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

const char MainWindow::MODEM_RECEIVE_RTC[] = { "+CCLK: \"{time}{time}{snum}\0" };
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  pText1 = &MainWindow::text1[ 0 ];
  char t[] = { "+CCLK: \"hola mundo\n\ncruel!\"\0" };
  int i = 0;



  MainWindow::pilhaDataModem[ 3 ][ 0 ] = 'C';//{ "CCLK?\0" };
  MainWindow::pilhaDataModem[ 3 ][ 1 ] = 'C';
  MainWindow::pilhaDataModem[ 3 ][ 2 ] = 'L';
  MainWindow::pilhaDataModem[ 3 ][ 3 ] = 'K';
  MainWindow::pilhaDataModem[ 3 ][ 4 ] = '?';
  MainWindow::pilhaDataModem[ 3 ][ 5 ] = 0;



  SendToDevice<const char, char, unsigned char, unsigned char>::init( 10, 5, 5 );
  //SendToDevice<const char, char, unsigned char, unsigned char>::setSendFunction( &MainWindow::send );
  SendToDevice<const char, char, unsigned char, unsigned char>::setSendToDataPointer( &MainWindow::data[ 0 ], 50 );
  SendToDevice<const char, char, unsigned char, unsigned char>::setOnBufferFullFunction( &MainWindow::bufferFull );
  SendToDevice<const char, char, unsigned char, unsigned char>::setOnEndFunction( &MainWindow::endEvent );
  SendToDevice<const char, char, unsigned char, unsigned char>::addPointer( 0, &MainWindow::pilhaDataModem[ 0 ][ 0 ] );
  SendToDevice<const char, char, unsigned char, unsigned char>::addPointer( 1, &MainWindow::pilhaDataModem[ 1 ][ 0 ] );
  SendToDevice<const char, char, unsigned char, unsigned char>::addPointer( 2, &MainWindow::pilhaDataModem[ 2 ][ 0 ] );
  SendToDevice<const char, char, unsigned char, unsigned char>::addPointer( 3, &MainWindow::pilhaDataModem[ 3 ][ 0 ] );
  SendToDevice<const char, char, unsigned char, unsigned char>::addTransmitData( 0, &MODEM_SEND_COMMAND_GET_RTC[ 0 ] );
  SendToDevice<const char, char, unsigned char, unsigned char>::addFunctionData( 0, &MainWindow::endEvent );
  SendToDevice<const char, char, unsigned char, unsigned char>::addReceiveData( 0, 0 );
  SendToDevice<const char, char, unsigned char, unsigned char>::addTransmitData( 1, 0 );
  SendToDevice<const char, char, unsigned char, unsigned char>::addReceiveData( 1, 0 );
  SendToDevice<const char, char, unsigned char, unsigned char>::run();

  for ( int i = 0; i != 50; i += 1 )
  {
    SendToDevice<const char, char, unsigned char, unsigned char>::infinityLoop();
  }

  while ( t[ i ] != 0 )
  {
    if ( SendToDevice<const char, char, unsigned char, unsigned char>::testPointer ( &pModemReceiveRtc, &MODEM_RECEIVE_RTC[ 0 ], t[ i ] ) == ( char ) 1 )
    {
      qDebug() << "entrou no if";
      qDebug() << MainWindow::pilhaDataModem[ 0 ];
      qDebug() << MainWindow::pilhaDataModem[ 1 ];
      qDebug() << MainWindow::pilhaDataModem[ 2 ];
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
  SendToDevice<const char, char, unsigned char, unsigned char>::infinityLoop();
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
  SendToDevice<const char, char, unsigned char, unsigned char>::onIncomingData( 'a' );
}

void MainWindow::on_pushButton_2_clicked()
{
  SendToDevice<const char, char, unsigned char, unsigned char>::onIncomingData( 'b' );
}

void MainWindow::on_pushButton_3_clicked()
{
  SendToDevice<const char, char, unsigned char, unsigned char>::onIncomingData( 'c' );
}
