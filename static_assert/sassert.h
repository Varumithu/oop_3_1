
//
//template <typename T>
//void my_static_assert_eq(T&& arg1, T&& arg2) {
//	bool b = (arg1 == arg2);
//	char[] test;
//}

template <bool arg>
void my_static_assert_true() {
	char test[arg];
}