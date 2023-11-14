#include "dataOutput.h"

dataOutput::dataOutput(extr inMin, extr inMax)
{
	min = inMin;
	max = inMax;
}

void dataOutput::printMinMax()
{
	std::cout << "Min = " << min.extrVal << "; min id = " << min.extrId <<
		"; Max = " << max.extrVal << "; max id = " << max.extrId << std::endl;
}