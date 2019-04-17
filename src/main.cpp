#include "FramelessWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FramelessWindow wndw;
    wndw.show();

    return app.exec();
}