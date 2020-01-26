#include "SalesmanWidget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SalesmanWidget wgt;
    wgt.show();

    return app.exec();
}

