#pragma once

#include <iostream>
#include <string>
#include "Person.h"

class SalesPerson :
	public Person
{
public:
	SalesPerson();
	SalesPerson(std::string Id, std::string Name, std::string Surname);
	virtual ~SalesPerson();

	friend std::ostream& operator<<(std::ostream& out, const SalesPerson& person);

	double getTotalSales() const;
	void setTotalSales(double TotalSales);
	double getCommissionRate() const;
	void setCommissionRate(double Commissionrate);

	virtual double getSalary() const;
	virtual std::string toString();

private:
	double _totalsales;
	double _commissionrate;
};

