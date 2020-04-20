#include <iostream>
#include <math.h>

using namespace std;

double Integral(double constant,double power)
{   
    // long int constant, power;
    // char var;
    // cout << "Enter a constant of variable to be integrated (if there is no constant enter 1): " << endl;
	// cin >> constant;
    // cout << "Now enter the variable to be integrated: " << endl;
	// cin >> var;
	// cout << "Finally, enter the power which everything is raised to: " << endl;
    // cin >> power;
	// cout << "\nYou have entered: \n" << constant << "*" << var << "^" << power << "\n" << endl;
	power= power + 1;
	constant=constant/power;
	// cout << "The integral is: " << constant << "" << var << "^" << power << endl << endl;
	
}
