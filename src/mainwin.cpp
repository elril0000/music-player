#include "mainwin.hpp"

MainWin::MainWin(QWidget *parent) : QMainWindow(parent)
{
    _mediaPlaylist = new MediaPlaylist();
    
    _mediaPlayer = new MediaPlayer();
    _mediaPlayer->setVolume(100);
    _mediaPlayer->setPlaylist(_mediaPlaylist);
    
    createActions();
    createMenus();
}

void MainWin::createActions()
{
    _openFileAction = new QAction(tr("Open File"), this);
    _openFolderAction = new QAction(tr("Open Folder"), this);
    _openPlaylistAction = new QAction(tr("Open Playlist"), this);
    _savePlaylistAction = new QAction(tr("Save Playlist"), this);
    _quitAction = new QAction(tr("&Quit"), this);
    
    _previousAction = new QAction(tr("Previous"), this);
    _playPauseAction = new QAction(tr("Play"), this);
    _stopAction = new QAction(tr("Stop"), this);
    _nextAction = new QAction(tr("Next"), this);
    
    _muteAction = new QAction(tr("Mute"), this);
    _muteAction->setCheckable(true);
    _muteAction->setChecked(false);
    
    _repeatAction = new QAction(tr("Repeat"), this);
    _shuffleAction = new QAction(tr("Shuffle"), this);
    
    connect(_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(_previousAction, SIGNAL(triggered()), SLOT(previous()));
    connect(_nextAction, SIGNAL(triggered()), SLOT(next()));
    connect(_playPauseAction, SIGNAL(triggered()), SLOT(playPause()));
    connect(_stopAction, SIGNAL(triggered()), SLOT(stop()));
    connect(_muteAction, SIGNAL(triggered(bool)), SLOT(mute(bool)));
}

void MainWin::createMenus()
{
    _fileMenu = menuBar()->addMenu(tr("File"));
    QList<QAction*> fileActions;
    fileActions << _openFileAction << _openFolderAction << _openPlaylistAction << _savePlaylistAction << _quitAction;
    _fileMenu->addActions(fileActions);
    _fileMenu->insertSeparator(_quitAction);
    
    _controlMenu = menuBar()->addMenu(tr("Control"));
    QList<QAction*> controlAction;
    controlAction << _previousAction << _playPauseAction << _stopAction << _nextAction << _muteAction << _repeatAction << _shuffleAction;
    _controlMenu->addActions(controlAction);
    _controlMenu->insertSeparator(_muteAction);
}


void MainWin::next()
{
    std::cout << "Next" << std::endl;
    _mediaPlaylist->next();
}

void MainWin::previous()
{
    std::cout << "Previous" << std::endl;
    _mediaPlaylist->previous();
}

void MainWin::playPause()
{
    std::cout << "Play or Pause" << std::endl;
    switch(_mediaPlayer->state())
    {
        case QMediaPlayer::StoppedState:
            std::cout << "Play" << std::endl;
            _mediaPlayer->play();
            break;
        case QMediaPlayer::PausedState:
            std::cout << "Play" << std::endl;
            _mediaPlayer->play();
            break;
        case QMediaPlayer::PlayingState:
            std::cout << "Pause" << std::endl;
            _mediaPlayer->pause();
            break;
    }
}

void MainWin::stop()
{
    std::cout << "Stop" << std::endl;
    _mediaPlayer->stop();
}

void MainWin::mute(bool muted)
{
    if(muted)
        std::cout << "Mute" << std::endl;
    else
        std::cout << "Unmute" << std::endl;
    
    _mediaPlayer->setMuted(muted);
}


MainWin::~MainWin()
{
    
}
