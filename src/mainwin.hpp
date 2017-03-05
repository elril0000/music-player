#pragma once

#include <iostream>
#include <memory>
#include <QtWidgets>

#include "mediaplayer.hpp"
#include "mediaplaylist.hpp"

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = nullptr);
    ~MainWin();

public slots:
    void next();
    void previous();
    void playPause();
    void stop();
    void mute(bool muted);
    
private:
    void createDock();
    void createActions();
    void createToolBar();
    void createMenus();
    void createStatusBar();
    void createCentralWidget();
    
    QMenu *_fileMenu;
    QMenu *_controlMenu;
    //QMenu *_viewMenu;
    
    //QToolBar *_controlToolBar;
    
    //QDockWidget *_libraryDock;
    
    QAction *_openFileAction;
    QAction *_openFolderAction;
    QAction *_openPlaylistAction;
    QAction *_savePlaylistAction;
    QAction *_quitAction;
    
    QAction *_previousAction;
    QAction *_playPauseAction;
    QAction *_stopAction;
    QAction *_nextAction;
    QAction *_muteAction;
    QAction *_repeatAction;
    QAction *_shuffleAction;
    
    //QSlider *_volumeSlider;
    //QSlider *_seekSlider;
    
    MediaPlayer _mediaPlayer;
    MediaPlaylist _mediaPlaylist;
};

