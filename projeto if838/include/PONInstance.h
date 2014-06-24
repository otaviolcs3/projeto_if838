#ifndef PONINSTANCE_H
#define PONINSTANCE_H

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <assert>

using namespace std;

template<class orderedClass>  bool binarySearch(vector<orderedClass>& array, orderedClass& value, unsigned begin, unsigned end);

class PONInstance
{
	public:
		PONInstance();
		virtual ~PONInstance();

		bool isInfeasible();
		bool relaxedIsInfeasible();

		void pushONU(pair<float, float>*);
		void pushSplitterType(unsigned);

		void setCostPerONU(float);
		void setCostPerSplitterOut(float);
		void setCostFiberCable(float);
		void setCostDeployment(float);
		void setMaximalDistance(float);

		/*pair<float, float>& getCentralOfficeCoords();
		pair<float, float>& getONUCoords(int index);
		unsigned getSplitterType(int index);*/

	protected:

	private:
		pair<float, float> centralOfficeCoords;
		vector<pair<float float> > ONUsCoords;       //coordenadas do central office
		vector<unsigned> splitterTypes;
		float costPerONU, costPerSplitterOut;
		float costFiberCable, costDeployment;
		//float largeValue;
		float maximalDistance;
};

#endif // PONINSTANCE_H
