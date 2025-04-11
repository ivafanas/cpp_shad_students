#include "MainWidget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWidget wgt;
    wgt.show();

    return app.exec();
}

