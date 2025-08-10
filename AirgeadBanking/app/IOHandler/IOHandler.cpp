/*
 * IOHandler.cpp
 * Airgead Banking - Project 2
 *
 *  Date: Jul 27, 2025
 *  Author: Richard Hawkins
 */

#include <iomanip>
#include <iostream>
#include <string>
#include "IOHandler.h"

using namespace std;

IOHandler::IOHandler()
// Default constructor
{}

void IOHandler::Clear()
// Use some character magic in the terminal to "clear" the window, but not REALLY, but it looks good enough to me
{
    cout << "\x1B[2J\x1B[H";
}

void IOHandler::EnterContinue()
// Stop the display, letting the user catch up, and continue when they're ready'
{
    string val;
    cout << "Press [ENTER] to continue..." << endl;
    cin.get();
}

void IOHandler::Divider()
// Print a pretty divider to makke things look nice
{
    Print("##################################################################");
}

void IOHandler::Space()
// It's a doulbe printline, just to get some extra space... This is what i get for putting all the IO in one class.
{
    cout << endl;
    cout << endl;
}

void IOHandler::Input(string& t_line)
// Read in from the terminal
{
    cin >> t_line;
}

void IOHandler::Print(string t_out)
// Print out to the terminal, with a bit of number formatting for simplicity
{
    cout << t_out << endl;
}

void IOHandler::PrintRow(int year, double closing, double interest)
// Print a table row with a bit of spacing and formatting
{
    cout << fixed << setprecision(2) << year << "\t\t\t" << closing << "\t\t\t\t" << interest << endl;
}

void IOHandler::Startup()
// Display the application startup message
{
    Clear(); // Clear the terminal
    Divider(); // add some pretty formatting
    cout << "Starting Airgead Banking Investment Planner..." << endl; // display the message
    EnterContinue(); // wait for the user...
    Clear(); // then clean the terminal up
}

void IOHandler::Exit()
// Display some confirmation and shutdown message
{
    Clear(); // clear the terminal
    Divider(); // add that great looking formatting
    cout << "Cleaning up and exiting the Airgead Banking Investment Planner..." << endl;
    cout << "Goodbye" << endl; // Let the user know what's happening
    Divider(); // once more with that good looking line
}

void IOHandler::NewPlan()
// Provide instruction to the user
{
    Clear();
    Divider();
    Print("To begin a new investment plan, let's gather some important information.");
}

void IOHandler::LoopHandler(bool& t_loop)
// Prompt the user to loop and calculate a new plan or exit
{
    string input;

    cout << "Would you like to analyze another investment plan?" << endl;
    cout << "- Enter [y] or [Y] to analyze again" << endl;

    Input(input);

    if (input == "y" || input == "Y") // if the user inputs y or Y...
    {
        t_loop = true; // loop again
    }
    else // otherwise
    {
        t_loop = false; // stop looping
    }

    Clear();
}

double IOHandler::CollectInitialInvestment()
// Prompt user for the initial investment
{
    string input;
    double val = -1;
    do
    {
        cout << "Initial Investment Amount: $";
        cin >> input;

        try
        {
            val = stod(input);
        }
        catch(...)
        {
            val = -1;
        }
    } while (val < 0.0);

    return val;
}

int IOHandler::CollectMonthsDuration()
// Prompt the user for the duration in years
{
    string input;
    int val = -1;
    do
    {
        cout << "Number Of Years: ";
        cin >> input;

        try
        {
            val = stoi(input);
        }
        catch(...)
        {
            val = -1;
        }
    } while (val <= 0);

    return val * 12;
}

double IOHandler::CollectMonthlyDeposit()
// Prompt the user for the monthly deposit
{
    string input;
    double val = -1;
    do
    {
        cout << "Monthly Deposit Amount: $";
        cin >> input;

        try
        {
            val = stod(input);
        }
        catch(...)
        {
            val = -1;
        }
    } while (val < 0.0);

    return val;
}

double IOHandler::CollectAnnualInterest()
// Prompt the user for the interest rate
{
    string input;
    double val = 0;
    do
    {
        cout << "Annual Interest Percentage: %";
        cin >> input;

        try
        {
            val = stod(input);
        }
        catch(...)
        {
            val = -1;
        }
    } while (val < 0.0);

    return val;
}
