#include "ProductionDep.h"



ProductionDep::ProductionDep()
{
}

ProductionDep::ProductionDep(std::string name) 
{
	setName(name);

}

ProductionDep::~ProductionDep()
{
}

std::string ProductionDep::toString() 
{

	return getName();

}