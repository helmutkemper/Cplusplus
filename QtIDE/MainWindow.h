#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../SendToDevice/SendToDevice.h"

namespace Ui {
  class MainWindow;
}

//----Boundary104491,78989,97301,104729Boundary

//0 - página interna do host
//1 - host
//2 - Length
//3 - Boundary
//4 - Boundary
//5 - nome
//6 - dado
//7 - nome
//8 - dado
//9 - Boundary

//POST {pt} HTTP/1.1\\r\\n
//Host: {pt}\\r\\n
//Content-Length: {pt}\\r\\n
//Cache-Control: no-cache\\r\\n
//Content-Type: multipart/form-data; boundary={pt}\\r\\n
//User-Agent: helmut.pt.kemper.at.gmail.pt.com.firmware.code.agent\\r\\n
//Accept: * / *\\r\\n
//Accept-Encoding: deflate\\r\\n
//Accept-Language: en-US,en;q=1,pt-BR;q=1,pt;q=1\\r\\n
//\\r\\n
//--{pt}\\r\\n
//Content-Disposition: form-data; name="{pt}"\\r\\n
//\\r\\n
//{pt}\\r\\n
//Content-Disposition: form-data; name="{pt}"\\r\\n
//\\r\\n
//{pt}\\r\\n
//--{pt}--

//0 - página interna do host
//1 - host
//2 - Length
//3 - Boundary
//4 - Boundary
//5 - nome
//6 - dado
//7 - Boundary
//constante para 1 dado
//POST {pt} HTTP/1.1\\r\\nHost: {pt}\\r\\nContent-Length: {pt}\\r\\nCache-Control: no-cache\\r\\nContent-Type: multipart/form-data; boundary={pt}\\r\\nUser-Agent: helmut.pt.kemper.at.gmail.pt.com.firmware.code.agent\\r\\nAccept: * / *\\r\\nAccept-Encoding: deflate\\r\\nAccept-Language: en-US,en;q=1,pt-BR;q=1,pt;q=1\\r\\n\\r\\n--{pt}\\r\\nContent-Disposition: form-data; name="{pt}"\\r\\n\\r\\n{pt}\\r\\n--{pt}--

//0 - página interna do host
//1 - host
//2 - Length
//3 - Boundary
//4 - Boundary
//5 - nome
//6 - dado
//7 - nome
//8 - dado
//9 - Boundary
// constante para dois dados
//POST {pt} HTTP/1.1\\r\\nHost: {pt}\\r\\nContent-Length: {pt}\\r\\nCache-Control: no-cache\\r\\nContent-Type: multipart/form-data; boundary={pt}\\r\\nUser-Agent: helmut.pt.kemper.at.gmail.pt.com.firmware.code.agent\\r\\nAccept: * / *\\r\\nAccept-Encoding: deflate\\r\\nAccept-Language: en-US,en;q=1,pt-BR;q=1,pt;q=1\\r\\n\\r\\n--{pt}\\r\\nContent-Disposition: form-data; name="{pt}"\\r\\n\\r\\n{pt}\\r\\nContent-Disposition: form-data; name="{pt}"\\r\\n\\r\\n{pt}\\r\\n--{pt}--

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    static const char SEND_POST_FORM_ONE_DATA[];
    static const char SEND_FORM_BOUNDARY[];
    static void send ( char d );
    static void endEvent ();
    static void bufferFull ();
    void copy ( const char *p1, char *p2 );
    ~MainWindow();

    const char *pText1;
    static const char text1[];
    static const char text2[];
    static char data[];

    SendToDevice<const char, char, unsigned char, unsigned char> *sd;

  private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void update ();

    void on_pushButton_3_clicked();

  private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
