#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include <thread_test.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Packet_data(char *s_mac, char* d_mac, char* e_type, char* s_ip, char * d_ip, char * ip_type, char* s_port, char* d_port);

private:
    Ui::MainWindow *ui;
    Thread_test* m_thread;

    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader;
};

#endif // MAINWINDOW_H
