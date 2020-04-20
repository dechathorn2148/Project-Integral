#include<iostream>
#include<string>
#include<cmath>

using namespace std;

double fun(double x, double pownum)
{
	 	return pow(x,pownum);	
}

//calcualte area of integral

double areaintigral(double lower, double upper,double pownum,int numdistance){

 double dx= upper-lower/numdistance;
 int sum = 0;
for(int i= 1;i<numdistance;i++)
	{
		double x=lower+i*dx;
		sum=sum+fun(x,pownum);
	}
	int integral = dx/2.0*(fun(lower,pownum)+2*sum+fun(upper,pownum));
	return integral;
}

float SpaceCal(float lower,float upper,float pownum)
{
// double lower,upper,pownum;
   int numdistance;
// //down integral
// 	cout << "Enter lnital limit\nn: ";
// 	cin >> lower;
// // top integral
// 	cout << "Enter lnital upper(final)limit\nn: ";
// 	cin >> upper;
// // input number of pow(x)
// 	cout << "Enter x pow you want\nn:";
// 	cin >> pownum;
// // distance X1,X2,xXn
// 	cout << "Enter the number of sub\nn:";
// 	cin >>numdistance;
    numdistance = 1;

//formula integral f(x)dx
	return areaintigral(lower, upper, pownum, numdistance);
}