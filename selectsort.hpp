#ifndef SELTEMPSORTDOTH
#define SELTEMPSORTDOTH

#include <utility>
#include <iostream>

template <class RandomAccessIterator, class Compare>
void select_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
	RandomAccessIterator maxit;
	for (RandomAccessIterator curfirst = first; curfirst != last; ++curfirst) {
		maxit = curfirst;
		for (RandomAccessIterator cur = curfirst; cur != last; ++cur) {
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