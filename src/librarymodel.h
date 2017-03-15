#pragma once

#include <QModelIndex>
#include <type_traits>

#include "libraryalbum.h"
#include "libraryartist.h"
#include "librarysong.h"

struct LibraryModel {
	
private:
	template<typename T>
	std::common_type_t<
		std::result_of_t<T(LibraryArtist)>,
		std::result_of_t<T(LibraryAlbum)>,
		std::result_of_t<T(LibrarySong)>>
	visitIndex(const QModelIndex& parent, T visitor) {
		if (!parent.isValid()) {
			return visitor(*static_cast<LibraryArtist*>(parent.internalPointer()));
		} else if (parent.parent().isValid()) {
			return visitor(*static_cast<LibraryAlbum*>(parent.internalPointer()));
		} else {
			return visitor(*static_cast<LibrarySong*>(parent.internalPointer()));
		}
	}
};
