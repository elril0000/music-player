#pragma once

#include <utility>

namespace detail {

template<typename, typename...>
struct OverloadSet;


template<typename Last>
struct OverloadSet<Last> : Last {
	explicit OverloadSet(Last last) : Last{std::move(last)} {}
	
	using Last::operator();
};

template<typename Head, typename... Tail>
struct OverloadSet : Head, OverloadSet<Tail...> {
	explicit OverloadSet(Head head, Tail... tail) : Head{std::move(head)}, OverloadSet<Tail...>{std::move(tail)...} {}
	
	using Head::operator();
	using OverloadSet<Tail...>::operator();
};

}

template<typename... Args>
auto overload(Args&&... args) {
	return detail::OverloadSet<std::remove_reference_t<Args>...>{std::forward<Args>(args)...};
}
