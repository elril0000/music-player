#include "librarydock.h"

LibraryDock::LibraryDock() : QDockWidget{tr("Library")}
{
// 	view.setModel();
	setWidget(&view);
	setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
}
