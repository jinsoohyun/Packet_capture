#include "mainwindow.h"
#include <QApplication>

MainWindow *w;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    w = new MainWindow();
    w->setWindowTitle(QString::fromUtf8("QT_Packet_Capture_by jsh"));
    w->show();

    return a.exec();
}






