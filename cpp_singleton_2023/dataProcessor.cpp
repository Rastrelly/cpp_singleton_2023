#include "dataProcessor.h"

dataProcessor::dataProcessor()
{
	dataSet.clear();
	srand(time(NULL));
}

void dataProcessor::generateDataset(int length)
{
	for (int i = 0; i < length; i++)
	{
		dataSet.push_back((float)(rand()%100)+(float)(rand()%100)/100.0f);
	}
}

bool dataProcessor::checkCond(float a, float b, bool checkLess)
{
	if (checkLess) return a < b;
	else return a > b;
}

dpExtr dataProcessor::getExtr(bool findMin)
{
	dpExtr tmp = { 0.0f,0 };
	if (dataSet.size() > 0)
	{
		float ex = dataSet[0];
		int cId = 0;
		for (int i = 0; i < dataSet.size(); i++)
		{
			if (checkCond(dataSet[i],ex,findMin))
			{
				cId = i;
				ex = dataSet[i];
			}
		}
		tmp.eId = cId;
		tmp.eVal = ex;
		return tmp;
	}
	tmp.eId = -1;
	tmp.eVal = 0.0f;
	return tmp;
}

dpExtr dataProcessor::getMin()
{
	return getExtr(true);
}

dpExtr dataProcessor::getMax()
{
	return getExtr(false);
}