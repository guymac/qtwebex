#include <QApplication>
#include "mainwindow.hh"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWin win;
    win.show();
    return app.exec();
}