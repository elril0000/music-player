#pragma once

#include <QFileSystemModel>
#include <QDockWidget>
#include <QTreeView>

struct FileTreeDock : QDockWidget
{
	FileTreeDock();
	
	QFileSystemModel model;
	QTreeView view;
};
