#pragma once

#include <vector>
#include <ctime>

struct dpExtr
{
	float eVal;
	int eId;
};

class dataProcessor
{
private:
	std::vector<float> dataSet;
	bool checkCond(float a, float b, bool checkLess);
	dpExtr getExtr(bool findMin);
public:	
	dataProcessor();
	void generateDataset(int length);	
	dpExtr getMin();
	dpExtr getMax();
};

