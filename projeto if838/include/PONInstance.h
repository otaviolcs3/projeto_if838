#ifndef PONINSTANCE_H
#define PONINSTANCE_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//template<class orderedClass>  bool binarySearch(vector<orderedClass>& array, orderedClass& value, unsigned begin, unsigned end);

typedef pair<double, double> Point;
typedef double (*Dist)(const Point&, const Point&);

class PONInstance
{
	public:
		PONInstance();
		virtual ~PONInstance();

		bool isFeasible();
		bool isRelaxedFeasible();

		void pushONU(const Point&);
		bool pushSplitterType(unsigned);

		void setCostPerONU(double);
		void setCostPerSplitterOut(double);
		void setCostFiberCable(double);
		void setCostDeployment(double);
		void setMaximalDistance(double);

		const Point& getCentralOfficeCoords();
		const Point& getONUCoords(unsigned);
		unsigned getSplitterType(unsigned);

	protected:
		bool isFeasible(Dist dist);

	private:
		Point centralOfficeCoords;
		vector<Point> ONUsCoords;       //coordenadas do central office
		vector<unsigned> splitterTypes;
		double costPerONU, costPerSplitterOut;
		double costFiberCable, costDeployment;
		//double largeValue;
		double maximalDistance, minimalDistance/*, maxDiffDistance*/;
};

#endif // PONINSTANCE_H
