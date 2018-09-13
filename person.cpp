#include "persons.h"


person& person::operator = (const person& that) {
	char* local_name = new char[strlen(that.name) + 1];
	std::copy(that.name, that.name + strlen(that.name) + 1, local_name);
	delete[] name;
	name = local_name;
	age = that.age;
	return *this;
}

person::person(const person & p) {
	const int temp = std::strlen(p.name);
	this->name = new char [std::strlen(p.name) + 1];
	std::copy(p.name, p.name + std::strlen(p.name) + 1, this->name);
	this->age = p.age;
}

person& person::set(const char* pname, int age) {
	if (name != nullptr) {
		delete[] this->name;
	}
	name = new char[strlen(pname) + 1];
	std::copy(pname, pname + std::strlen(pname) + 1, name); 
	this->age = age;
	return *this;
};

std::ostream & operator <<(std::ostream & os, const person & p) {
	for (size_t i = 0; i < std::strlen(p.get_name()); ++i) {
		os << p.get_name()[i];
	}
	os << ' ' << p.get_age() << ';';
	return os;
}