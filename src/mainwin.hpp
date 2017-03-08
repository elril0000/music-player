#pragma once

#include <iostream>
#include <memory>
#include <QtWidgets>

#include "mediaplayer.hpp"
#include "mediaplaylist.hpp"

#include "mediaaction.h"
#include "docks.h"

struct MainWin : QMainWindow
{
	explicit MainWin(QWidget *parent = nullptr);

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
	void setState(MediaPlayer::State state);

	QMenu *_fileMenu;
	QMenu *_controlMenu;
	QMenu *_viewMenu;

	//QToolBar *_controlToolBar;

	
	QListView *_playlistView;
	
	QAction *_openFileAction;
	QAction *_openFolderAction;
	QAction *_openPlaylistAction;
	QAction *_savePlaylistAction;
	QAction *_quitAction;

	Docks docks;
	MediaAction mediaActions;

	//QSlider *_volumeSlider;
	//QSlider *_seekSlider;

	MediaPlayer _mediaPlayer;
	MediaPlaylist _mediaPlaylist;
};

