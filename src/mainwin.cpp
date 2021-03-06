#include "mainwin.hpp"

MainWin::MainWin(QWidget *parent) : QMainWindow(parent)
{
	_mediaPlayer.setVolume(100);
	_mediaPlayer.setPlaylist(&_mediaPlaylist);
	
	resize(QSize{1080, 720});
	setState(_mediaPlayer.state());
	
	createActions();
	createDock();
	createMenus();
	createCentralWidget();
	
	connect(&_mediaPlayer, &MediaPlayer::stateChanged, [&](MediaPlayer::State state){ setState(state); });
}

void MainWin::createActions()
{
	_openFileAction = new QAction(tr("Add File"), this);
	_openFolderAction = new QAction(tr("Add Folder"), this);
	_openPlaylistAction = new QAction(tr("Open Playlist"), this);
	_savePlaylistAction = new QAction(tr("Export Playlist"), this);
	_quitAction = new QAction(tr("&Quit"), this);

	connect(_quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
	connect(&mediaActions.previous, &QAction::triggered, [&]{ previous(); });
	connect(&mediaActions.next, &QAction::triggered, [&]{ next(); });
	connect(&mediaActions.playPause, &QAction::triggered, [&]{ playPause(); });
	connect(&mediaActions.stop, &QAction::triggered, [&]{ stop(); });
	connect(&mediaActions.mute, &QAction::triggered, [&](bool m){ mute(m); });
}

void MainWin::createMenus()
{
	_fileMenu = menuBar()->addMenu(tr("File"));
	_fileMenu->addActions({_openFileAction, _openFolderAction, _openPlaylistAction, _savePlaylistAction, _quitAction});
	_fileMenu->insertSeparator(_quitAction);
    
	_controlMenu = menuBar()->addMenu(tr("Control"));
	
	_controlMenu->addActions({
		&mediaActions.previous,
		&mediaActions.playPause,
		&mediaActions.stop,
		&mediaActions.next,
		&mediaActions.mute,
		&mediaActions.repeat,
		&mediaActions.shuffle
	});
	
	_controlMenu->insertSeparator(&mediaActions.mute);
	
	_viewMenu = menuBar()->addMenu(tr("View"));
	_viewMenu->addActions({docks.library.toggleViewAction(), docks.filetree.toggleViewAction()});
}

void MainWin::createDock()
{
	setDockOptions(QMainWindow::AnimatedDocks | 
				   QMainWindow::AllowTabbedDocks | 
				   QMainWindow::ForceTabbedDocks | 
				   QMainWindow::VerticalTabs);
	addDockWidget(Qt::LeftDockWidgetArea, &docks.library);
	addDockWidget(Qt::LeftDockWidgetArea, &docks.filetree);
	tabifyDockWidget(&docks.library, &docks.filetree);
}

void MainWin::createCentralWidget()
{
	QListView *centralView = new QListView(this);
	
	setCentralWidget(centralView);
}

void MainWin::setState(MediaPlayer::State state)
{
	switch(state)
	{
		case MediaPlayer::StoppedState:
			setWindowTitle(tr("Stopped - Music Player"));
			break;
			
		case MediaPlayer::PausedState:
			setWindowTitle(tr("Pause - Music Player"));
			break;
			
		case MediaPlayer::PlayingState:
			setWindowTitle(tr("Playing - Music Player"));
			break;
	}
}


void MainWin::next()
{
	std::cout << "Next" << std::endl;
	_mediaPlaylist.next();
}

void MainWin::previous()
{
	std::cout << "Previous" << std::endl;
	_mediaPlaylist.previous();
}

void MainWin::playPause()
{
	std::cout << "Play or Pause" << std::endl;
	switch(_mediaPlayer.state())
	{
		case QMediaPlayer::StoppedState:
			std::cout << "Play" << std::endl;
			_mediaPlayer.play();
			break;
		case QMediaPlayer::PausedState:
			std::cout << "Play" << std::endl;
			_mediaPlayer.play();
			break;
		case QMediaPlayer::PlayingState:
			std::cout << "Pause" << std::endl;
			_mediaPlayer.pause();
			break;
	}
}

void MainWin::stop()
{
	std::cout << "Stop" << std::endl;
	_mediaPlayer.stop();
}

void MainWin::mute(bool muted)
{
	if(muted)
		std::cout << "Mute" << std::endl;
	else
		std::cout << "Unmute" << std::endl;

	_mediaPlayer.setMuted(muted);
}
