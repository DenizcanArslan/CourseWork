#pragma once

#include <iostream>
#include <string>
#include "Person.h"

class Staff :
	public Person
{
public:
	Staff();
	Staff(std::string Id, std::string Name, std::string Surname);
	virtual ~Staff();

	friend std::ostream& operator<<(std::ostream& out, const Staff& person);

	virtual double getSalary() const;
	virtual std::string toString();
};

