#ifndef PERSONDOTH
#define PERSONDOTH

#include <string>
#include <iostream>
#include <memory>
#include <algorithm>



class person final{
public:
	person();
	const char* get_name() const;
	int get_age() const;
	person(const person & p);
	person& set(const char* pname, int age);
	~person();
	person& operator = (const person& that);
private:
	char* name;
	int age;
};

std::ostream & operator <<(std::ostream & os, const person & p);



#endif