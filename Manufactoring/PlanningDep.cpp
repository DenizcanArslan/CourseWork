#include "PlanningDep.h"



PlanningDep::PlanningDep()
{
	setName("-");
}

PlanningDep::PlanningDep(std::string name) 
{
	setName(name);

}

PlanningDep::~PlanningDep()
{
}


std::string PlanningDep::toString() 
{

	return getName();

}