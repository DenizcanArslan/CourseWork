#include <iostream>
#include <vector>
#include <string>

#include "Department.h"



Department::Department()
{
}

Department::Department (std::string name) {
	_name = name;

}

Department::~Department() // Destructor
{
}


std::string Department::getName() 
{
	return _name;
}

void Department::setName(std::string name) 
{
	_name = name;
}

void Department::addPerson(Person* person) 
{

	_people.push_back(person);
}

std::vector<Person*>& Department::getPeople() 
{
	return _people;
}

void Department::printAllPeople()
{
	Person* person;

	for (int i = 0; i < _people.size(); i++)
	{
		person = _people[i];
		std::cout << _people[i]->toString() << std::endl;
	}
}


Person*  Department::getMaxSalariedPersonInDepartment()
{
	if (_people.size() > 0) {
		Person* MaxSalariedPerson = _people[0];
		for (int i = 0; i < _people.size(); i++)
		{
			if (_people[i]->getSalary() > MaxSalariedPerson->getSalary()) {
				MaxSalariedPerson = _people[i];
			}
		}
		return MaxSalariedPerson;
	}
	else {
		return NULL;
	}

}

