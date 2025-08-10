/*
 * AirgeadBanking.cpp
 * Airgead Banking - Project 2
 *
 *  Date: Jul 27, 2025
 *  Author: Richard Hawkins
 *
 * Airgead Banking App accepts user inputs for hypothetical savings planning,
 * and displays returns by month for the described investment plan.
 */

#include <string>
#include "InvestmentPlan/InvestmentPlan.h"
#include "IOHandler/IOHandler.h"

using namespace std;

int main() // entrypoint must be int main
{
    IOHandler io = IOHandler(); // Create an in-out handler object to manage all user input and output
    io.Startup(); // Print the startup welcome messages
    InvestmentPlan userPlan = InvestmentPlan(); // Create a blank investment plan object
    bool loop = false; // Declare and instantiate the loop indicator
    do
    {
        userPlan = InvestmentPlan(io); // Re-create the userPlan with a new constructor (that gathers values from the user with the io object)
        userPlan.DisplayPlans(io); // Calculate and print the compound interest for both with and without monthly deposits
        io.LoopHandler(loop); // Prompt user to run application with new plan values
    } while (loop); // Loop over if true
    io.Exit(); // Display an exit message
    return 0;
}
