#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> 

#include "Person.h"
#include "SalesPerson.h"
#include "Worker.h"
#include "Staff.h"
#include "Department.h"
#include "SalesDep.h"
#include "ProductionDep.h"
#include "PlanningDep.h"

using namespace std;

void ReadFile(vector<Department*>& departments);

void printAllDepartments(vector<Department*> &departments);
void printAllDepartmentPeople(vector<Department*> &departments);


Department* findDepartment(vector<Department*>& departments, string DepartmentName);
Person* maxSalariedPerson(vector<Department*> &departments);
std::vector<Person*>*  getOldestPeople(vector<Department*> &departments);


int main()
{
	vector<Department*> departments;

	ReadFile(departments);
	cout << "File Read Completed!"<<endl;
	cout << endl;

	cout << "All departments and People" << endl;
	printAllDepartmentPeople(departments);


	cout << endl;
	cout << "Max Salaried People " << endl;

	Person* maxsalaried = maxSalariedPerson(departments);
	if (maxsalaried != NULL) {
		cout << maxsalaried->toString()<<endl;
	}

	cout << endl;

	cout << "Oldest  People List " << endl;

	std::vector<Person*>*  oldestpeople = getOldestPeople(departments);
	Person* currentperson;
	for (int i = 0; i < oldestpeople->size(); i++) {
		currentperson = (*oldestpeople)[i];
		cout << currentperson->toString()<< endl;
	}

	cout << "Press enter to exit"<<endl;
	getchar();
	return 0;
}


void ReadFile(vector<Department*>& departments)
{
	std::ifstream ifs("Manufactoring.txt", std::ifstream::in);
	string DepType;
	string DepartmentName;
	string PersonType;
	string Id;
	string Name;
	string Surname;
	int StartYear;
	double BaseSalary;
	double TotalSales;
	double CommissionRate;
	double Overtime;
	double HourlyOvertimePay;
	char line[301];
	ifs.getline(line, 300);
	SalesDep* salesdep = NULL;
	ProductionDep* productiondep = NULL;
	PlanningDep* planningdep = NULL;
	Person* person = NULL;
	Staff* staff = NULL;
	SalesPerson* salesperson = NULL;
	Worker* worker = NULL;
	while (!ifs.eof())
	{
		ifs >> DepType >> DepartmentName >> PersonType >>
			Id >> Name >> Surname >> StartYear >> BaseSalary >>
			TotalSales >> CommissionRate >> Overtime >> HourlyOvertimePay;

		Department* dep = findDepartment(departments, DepartmentName);
		if (dep == NULL) {
			if (DepType == "PlanningDep")
			{
				planningdep = new PlanningDep(DepartmentName);
				dep = planningdep;
			}
			else if (DepType == "ProductionDep")
			{
				productiondep = new ProductionDep(DepartmentName);
				dep = productiondep;
			}
			else if (DepType == "SalesDep")
			{
				salesdep = new SalesDep(DepartmentName);
				dep = salesdep;
			}
			departments.push_back(dep);
		}

		if (PersonType == "Staff")
		{
			staff = new Staff(Id, Name, Surname);
			staff->setBaseSalary(BaseSalary);
			staff->setStartYear(StartYear);

			person = staff;
		}
		else if (PersonType == "Worker")
		{
			worker = new Worker(Id, Name, Surname);
			worker->setBaseSalary(BaseSalary);
			worker->setStartYear(StartYear);
			worker->setOvertime(Overtime);
			worker->setHourlyovertimepay(HourlyOvertimePay);

			person = worker;
		}
		else if (PersonType == "SalesPerson")
		{
			salesperson = new SalesPerson(Id, Name, Surname);
			salesperson->setBaseSalary(BaseSalary);
			salesperson->setStartYear(StartYear);
			salesperson->setTotalSales(TotalSales);
			salesperson->setCommissionRate(CommissionRate);

			person = salesperson;
		}
		dep->addPerson(person);

	}

}



void printAllDepartments(vector<Department*> &departments)
{
	for (int i = 0; i < departments.size(); i++)
	{
		cout << departments[i]->getName() << endl;
	}
}

void printAllDepartmentPeople(vector<Department*> &departments)
{
	for (int i = 0; i < departments.size(); i++)
	{
		cout << departments[i]->getName() << " people " << endl;
		departments[i]->printAllPeople();
		cout << endl;
	}
}


Department* findDepartment(vector<Department*>& departments, string DepartmentName)
{
	for (int i = 0; i < departments.size(); i++)
	{
		if (departments[i]->getName() == DepartmentName) {
			return departments[i];
		}
	}
	return NULL;
}



Person* maxSalariedPerson(vector<Department*> &departments)
{
	if (departments.size() > 0) {
		Department* dep = departments[0];
		Person* maxsalaried = dep->getMaxSalariedPersonInDepartment();
		Person* currentperson;
		for (int i = 1; i < departments.size(); i++)
		{
			currentperson = departments[i]->getMaxSalariedPersonInDepartment();
			if (currentperson != NULL) {
				if (currentperson->getSalary() > maxsalaried->getSalary()) {
					maxsalaried = currentperson;
				}
			}
			
		}
		return maxsalaried;
	}
	else {
		return NULL;
	}
}


std::vector<Person*>*  getOldestPeople(vector<Department*> &departments)
{
	// There may be many people who started in the same year.

	std::vector<Person*>* oldestpeople = new std::vector<Person*>();
	if (departments.size() > 0)
	{
		Department* currentdep=NULL ;
		Person* currentperson=NULL;
		int oldeststartyear = 99999;
		// First, find the oldest people year
		for (int i = 0; i < departments.size(); i++) {
			currentdep = departments[i];
			for (int j = 0; j < currentdep->getPeople().size(); j++) {
				currentperson = currentdep->getPeople()[j];
				if (currentperson->getStartYear() < oldeststartyear) {
					oldeststartyear = currentperson->getStartYear();
				}
			}
		}

		// add all people with the same oldes start year  to the oldestpeople vector
		for (int i = 0; i < departments.size(); i++) {
			currentdep = departments[i];
			for (int j = 0; j < currentdep->getPeople().size(); j++) {
				currentperson = currentdep->getPeople()[j];
				if (currentperson->getStartYear() == oldeststartyear) {
					oldestpeople->push_back(currentperson);
				}
			}
		}

	}

	return oldestpeople;
	
	
	
}


ostream& operator<<(ostream& out, const Staff &person)
{
	out << person.getId() << " " << person.getName() << " " << person.getSurname();

	return out;
}


ostream &operator<<(ostream& out, const SalesPerson& person)
{
	
	out << person.getId() <<  " " << person.getName() << " " << person.getSurname();
	
	return out;
}


ostream& operator<<(ostream& out, const Worker &person)
{
	out << person.getId() << " " << person.getName() << " " << person.getSurname();

	return out;
}
