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

int main()
{
	// Define variables
	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	double arguments [3];
	double monthly_interest_rate = yearly_interest_rate / 12;

	// USER INPUT
	cout << "\nLoan Amount: ";
	cin >> loan;
	while (loan < 0) { // Program will not move forward unless positive loan is entered
		cout << "\nEnter a positive loan amount: "; 
		cin >> loan;
	}
	
	cout << "Interest rate (% per year)": ";
	cin >> month_int_rate;
	while (loan < 0) { // Program will not move forward until a positive interest rate is entered
		cout << "\nEnter a positive interest rate: ";
		cin >> month_int_rate;
	}
	
	monthly_paid = month_int_rate / 100;
	cout << "Monthly Payments: ";
	cin >> monthly_paid;
	

	loan_amount = arguments[0];
	yearly_interest_rate = arguments[1];
	monthly_payment = arguments[2];
	cout << "*****************************************************************\n"
	<< "\tAmortization Table\n"
	<< "*****************************************************************\n"
	<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
	while (loan > 0) {
		if (current_month == 0) {
			cout << current_month++ << "\t$" << loan;
			if (loan < 1000) cout << "\t"; // Formatting MAGIC
				cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
			
		}
		else {
	cout << "****************************************************************\n";
	cout << "\nIt takes " << --current_month << " months to pay off " << "the loan.\n" << "Total interest paid is: $" << interestTotal;
	
	cout << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;

	return 0;
}
