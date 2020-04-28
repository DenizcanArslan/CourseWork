#pragma once

#include <iostream>
#include <string>

class Person  // Abstract class
{
public:
	Person();
	virtual ~Person();

	std::string getId() const;
	void setId(std::string Id);

	std::string getName() const;
	void setName(std::string Name);

	std::string getSurname() const;
	void setSurname(std::string Surname);

	int getStartYear() const;
	void setStartYear(int StartYear);


	double getBaseSalary() const ;
	void setBaseSalary(double baseSalary);
	virtual double getSalary() const  = 0;  // Abstract function- pure virtual function- for polimorfizm
	virtual std::string toString() = 0; // Abstract function- pure virtual function - for polimorfizm
private:
	std::string  _id;
	std::string  _name;
	std::string  _surname;
	int _startyear;
	double _baseSalary;

};

