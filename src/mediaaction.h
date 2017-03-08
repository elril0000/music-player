#pragma once

#include <QAction>

struct MediaAction
{
	MediaAction();
	
	QAction previous;
	QAction playPause;
	QAction stop;
	QAction next;
	QAction mute;
	QAction repeat;
	QAction shuffle;
};
