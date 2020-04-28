#pragma once

#include <vector>
#include <iostream>

#include "Person.h"


class Department // Abstrac Class
{
public:
	Department();
	Department(std::string name);

	virtual ~Department();

	std::string getName();
	void setName(std::string name);
	void addPerson(Person* person);
	std::vector<Person*>& getPeople();
	void printAllPeople();
	Person* getMaxSalariedPersonInDepartment();
	


	virtual std::string toString() = 0; // Abstract function- pure virtual function

protected:
	std::string _name;
	std::vector<Person*> _people;
};

