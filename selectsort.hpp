#ifndef SELTEMPSORTDOTH
#define SELTEMPSORTDOTH

#include <utility>
#include <iostream>

template <class ForwardIterator, class Compare>
void select_sort(ForwardIterator first, ForwardIterator last, Compare comp){
	ForwardIterator maxit;
	for (ForwardIterator curfirst = first; curfirst != last; ++curfirst) {
		maxit = curfirst;
		for (ForwardIterator cur = curfirst; cur != last; ++cur) {
			if (comp(*cur, *maxit) == true) {
				maxit = cur;
			}
		}
		std::swap(*curfirst, *maxit);
		
	}
}

template <typename it>
void print_arr (it first, it last, std::ostream & os) {
	for (it cur = first; cur != last; ++cur) {
		os << *cur << ' ';
	}
}

#endif