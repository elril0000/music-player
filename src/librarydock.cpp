#include "librarydock.h"

LibraryDock::LibraryDock() : QDockWidget{tr("Library")}
{
	setWidget(&view);
	setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
}
