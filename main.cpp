// Riggs McLeod & David Lilley
#include <iostream>

using namespace std;

//pass in space-delimited arguments when you call the executable
//Example: ./a.out 1 2 3.3
double debt_finder(double cost, double m_interest_rate, double m_payments)
{
    double balance = cost;
    double principle = m_payments - m_interest_rate * balance;
    // 50 - 1.5% * 1000 = 35
    double interest = m_interest_rate * balance;
    // 1.5% * 1000 = 15
    while (balance > 0) {
        principle = m_payments - (m_interest_rate * .01) * balance;
        if (principle > balance) {
            balance = 0;
        }
        interest = m_interest_rate * balance;
        balance -= principle;
        
    }
    return balance;
}

int main( int argc, char * argv[] )
{
	if (argc > 4) 
	{
		cout << "Too many arguments. Cannot pass in more than three." << endl;
		return -1;
	}
	// Define variables
	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	double arguments [3];
	double monthly_interest_rate = yearly_interest_rate / 12;

	// USER INPUT
	cout << "\nLoan Amount: ";
	cin >> loan;

	
	if (argc > 1)
	{
		while ( i < argc )
		{

			try
			{
				arguments[i-1] = stod(argv[i]);
			}
			catch(const std::invalid_argument&)
			{
				if(i==1)
					cout << "(Invalid loan amount): " << argv[i] << endl;
				else if (i==2)
					cout << "(Invalid interest rate): " << argv[i-1] << " " << argv[i] << endl;
				else
					cout << "(Invalid payment): " << argv[i-2] << " " << argv[i-1] << " " << argv[i] << endl;
				return -2;
			}
			i++;
		}
	}

	loan_amount = arguments[0];
	yearly_interest_rate = arguments[1];
	monthly_payment = arguments[2];
	cout << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;

	return 0;
}
