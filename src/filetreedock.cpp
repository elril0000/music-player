#include "filetreedock.h"

#include <QStandardPaths>

FileTreeDock::FileTreeDock() : QDockWidget{tr("File Tree")}
{
	model.setRootPath(QStandardPaths::displayName(QStandardPaths::MusicLocation));
	view.setModel(&model);
	setWidget(&view);
	setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	setVisible(false);
}
