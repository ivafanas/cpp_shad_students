#include "PalindromeWidget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PalindromeWidget wgt;
    wgt.show();

    return app.exec();
}

