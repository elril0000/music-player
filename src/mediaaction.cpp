#include "mediaaction.h"

MediaAction::MediaAction() : 
	previous{QAction::tr("Previous")},
	playPause{QAction::tr("Play")},
	stop{QAction::tr("Stop")},
	next{QAction::tr("Next")},
	mute{QAction::tr("Mute")},
	repeat{QAction::tr("Repeat")},
	shuffle{QAction::tr("Shuffle")}
{
	mute.setCheckable(true);
	mute.setChecked(false);
}
