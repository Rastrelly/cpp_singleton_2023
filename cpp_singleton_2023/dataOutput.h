#pragma once

#include <iostream>

struct extr { float extrVal; int extrId; };

class dataOutput
{
private:
	extr min, max;
public:
	dataOutput(extr inMin, extr inMax);
	void printMinMax();
};

