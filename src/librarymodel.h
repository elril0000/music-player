#pragma once

#include <QModelIndex>
#include <type_traits>

#include "libraryroot.h"
#include "libraryalbum.h"
#include "libraryartist.h"
#include "librarysong.h"

struct LibraryModel : QAbstractItemModel {
	using QAbstractItemModel::QAbstractItemModel;
	
	QModelIndex parent(const QModelIndex & child) const override;
	int columnCount(const QModelIndex & parent) const override;
	QVariant data(const QModelIndex & index, int role) const override;
	QModelIndex index(int row, int column, const QModelIndex & parent) const override;
	int rowCount(const QModelIndex & parent) const override;
	
private:
	LibraryRoot root;
	
	template<typename T>
	std::common_type_t<
		std::result_of_t<T(LibraryRoot&)>,
		std::result_of_t<T(LibraryArtist&)>,
		std::result_of_t<T(LibraryAlbum&)>,
		std::result_of_t<T(LibrarySong&)>>
	static visitIndex(const QModelIndex& parent, T visitor) {
		if (!parent.isValid()) {
			return visitor(*static_cast<LibraryRoot*>(parent.internalPointer()));
		} else if (!parent.parent().isValid()) {
			return visitor(*static_cast<LibraryArtist*>(parent.internalPointer()));
		} else if (!parent.parent().parent().isValid()) {
			return visitor(*static_cast<LibraryAlbum*>(parent.internalPointer()));
		} else {
			return visitor(*static_cast<LibrarySong*>(parent.internalPointer()));
		}
	}
};
