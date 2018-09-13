#ifndef PERSONDOTH
#define PERSONDOTH

#include <string>
#include <iostream>
#include <memory>
#include <algorithm>



class person final{
public:
	person() {
		name = nullptr; 
		age = 0; 
	};
	const char* get_name() const {
		return this->name;
	}
	int get_age() const {
		return this->age;
	}
	person(const person & p);
	person& set(const char* pname, int age);
	~person() { 
		delete[] name;
	}
	person& operator = (const person& that);
private:
	char* name;
	int age;
};

std::ostream & operator <<(std::ostream & os, const person & p);



#endif