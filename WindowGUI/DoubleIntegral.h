#include <iostream>
#include <cmath>
using namespace std; 

float x=1.0;
float y=1.0;

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
float Calculate(float ly,float uy,float lx,float ux,float h,float k)
{ 
    // lx and ux are upper and lower limit of x integral 
    // ly and uy are upper and lower limit of y integral 
    // h is the step size for integration wrt x 
    // k is the step size for integration wrt y 
    // float h, k, lx, ux, ly, uy; 
    // cout  << "input h \n";
    // cin >> h;
    // cout << "input k \n ";
    // cin >> k;
    // cout << "input lx \n ";
    // cin >> lx;
    // cout << "input ux \n";
    // cin >> ux;
    // cout << "input ly \n ";
    // cin >> ly;
    // cout << "input uy \n";
    // cin >> uy;
	float sum;
    sum = doubleIntegral(h, k, lx, ux, ly, uy); 
    return sum; 
}