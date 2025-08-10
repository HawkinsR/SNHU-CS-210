/*
 * IOHandler.h
 * Airgead Banking - Project 2
 *
 *  Date: Jul 27, 2025
 *  Author: Richard Hawkins
 */

#ifndef AirgeadBanking_IOHandler_IOHandler_H
#define AirgeadBanking_IOHandler_IOHandler_H

#include <string>

using namespace std;

class IOHandler
// Class template for the io handler
{
    public:
        IOHandler();
        void EnterContinue();
        void Clear();
        void Divider();
        void Space();
        void Startup();
        void Exit();
        void NewPlan();
        void Input(string& t_line);
        void Print(string t_out);
        void PrintRow(int year, double closing, double interest);
        void LoopHandler(bool& t_loop);
        double CollectInitialInvestment();
        int CollectMonthsDuration();
        double CollectMonthlyDeposit();
        double CollectAnnualInterest();
};

#endif
