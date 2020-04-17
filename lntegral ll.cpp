#include <iostream>
#include <cmath>
using namespace std;
double fun(double x,double y)
{	x=1;
 	y=1;
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


int main()
{
	double lowBound1, upBound1, lowBound2, upBound2;
	int n = 10000;
	cout << "low x = "; 
	cin >> lowBound2;
	cout << "up x = ";
	cin >> upBound2;
	cout << "low y = ";
	cin >> lowBound1;
	cout << "up y = ";
	cin >> upBound1; 
	double dx = (upBound2-lowBound2)/n;
	double dy = (upBound1-lowBound1)/n;
	double result = DoubleIntegral(lowBound1, lowBound2, n, dy, dx);
	cout << "DoubleIntegral = ";
	cout << result ;
	return 0;
}

// second code//
#include <iostream>
#include <cmath> 
using namespace std; 

float givenFunction(float x, float y) 
{ 
    x =1;
    y =1;
    return x*y; 
} 
  
float doubleIntegral(float h, float k, 
                     float lx, float ux, 
                     float ly, float uy) 
{ 
    int nx, ny; 
    float z[50][50], ax[50], answer; 
    nx = (ux - lx) / h; 
    ny = (uy - ly) / k; 
  
    for (int i = 0; i < nx; ++i) { 
        for (int j = 0; j < ny; ++j) { 
            z[i][j] = givenFunction(lx + i * h, 
                                    ly + j * k); 
        } 
    } 
  

    for (int i = 0; i < nx; ++i) { 
        ax[i] = 0; 
        for (int j = 0; j < ny; ++j) { 
            if (j == 0 || j == ny - 1) 
                ax[i] += z[i][j]; 
            else if (j % 2 == 0) 
                ax[i] += 2 * z[i][j]; 
            else
                ax[i] += 4 * z[i][j]; 
        } 
        ax[i] *= (k / 3); 
    } 
  
    answer = 0; 
  

    for (int i = 0; i < nx; ++i) { 
        if (i == 0 || i == nx - 1) 
            answer += ax[i]; 
        else if (i % 2 == 0) 
            answer += 2 * ax[i]; 
        else
            answer += 4 * ax[i]; 
    } 
    answer *= (h / 3); 
  
    return answer; 
} 
  
int main() 
{ 
    float h, k, lx, ux, ly, uy; 
  	cout << "Low X = ";
  	cin >> lx;
  	cout << "Up X = ";
  	cin >> ux;
  	cout << "Low Y = ";
  	cin >> ly;
  	cout << "Up Y = ";
  	cin >> uy;
  	
    h =0.1, k = 0.15; 
  
    printf("%f", doubleIntegral(h, k, lx, ux, ly, uy)); 
    return 0; 
} 
