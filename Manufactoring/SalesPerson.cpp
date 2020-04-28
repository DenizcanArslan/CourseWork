#include <iostream>
#include <string>
#include "SalesPerson.h"

SalesPerson::SalesPerson()
{
	setId("-");
	setName("-");
	setSurname("-");
	setStartYear(0);
	setBaseSalary(0);
	setTotalSales(0);
	setCommissionRate(0);
}
SalesPerson::SalesPerson(std::string Id, std::string Name, std::string Surname) 
{
	setId(Id);
	setName(Name);
	setSurname(Surname);
	setStartYear(0);
	setBaseSalary(0);
	setTotalSales(0);
	setCommissionRate(0);
}

SalesPerson::~SalesPerson()
{

}


double SalesPerson::getTotalSales() const
{
	return _totalsales;
}

void SalesPerson::setTotalSales(double TotalSales) 
{
	_totalsales = TotalSales;
}

double SalesPerson::getCommissionRate() const
{
	return _commissionrate;
}

void SalesPerson::setCommissionRate(double Commissionrate) 
{
	_commissionrate = Commissionrate;
}

double SalesPerson::getSalary() const
{
	return getBaseSalary() + getTotalSales()* getCommissionRate();
}

std::string SalesPerson::toString() {
	return "Id: " + getId() + 
		", Name: " + getName() + 
		", Surname: " + getSurname() + 
		", StartYear: " + std::to_string(getStartYear()) +
		", Salary : " + std::to_string(getSalary())+ 
		", TotalSales: "+ std::to_string(getTotalSales()) + 
		", CommissionRate: " + std::to_string( getCommissionRate()) ;
}
