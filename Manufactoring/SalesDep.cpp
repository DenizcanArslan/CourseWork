#include "SalesDep.h"



SalesDep::SalesDep()
{
}

SalesDep::SalesDep(std::string name) {
	setName(name);
}

SalesDep::~SalesDep()
{
}

std::string SalesDep::toString() 
{

	return getName();

}
