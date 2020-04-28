#include <iostream>
#include<string>
#include "Person.h"



Person::Person()
{
}


Person::~Person()
{
}


std::string Person::getId() const
{
	return _id;
}

void Person::setId(std::string Id) 
{
	_id = Id;
}

std::string Person::getName() const
{
	return _name;
}

void Person::setName(std::string Name) 
{
	_name = Name;
}

std::string Person::getSurname() const
{
	return _surname;
}

void Person::setSurname(std::string Surname) 
{
	_surname = Surname;
}

int Person::getStartYear() const 
{
	return _startyear;
}

void Person::setStartYear(int StartYear) 
{
	_startyear = StartYear;
}


double Person::getBaseSalary() const
{
	return _baseSalary;
}

void Person::setBaseSalary(double baseSalary) 
{
	_baseSalary = baseSalary;
}
