#pragma once
#include "Department.h"
class ProductionDep :
	public Department
{
public:
	ProductionDep();
	ProductionDep(std::string name);
	virtual ~ProductionDep();


	virtual std::string toString();
};

