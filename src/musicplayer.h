#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>

namespace Ui {
class musicplayer;
}

class musicplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit musicplayer(QWidget *parent = 0);
    ~musicplayer();

private:
    Ui::musicplayer *ui;
};

#endif // MUSICPLAYER_H
