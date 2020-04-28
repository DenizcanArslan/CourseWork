#include <iostream>
#include <string>

#include "Worker.h"


Worker::Worker()
{
	setId("-");
	setName("-");
	setSurname("-");
	setBaseSalary(0);
	setStartYear(0);
}

Worker::Worker(std::string Id, std::string Name, std::string Surname)
{

	setId(Id);
	setName(Name);
	setSurname(Surname);
	setBaseSalary(0);
	setStartYear(0);
}


Worker::~Worker()
{
}


double Worker::getSalary() const
{
	return getBaseSalary() + getOvertime() * getHourlyovertimepay();
}

std::string Worker::toString() 
{
	return "Id: " + getId() +
		", Name: " + getName() +
		", Surname: " + getSurname() +
		", StartYear: " + std::to_string(getStartYear()) +
		", Salary : " + std::to_string(getSalary()) +
		", Overtime: " + std::to_string(getOvertime()) +
		", HourlyOvertimepay: " + std::to_string(getHourlyovertimepay());
}


double Worker::getOvertime()  const
{
	return _overtime;
}

void Worker::setOvertime(double overtime)
{
	_overtime = overtime;
}

double Worker::getHourlyovertimepay() const
{
	return _hourlyovertimepay;
}

void Worker::setHourlyovertimepay(double hourlyovertimepay)
{
	_hourlyovertimepay = hourlyovertimepay;
}
