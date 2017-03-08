#pragma once

#include <QDockWidget>
#include <QTreeView>

struct LibraryDock : QDockWidget
{
	LibraryDock();
	
	QTreeView view;
};
