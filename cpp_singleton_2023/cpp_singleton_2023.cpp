#include <iostream>
#include "dataProcessor.h"
#include "dataOutput.h"

class Singleton
{
private:
	//pointer to a Singleton instance
	static Singleton *instance;
	//private constructor
	Singleton()
	{
		data = 0;
	}

	//data fields
	int           data;
	dataProcessor *dP;
	dataOutput    *dO;

public:
	//getters and setters
	int getData() { return data; }
	void setData(int val) { data = val; }
	void printData() { std::cout << "data=" << getData() << std::endl; }

	void setDataProc(dataProcessor *dProc)
	{
		dP = dProc;
	}

	void setDataOutp(dataOutput *dOut)
	{
		dO = dOut;
	}

	dataProcessor * getInternalDP() { return dP; }
	dataOutput    * getInternalDO() { return dO; }

	//constructor returns static instance by pointer
	static Singleton *getInstance()
	{
		if (!instance)
			instance = new Singleton;
		return instance;
	}
};

//Singleton intialization to null
Singleton *Singleton::instance = 0;

int main()
{
    std::cout << "Initializing singleton 1\n";
	Singleton *s1 = s1->getInstance();
	s1->setData(10);
	s1->printData();
	std::cout << "Initializing singleton 2\n";
	Singleton *s2 = s2->getInstance();
	s2->printData();

	s2->setDataProc(new dataProcessor());
	s2->getInternalDP()->generateDataset(10);

	s2->setDataOutp(new dataOutput(
		{ s2->getInternalDP()->getMin().eVal,
		  s2->getInternalDP()->getMin().eId }, 
		{ s2->getInternalDP()->getMax().eVal,
		  s2->getInternalDP()->getMax().eId }));
	s2->getInternalDO()->printMinMax();
}