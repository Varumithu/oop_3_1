#include "persons.h"


person& person::operator = (const person& that) {
	if (&that != this) {
		delete[] name;
		char* name = new char[strlen(that.name) + 1];
		std::copy(that.name, that.name + strlen(that.name) + 1, name);
		age = that.age;
		return *this;
	}
	else {
		return *this;
	}
}

person::person(const person & p) {
	this->name = new char [std::strlen(p.name) + 1];
	std::copy(p.name, p.name + std::strlen(p.name) + 1, this->name);
	this->age = p.age;
}

person& person::set(const char* pname, int age) {
	delete[] this->name;
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

person::person() {
	name = nullptr;
	age = 0;
};

const char* person::get_name() const {
	return this->name;
}

int person::get_age() const {
	return this->age;
}

person::~person() {
	delete[] name;
}