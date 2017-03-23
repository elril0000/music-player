#include "librarymodel.h"

#include "overloadset.h"

int LibraryModel::columnCount(const QModelIndex& parent) const {
	return 1;
}

QVariant LibraryModel::data(const QModelIndex& index, int role) const {
	
}

QModelIndex LibraryModel::index(int row, int column, const QModelIndex& parent) const {
	
}

QModelIndex LibraryModel::parent(const QModelIndex& child) const {
	
}

int LibraryModel::rowCount(const QModelIndex& parent) const {
	return visitIndex(parent, overload(
		[](LibraryRoot& r){ return r.artists.size(); },
		[](LibraryArtist& a){ return a.albums.size(); },
		[](LibraryAlbum& a){ return a.songs.size(); },
		[](auto&){ return 0; }
	));
}
