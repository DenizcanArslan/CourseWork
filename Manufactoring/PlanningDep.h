#pragma once

#include <iostream>
#include <string>
#include "Department.h"

class PlanningDep :
	public Department
{
public:
	PlanningDep();
	PlanningDep(std::string name);
	~PlanningDep();



	virtual std::string toString();
};

