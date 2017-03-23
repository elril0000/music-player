#pragma once

#include "librarymodel.h"

#include <QDockWidget>
#include <QTreeView>

struct LibraryDock : QDockWidget
{
	LibraryDock();
	
	QTreeView view;
	LibraryModel model;
};
