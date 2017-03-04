#include "musicplayer.h"
#include "ui_musicplayer.h"

musicplayer::musicplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::musicplayer)
{
    ui->setupUi(this);
}

musicplayer::~musicplayer()
{
    delete ui;
}
