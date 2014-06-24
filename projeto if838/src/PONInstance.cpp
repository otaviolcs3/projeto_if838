#include "PONInstance.h"

using namespace std;

template<class orderedClass>
bool binarySearch(vector<orderedClass>& array, orderedClass& value, unsigned begin, unsigned end)
{
	/**
	função ainda não testada!
	*/
	if(begin < end)
	{
		unsigned middle = (begin + end) / 2;

		if(array[middle] == value)
			return true;
		else if(array[middle] > value)
			return binarySearch(array, value, begin, middle);
		else
			return binarySearch(array, value, middle, end);
	}
	else
		return false;
}

PONInstance::PONInstance()
{
	//ctor
}

PONInstance::~PONInstance()
{
	//dtor
}

void PONInstance::pushONU(pair<float, float>* onu)
{
	ONUsCoords.push_back(*onu);
}

bool PONInstance::pushSplitterType(unsigned type)
{
	if(!binarySearch(splitterTypes, type, 0, splitterTypes.size()))
	{
		splitterTypes.push_back(type);
		sort(splitterTypes.begin(), splitterTypes.end());
		return true;
	}
	else
		return false;
}

void PONInstance::setCostPerONU(float cost)
{
	costPerONU = cost;
}

void PONInstance::setCostPerSplitterOut(float cost)
{
	costPerSplitterOut = cost;
}

void PONInstance::setCostFiberCable(float cost)
{
	costFiberCable = cost;
}

void PONInstance::setCostDeployment(float cost)
{
	costDeployment = cost;
}

void PONInstance::setMaximalDistance(float distance)
{
	maximalDistance = distance;
}

