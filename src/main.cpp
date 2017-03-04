#include "musicplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    musicplayer w;
    w.show();

    return app.exec();
}

