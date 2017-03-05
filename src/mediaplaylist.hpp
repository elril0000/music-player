#pragma once

#include <QMediaPlaylist>

struct MediaPlaylist : public QMediaPlaylist
{
	explicit MediaPlaylist(QObject *parent = nullptr);
    
private:
    
};
