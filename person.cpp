#include "persons.h"


person& person::operator = (const person& that) {
	if (&that != this) {
		delete[] name;
		size_t namelen = strlen(that.name) + 1;
		char* name = new char[namelen];
		std::copy(that.name, that.name + namelen, name);
		age = that.age;
		return *this;
	}
	else {
		return *this;
	}
}

person::person(const person & p) {
	size_t namelen = strlen(p.name) + 1;
	this->name = new char [namelen];
	std::copy(p.name, p.name + namelen, this->name);
	this->age = p.age;
}

person& person::set(const char* pname, int age) {
	delete[] this->name;
	size_t namelen = strlen(pname) + 1;
	name = new char[namelen];
	std::copy(pname, pname + namelen, name); 
	this->age = age;
	return *this;
};

std::ostream & operator <<(std::ostream & os, const person & p) {
	size_t namelen = strlen(p.get_name());
	for (size_t i = 0; i < namelen; ++i) {
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