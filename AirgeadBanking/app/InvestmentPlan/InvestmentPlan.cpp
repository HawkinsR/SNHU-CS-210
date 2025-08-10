/*
 * InvestmentPlan.cpp
 * Airgead Banking - Project 2
 *
 *  Date: Jul 27, 2025
 *  Author: Richard Hawkins
 */

#include <cmath>
#include <string>
#include "InvestmentPlan.h"
#include "../IOHandler/IOHandler.h"

using namespace std;

int InvestmentPlan::GetMonthsDuration()
// Getter m_monthsDuration
{
    return m_monthsDuration;
}

void InvestmentPlan::GetMonthsDurationRef(int& t_monthsDuration)
// Getter by reference m_monthsDuration
{
    t_monthsDuration = m_monthsDuration;
}

void InvestmentPlan::SetMonthsDuration(int t_monthsDuration)
// Setter m_monthsDuration
{
    if (t_monthsDuration > 0) // validate duration at least 1 month
    {
        m_monthsDuration = t_monthsDuration;
    }
    else
    {
        m_monthsDuration = 1;
    }
}

double InvestmentPlan::GetInitialDeposit()
// Getter m_initialDeposit
{
    return m_initialDeposit;
}

void InvestmentPlan::GetInitialDepositRef(double& t_initialDeposit)
// Getter by reference m_initialDeposit
{
    t_initialDeposit = m_initialDeposit;
}

void InvestmentPlan::SetInitialDeposit(double t_initialDeposit)
// Setter m_initialDeposit
{
    if (t_initialDeposit >= 0) // validate 0 or greater
    {
        m_initialDeposit = round(t_initialDeposit * 100.0) / 100.0; // round to the nearest hundredth place
    }
    else
    {
        m_initialDeposit = 0;
    }
}

double InvestmentPlan::GetMonthlyDeposit()
// Getter m_monthlyDeposit
{
    return m_monthlyDeposit;
}

void InvestmentPlan::GetMonthlyDepositRef(double& t_monthlyDeposit)
// Getter by reference m_monthlyDeposit
{
    t_monthlyDeposit = m_monthlyDeposit;
}

void InvestmentPlan::SetMonthlyDeposit(double t_monthlyDeposit)
// Setter m_monthlyDeposit
{
    if (t_monthlyDeposit >= 0) // validate 0 or greater
    {
        m_monthlyDeposit = round(t_monthlyDeposit * 100.0) / 100.0; // round to the nearest hundredth place
    }
    else
    {
        m_monthlyDeposit = 0;
    }
}

double InvestmentPlan::GetInterest()
// Getter m_interest
{
    return m_interest;
}

void InvestmentPlan::GetInterestRef(double& t_interest)
// Getter by reference m_interest
{
    t_interest = m_interest;
}

void InvestmentPlan::SetInterest(double t_interest)
// Setter m_interest
{
    m_interest = round(t_interest * 100.0) / 100.0; // round to the nearest hundredth place
}

double InvestmentPlan::GetOpeningAmount()
// Getter m_openingAmount
{
    return m_openingAmount;
}

void InvestmentPlan::GetOpeningAmountRef(double& t_openingAmount)
// Getter by reference m_openingAmount
{
    t_openingAmount = m_openingAmount;
}

void InvestmentPlan::SetOpeningAmount(double t_openingAmount)
// Setter m_openingAmount
{
    m_openingAmount = t_openingAmount;

}

double InvestmentPlan::GetClosingAmount()
// Getter m_closingAmount
{
    return m_closingAmount;
}

void InvestmentPlan::GetClosingAmountRef(double& t_closingAmount)
// Getter by reference m_closingAmount
{
    t_closingAmount = m_closingAmount;
}

void InvestmentPlan::SetClosingAmount(double t_closingAmount)
// Setter m_closingAmount
{
    m_closingAmount = t_closingAmount;
}

