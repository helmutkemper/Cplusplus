#include "mbed.h"
#include "SDFileSystem.h"
#include "EthernetInterface.h"
#include "./SendToDevice/SendToDevice.h"
#include <stdio.h>
#include <string.h>

#define PORT   80

SDFileSystem sdCardGCls (PTE3, PTE1, PTE2, PTE4, "sd"); // MOSI, MISO, SCK, CS

EthernetInterface ethernetInterfaceGCls;

TCPSocketServer tcpSocketServerGCls;
bool serverIsListenedGBl = false;

TCPSocketConnection tcpSocketConnectionGCls;
bool clientIsConnected = false;

SendToDevice<const char, char, unsigned char, unsigned char> sendToDeviceGCls ( 10, 3 );

bool inifinit = true;

int i = 0;
char c;
char fileContent[1024] = {};

//const char SEND_POST_FORM_ONE_DATA[] = { "POST /index.php HTTP/1.1\\r\\nHost: 192.168.124.62\\r\\nContent-Length: 165\\r\\nCache-Control: no-cache\\r\\nContent-Type: multipart/form-data; boundary=----Boundary104491,78989,97301,104729Boundary\\r\\nUser-Agent: helmut.pt.kemper.at.gmail.pt.com.firmware.code.agent\\r\\nAccept: * / *\\r\\nAccept-Encoding: deflate\\r\\nAccept-Language: en-US,en;q=1,pt-BR;q=1,pt;q=1\\r\\n\\r\\n------Boundary104491,78989,97301,104729Boundary\\r\\nContent-Disposition: form-data; name=\"teste\"\\r\\n\\r\\ntexto enviado\\r\\n------Boundary104491,78989,97301,104729Boundary--\r\n\0" };
const char SEND_POST_FORM_ONE_DATA[] = { "HTTP/1.1 200 OK\n\rContent-Length: 12\n\rContent-Type: text\n\rConnection: Close\n\r\n\rHello Word!\0" };

Serial pcSerialPort(USBTX, USBRX);

void onInternetBufferFull ()
{
  pcSerialPort.printf("%s", &fileContent[ 0 ] );
  tcpSocketConnectionGCls.send( &fileContent[ 0 ], 1023 );
}

void internetClose ()
{
  pcSerialPort.printf( "\r\nclose()\r\n" );
  tcpSocketConnectionGCls.close();
  inifinit = false;

  sendToDeviceGCls.addTransmitData( 0, &SEND_POST_FORM_ONE_DATA[ 0 ] );
  sendToDeviceGCls.addReceiveData( 0, 0 );
  sendToDeviceGCls.addTransmitData( 1, 0 );
  sendToDeviceGCls.addReceiveData( 1, 0 );
}

void internetServerConnect ()
{
  //setup ethernet interface
  ethernetInterfaceGCls.init(); //Use DHCP
  ethernetInterfaceGCls.connect();
  pcSerialPort.printf("IP Address is %s\n\r", ethernetInterfaceGCls.getIPAddress());

  //setup tcp socket
  if( tcpSocketServerGCls.bind( PORT ) < 0 )
  {
    pcSerialPort.printf("tcp server bind failed.\n\r");
  }
  else
  {
    pcSerialPort.printf("tcp server bind successed.\n\r");
    serverIsListenedGBl = true;
  }

  if( tcpSocketServerGCls.listen( 1 ) < 0 )
  {
    pcSerialPort.printf( "tcp server listen failed.\n\r" );
  }
  else
  {
    pcSerialPort.printf( "tcp server is listening...\n\r" );
  }
}

int main (void)
{

  pcSerialPort.baud( 115200 );

  sendToDeviceGCls.setSendToDataPointer( &fileContent[ 0 ], 1023 );
  sendToDeviceGCls.setOnBufferFullFunction( &onInternetBufferFull );
  sendToDeviceGCls.setOnEndFunction( &internetClose );

  internetServerConnect ();




  while ( true )
  {
    // infinity loop

    //inicio - listening for http GET request
    if ( serverIsListenedGBl )
    {
      //blocking mode(never timeout)
      if( tcpSocketServerGCls.accept( tcpSocketConnectionGCls ) < 0 )
      {
        pcSerialPort.printf( "failed to accept connection.\n\r" );
      }
      else
      {
        pcSerialPort.printf( "connection success!\n\rIP: %s\n\r", tcpSocketConnectionGCls.get_address() );
        clientIsConnected = true;

        while( clientIsConnected )
        {
          char buffer[1024] = {};
          switch( tcpSocketConnectionGCls.receive( buffer, 1023 ) )
          {
            case 0:
              pcSerialPort.printf( "recieved buffer is empty.\n\r" );
              clientIsConnected = false;
              break;
            case -1:
              pcSerialPort.printf( "failed to read data from client.\n\r" );
              clientIsConnected = false;
              break;
            default:
              pcSerialPort.printf( "\r\nrun();\n\r" );
              sendToDeviceGCls.clear();
              sendToDeviceGCls.addTransmitData( 0, &SEND_POST_FORM_ONE_DATA[ 0 ] );
              sendToDeviceGCls.addReceiveData( 0, 0 );
              sendToDeviceGCls.addTransmitData( 1, 0 );
              sendToDeviceGCls.addReceiveData( 1, 0 );
              sendToDeviceGCls.run();
              inifinit = true;
              while ( inifinit )
              {
                sendToDeviceGCls.infinityLoop();
              }
              break;
          }
        }
        pcSerialPort.printf( "\r\nclientIsConnected = false\n\r" );

      }
    }
    //fim - listening for http GET request







  }

}
