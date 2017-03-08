#include "mainwin.hpp"

MainWin::MainWin(QWidget *parent) : QMainWindow(parent)
{
	_mediaPlayer.setVolume(100);
	_mediaPlayer.setPlaylist(&_mediaPlaylist);

	createActions();
	createDock();
	createMenus();
	createCentralWidget();
}

void MainWin::createActions()
{
	_openFileAction = new QAction(tr("Open File"), this);
	_openFolderAction = new QAction(tr("Open Folder"), this);
	_openPlaylistAction = new QAction(tr("Open Playlist"), this);
	_savePlaylistAction = new QAction(tr("Save Playlist"), this);
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
	_viewMenu->addActions({_libraryDock->toggleViewAction(), _fileTreeDock->toggleViewAction()});
}

void MainWin::createDock()
{
	setDockOptions(QMainWindow::AnimatedDocks | 
				   QMainWindow::AllowTabbedDocks | 
				   QMainWindow::ForceTabbedDocks | 
				   QMainWindow::VerticalTabs);
	QTreeView *tree = new QTreeView(this);
	
	_libraryDock = new QDockWidget(tr("Library"), this);
	_libraryDock->setWidget(tree);
	_libraryDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	addDockWidget(Qt::LeftDockWidgetArea, _libraryDock);
	
	QFileSystemModel *fileTreeModel = new QFileSystemModel(this);
	fileTreeModel->setRootPath(QStandardPaths::displayName(QStandardPaths::MusicLocation));
	QTreeView *fileTreeView = new QTreeView(this);
	fileTreeView->setModel(fileTreeModel);
	
	_fileTreeDock = new QDockWidget(tr("File Tree"), this);
	_fileTreeDock->setWidget(fileTreeView);
	_fileTreeDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	addDockWidget(Qt::LeftDockWidgetArea, _fileTreeDock);
	tabifyDockWidget(_libraryDock, _fileTreeDock);
	_libraryDock->raise();
	_fileTreeDock->setVisible(false);
}

void MainWin::createCentralWidget()
{
	QListView *centralView = new QListView(this);
	
	setCentralWidget(centralView);
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


MainWin::~MainWin()
{
    
}