void InvestmentPlan::DisplayWithout(IOHandler io)
// Display annual interest without monthly deposits
{
    io.Clear(); // clean the screen
    io.Divider(); // add some formatting
    io.Print("#\t\tBalances Without Monthly Deposits\t\t #"); // print the heading
    io.Divider(); // make it pretty
    io.Print("#  Year\t\tYear End Balance\t\tInterest Earned  #"); // print the column headings

    for (int i = 1; i <= m_monthsDuration /12; i++) // loop the number of years on the plan
    {
        double annualInterest = 0;
        double monthlyInterest = 0; // reset the annual tallies for interest

        for (int i = 1; i <= 12; i++) // loop for each month to compound interest
        {
            SetOpeningAmount(GetClosingAmount()); // get the last closing amount
            monthlyInterest = GetOpeningAmount() * ((GetInterest()/100)/12); // calculate the monthly interest
            SetClosingAmount(GetOpeningAmount() + monthlyInterest); // update the closing amount for the month
            annualInterest += monthlyInterest; // add the monthly interest to the annual tally
        }
        io.PrintRow(i, GetClosingAmount(), annualInterest); // print the row
    }
    io.Divider(); // more pretty formatting
    ResetInvestmentPlan(); // reset the opening and closing values
}

void InvestmentPlan::DisplayWith(IOHandler io)
// Display annual interest with monthly deposits
{
    io.Divider(); // more formatting
    io.Print("#\t\tBalances With Monthly Deposits\t\t\t #"); // new heading to pring
    io.Divider(); // gotta look good
    io.Print("#  Year\t\tYear End Balance\t\tInterest Earned  #"); // column headings

    for (int i = 1; i <= m_monthsDuration /12; i++) // annual loop
    {
        double annualInterest = 0;
        double monthlyInterest = 0; // reset the annual tallies

        for (int i = 1; i <= 12; i++) // monthly loop
        {
            SetOpeningAmount(GetClosingAmount()); // get last closing amount
            monthlyInterest = (GetOpeningAmount() + GetMonthlyDeposit()) * ((GetInterest()/100)/12); // calculate the monthly interest WITH a deposit
            SetClosingAmount(GetOpeningAmount() + GetMonthlyDeposit() + monthlyInterest); // calculate the closing value for the month
            annualInterest += monthlyInterest; // add monthly interest to the annual
        }
        io.PrintRow(i, GetClosingAmount(), annualInterest); // print the row
    }
    io.Divider(); // keep looking good
    ResetInvestmentPlan(); // reset the opening and closing values
}

void InvestmentPlan::DisplayPlans(IOHandler io)
// manage displaying the two plan options, with and without deposits
{
    io.Clear(); // clean up
    DisplayWithout(io); // display the without table
    io.Space(); // add some more spaceing for readability
    DisplayWith(io); // display the with table
    io.EnterContinue(); // wait for the user to continue
}

void InvestmentPlan::ResetInvestmentPlan()
// Reset m_openingAmount and m_closingAmount
{
    SetOpeningAmount(GetInitialDeposit());
    SetClosingAmount(GetInitialDeposit());
}

InvestmentPlan::InvestmentPlan()
// Default constructor with 0's
{
    SetInitialDeposit(0);
    SetMonthsDuration(0);
    SetMonthlyDeposit(0);
    SetInterest(0);
    SetOpeningAmount(0);
    SetClosingAmount(0);
}

InvestmentPlan::InvestmentPlan(IOHandler io)
// Constructor with user values provided by the io handler
{
    io.NewPlan();
    SetInitialDeposit(io.CollectInitialInvestment());
    SetMonthsDuration(io.CollectMonthsDuration());
    SetMonthlyDeposit(io.CollectMonthlyDeposit());
    SetInterest(io.CollectAnnualInterest());
    SetOpeningAmount(GetInitialDeposit());
    SetClosingAmount(GetInitialDeposit());
}
