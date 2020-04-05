#include <iostream>
#include <cmath>
using namespace std;
double fun(double x,double y)
{
	return pow(pow(x,4)+pow(y,5),0.5);
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
	int n = 30000; //ติดปัญหาเรื่องความละเอียดช่อง เกิน30000ช่องโค้ดรันช้ามากจนถึงขั้นรันไม่ได้
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
	cout << "DoubleIntegral = ",result;
	return 0;
}

// second code//
#include <iostream>
#include <cmath>
using namespace std; 
  

float givenFunction(float x, float y) 
{ 
    return x*y; 
} 
  

float doubleIntegral(float h, float k, 
                     float lx, float ux, 
                     float ly, float uy) 
{ 
    int nx, ny; 
    
   
    float z[50][50], ax[50], answer; 
  
   
    nx = (ux - lx) / h + 1; 
    ny = (uy - ly) / k + 1; 
  
    
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
  
// Driver Code 
int main() 
{ 
    // lx and ux are upper and lower limit of x integral 
    // ly and uy are upper and lower limit of y integral 
    // h is the step size for integration wrt x 
    // k is the step size for integration wrt y 
    float x=1.0;
    float y=1.0;
    float h, k, lx, ux, ly, uy; 
    cout  << "input h \n";
    cin >> h;
    cout << "input k \n ";
    cin >> k;
    cout << "input lx \n ";
    cin >> lx;
    cout << "input ux \n";
    cin >> ux;
    cout << "input ly \n ";
    cin >> ly;
    cout << "input uy \n";
    cin >> uy;
    printf("%f", doubleIntegral(h, k, lx, ux, ly, uy)); 
    return 0; 
} 
