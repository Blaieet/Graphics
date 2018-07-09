#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("ZBuffer GPU De Blai Alex i Jordi");
    w.show();

    return a.exec();
}
