#include <iostream>
#include <cmath> 
using namespace std; 

float givenFunction(float x, float y) 
{ 
    x =1;
    y =1;
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
			double funValue = givenFunction(xi,yi);
			double rectangleArea = funValue*dx;
			Smallsum += rectangleArea;
		}
 		double secondRectangleArea = Smallsum*dy;
		Bigsum += secondRectangleArea;
	}
	return Bigsum;
}

float Calculate(double lx,double ux,double ly,double uy)
{
	// double lowBound1, upBound1, lowBound2, upBound2;
	int n = 10000;
	// cout << "low x = "; 
	// cin >> lx;
	// cout << "up x = ";
	// cin >> ux;
	// cout << "low y = ";
	// cin >> ly;
	// cout << "up y = ";
	// cin >> uy; 
	double dx = (ux-lx)/n;
	double dy = (uy-ly)/n;
	double result = DoubleIntegral(ly, lx, n, dy, dx);
	// cout << "DoubleIntegral = ";
	// cout << result ;
	return result;
}
