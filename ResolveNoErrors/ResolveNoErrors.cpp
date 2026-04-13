// ResolveNoErrors.cpp : Defines the entry point for the application.
//

#include "ResolveNoErrors.h"

using namespace std;

class FakeCalculator
{
public:
	double add(double a, double b) { return a + b; }
	double subtract(double a, double b) { return a - b; }
	double multiply(double a, double b) { return a * b; }
	double divide(double a, double b) 
	{ 
		if (b == 0) 
		{
			cout << "Error: Division by zero!" << endl;
			return 0;
		}
		return a / b; 
	}

	void displayResult(const string& operation, double result)
	{
		cout << " = " << result << endl;
	}
};

int myValue = 10;        // First definition as variable
void myValue ();        // C2365: redefinition; previous was 'variable'

extern int data[10];     // Forward declaration with 10 elements
int data[20];

extern int value;        // Non-const declaration
const int value = 5;

int main()
{
	cout << "Hello CMake." << endl;

	FakeCalculator calc;

	cout << "\nFake Calculator Demo:" << endl;
	calc.displayResult("10 + 5", calc.add(10, 5, 8));
	calc.displayResult("10 - 5", calc.subtract(10, 5));
	calc.displayResult("10 * 5", calc.multiply(10, 5));
	calc.displayResult("10 / 5", calc.divide(10, 5));
	calc.displayResult("10 / 0", calc.divide(10, 0));

	return 0;
}

