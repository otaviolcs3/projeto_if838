#include "../include/PONInstance.h"
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

/*template<class orderedClass>
bool binarySearch(vector<orderedClass>& array, orderedClass& value, unsigned begin, unsigned end)
{

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
}*/

PONInstance::PONInstance()
{
	//ctor
}

PONInstance::~PONInstance()
{
	//dtor
}

void PONInstance::pushONU(const Point& onu)
{
	ONUsCoords.push_back(onu);
}

bool PONInstance::pushSplitterType(unsigned type)
{
	if(!binary_search(splitterTypes.begin(), splitterTypes.end(), type))
	{
		splitterTypes.push_back(type);
		sort(splitterTypes.begin(), splitterTypes.end());
		return true;
	}
	else
		return false;
}

void PONInstance::setCostPerONU(double cost)
{
	costPerONU = cost;
}

void PONInstance::setCostPerSplitterOut(double cost)
{
	costPerSplitterOut = cost;
}

void PONInstance::setCostFiberCable(double cost)
{
	costFiberCable = cost;
}

void PONInstance::setCostDeployment(double cost)
{
	costDeployment = cost;
}

void PONInstance::setMaximalDistance(double distance)
{
	maximalDistance = distance;
}

double absDistance(const Point& p1, const Point& p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

double euclidianDistance(const Point& p1, const Point& p2)
{
	double x = p1.first - p2.first, y = p1.second - p2.second;
	return sqrt(x * x + y * y);
}

bool PONInstance::isFeasible(Dist dist)
{
	bool flag = true;
	double distance_value;

	for(unsigned i = 0, size = ONUsCoords.size(); (i < size) && flag; i++)
	{
	    distance_value = dist(ONUsCoords[i], centralOfficeCoords);

        flag = ( distance_value <= maximalDistance);
        flag = flag && ( distance_value >= minimalDistance);
	}

	return flag;
}

bool PONInstance::isFeasible()
{
	return PONInstance::isFeasible(absDistance);
}

bool PONInstance::isRelaxedFeasible()
{
	return PONInstance::isFeasible(euclidianDistance);
}

const Point& PONInstance::getCentralOfficeCoords()
{
	return centralOfficeCoords;
}

const Point& PONInstance::getONUCoords(unsigned index)
{
	return ONUsCoords[index];
}

unsigned PONInstance::getSplitterType(unsigned index)
{
	return splitterTypes[index];
}



