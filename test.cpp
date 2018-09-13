#include "selectsort.hpp"
#include "persons.h"

#include <iostream>
#include <string>

#include <gtest/gtest.h>

bool my_comp(int a, int b) {
	return a < b;
}

bool p_a_comp(const person & a, const person & b) {
	return a.get_age() < b.get_age();
}

bool p_n_comp(const person & a, const person & b) {
	return std::strcmp(a.get_name(), b.get_name()) < 0;
}

bool int_array_equal(int* a, int* b, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool person_array_equal(person* a, person* b, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (std::strcmp(a[i].get_name(), b[i].get_name()) != 0) {
			return false;
		}
	}
	return true;
}

TEST(TestTempSelsort, IntTest) {
	int arr[] = { 5, 10, 54, 2, 12, 7, 3, 1, 76, 8 };
	int check[] = { 1, 2, 3, 5, 7, 8, 10, 12, 54, 76 };
	select_sort(arr, arr + 10, my_comp);
	bool flag = int_array_equal(arr, check, 10);
	ASSERT_TRUE(flag);
}

TEST(TestTempSelsort, StructWithPointerTest) {
	char a[] = "ahdf";
	char b[] = "baa";
	char c[] = "cc";
	char d[] = "dd";
	char e[] = "eeeee";
	person p[5];
	p[0].set(a, 1);
	p[1].set(e, 4);
	p[2].set(c, 16);
	p[3].set(b, 2);
	p[4].set(d, 3);
	person check[5];
	check[0].set(a, 1);
	check[1].set(b, 4);
	check[2].set(c, 16);
	check[3].set(d, 2);
	check[4].set(e, 3);
	select_sort(p, p + 5, p_n_comp);
	ASSERT_TRUE(person_array_equal(p, check, 5));
}

int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}