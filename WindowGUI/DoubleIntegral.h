#include <iostream>
#include <cmath>
using namespace std;
double x=1;
double y=1;
double fun(double x,double y)
{
	return x*y;
}

double DoubleIntegral(double lowBound1, double lowBound2, int n, double dy, double dx)
{
	double Bigsum =0;
	
	for(int i = 0; i < n; i++)
	{
		double yi = lowBound1+i*dy;
		double Smallsum = 0;
		
		for(int j = 0; j < n; j++)
		{
			double xi = lowBound2+j*dx;
			double funValue = fun(xi,yi);
			double rectangleArea = funValue*dx;
			Smallsum += rectangleArea;
		}
 		double secondRectangleArea = Smallsum*dy;
		Bigsum += secondRectangleArea;
	}
	return Bigsum;
}

double Calculate(double lowBound1,double upBound1,double lowBound2,double upBound2)
{
	// double lowBound1, upBound1, lowBound2, upBound2;
	int n = 3000;
	// cout << "low x = "; 
	// cin >> lowBound2;
	// cout << "up x = ";
	// cin >> upBound2;
	// cout << "low y = ";
	// cin >> lowBound1;
	// cout << "up y = ";
	// cin >> upBound1; 
	double dx = (upBound2-lowBound2)/n;
	double dy = (upBound1-lowBound1)/n;
	double result = DoubleIntegral(lowBound1, lowBound2, n, dy, dx);
	return result;
}