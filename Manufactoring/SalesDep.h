#pragma once
#include "Department.h"
class SalesDep :
	public Department
{
public:
	SalesDep();
	SalesDep(std::string name);
	~SalesDep();

	virtual std::string toString();
};

