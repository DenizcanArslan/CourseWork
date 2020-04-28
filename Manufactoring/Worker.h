#pragma once

#include <iostream>
#include <string>

#include "Person.h"

class Worker :
	public Person
{
public:
	Worker();
	Worker(std::string Id, std::string Name, std::string Surname);
	
	virtual ~Worker();


	friend std::ostream& operator<<(std::ostream& out, const Worker& person);

	virtual double getSalary() const;
	virtual std::string toString();

	double getOvertime() const;
	void setOvertime(double overtime);
	double getHourlyovertimepay() const;
	void setHourlyovertimepay(double hourlyovertimepay);




private:
	double _hourlyovertimepay;
	double _overtime;

};

