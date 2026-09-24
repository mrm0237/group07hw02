// Riggs McLeod & David Lilley
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Pass in space-delimited arguments when you call the executable
// Example: ./a.out 1 2 3.3
double debt_finder(double cost, double m_interest_rate, double m_payments)
{
    double balance = cost;
    double interest;
    double principal;

    while (balance > 0)
    {
        interest = (m_interest_rate * 0.01) * balance;
        principal = m_payments - interest;

        if (principal <= 0)
        {
            return balance;
        }

        if (principal > balance)
        {
            principal = balance;
        }

        balance -= principal;
    }

    return balance;
}

int main(int argc, char *argv[])
{
    // Define variables
    double loan_amount;
    double yearly_interest_rate;
    double monthly_payment;

    // Check command-line arguments
    if (argc > 4)
    {
        cout << "Too many arguments. Cannot pass in more than three."
             << endl;
        return -1;
    }

    // If arguments were provided, use them
    if (argc > 1)
    {
        if (argc != 4)
        {
            cout << "Please provide all three arguments:"
                 << " loan amount, interest rate, and monthly payment."
                 << endl;
            return -1;
        }

        try
        {
            loan_amount = stod(argv[1]);
            yearly_interest_rate = stod(argv[2]);
            monthly_payment = stod(argv[3]);
        }
        catch (const invalid_argument&)
        {
            cout << "Invalid argument." << endl;
            return -2;
        }
        catch (const out_of_range&)
        {
            cout << "Argument is out of range." << endl;
            return -2;
        }

        // Validate command-line input
        if (loan_amount <= 0)
        {
            cout << "Loan amount must be positive." << endl;
            return -1;
        }

        if (yearly_interest_rate < 0)
        {
            cout << "Interest rate must be positive." << endl;
            return -1;
        }

        if (monthly_payment <= 0)
        {
            cout << "Monthly payment must be positive." << endl;
            return -1;
        }
    }
    else
    {
        // USER INPUT
        cout << "Loan Amount: ";
        cin >> loan_amount;

        while (loan_amount <= 0)
        {
            cout << "Enter a positive loan amount: ";
            cin >> loan_amount;
        }

        cout << "Interest Rate (% per year): ";
        cin >> yearly_interest_rate;

        while (yearly_interest_rate < 0)
        {
            cout << "Enter a positive interest rate: ";
            cin >> yearly_interest_rate;
        }

        cout << "Monthly Payments: ";
        cin >> monthly_payment;

        while (monthly_payment <= 0)
        {
            cout << "Enter a positive monthly payment: ";
            cin >> monthly_payment;
        }
    }

    // Convert yearly interest rate to a monthly decimal rate
    double monthly_interest_rate =
        (yearly_interest_rate / 100.0) / 12.0;

    double balance = loan_amount;
    double total_interest = 0.0;
    int current_month = 0;

    cout << fixed << setprecision(2);

    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    double interest;
    double payment;
    double principal;

    while (balance > 0)
    {
        if (current_month == 0)
        {
            cout << current_month++ << "\t$" << balance;

            if (balance < 1000)
                cout << "\t";

            cout << "\tN/A\tN/A\tN/A\t\tN/A\n";
        }
        else
        {
            // Calculate monthly interest
            interest = balance * monthly_interest_rate;

            // Start with the normal monthly payment
            payment = monthly_payment;

            // Adjust the final payment if necessary
            if (balance + interest < monthly_payment)
            {
                payment = balance + interest;
            }

            // Calculate principal paid
            principal = payment - interest;

            // Update balance
            balance -= principal;

            // Prevent tiny negative balances from floating-point math
            if (balance < 0.005)
            {
                balance = 0;
            }

            // Add interest to total
            total_interest += interest;

            cout << current_month
                 << "\t$" << balance
                 << "\t$" << payment
                 << "\t" << monthly_interest_rate
                 << "\t$" << interest
                 << "\t$" << principal
                 << endl;

            current_month++;
        }
    }

    cout << "*****************************************************************\n";
    cout << "\nIt takes " << --current_month
         << " months to pay off the loan.\n";
    cout << "Total interest paid is: $"
         << total_interest << endl;

    return 0;
}
