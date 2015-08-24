#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../SendToDevice/SendToDevice.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    static void send ( char d );
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
