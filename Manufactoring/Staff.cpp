#include <iostream>
#include <string>
#include "Staff.h"



Staff::Staff()
{
	setId("-");
	setName("-");
	setSurname("-");
	setBaseSalary(0);
	setStartYear(0);

}
Staff::Staff(std::string Id, std::string Name, std::string Surname) 
{
	setId(Id);
	setName(Name);
	setSurname(Surname);
	setBaseSalary(0);
	setStartYear(0);
}


Staff::~Staff()
{
}


double Staff::getSalary() const
{
	return getBaseSalary();
}


std::string Staff::toString() 
{
	return "Id: " + getId() +
		", Name: " + getName() +
		", Surname: " + getSurname() +
		", StartYear: " + std::to_string(getStartYear()) + 
		", Salary : " + std::to_string(getSalary());


}
