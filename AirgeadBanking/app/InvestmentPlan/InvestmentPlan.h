/*
 * InvestmentPlan.h
 * Airgead Banking - Project 2
 *
 *  Date: Jul 27, 2025
 *  Author: Richard Hawkins
 */

#ifndef AirgeadBanking_InvestmentPlan_InvestmentPlan_H
#define AirgeadBanking_InvestmentPlan_InvestmentPlan_H

#include "../IOHandler/IOHandler.h"

using namespace std;

class InvestmentPlan
// The investment plan template
{
    public: // public members
        InvestmentPlan();
        InvestmentPlan(IOHandler io);

        void ResetInvestmentPlan();

        void DisplayPlans(IOHandler io);
        void DisplayWithout(IOHandler io);
        void DisplayWith(IOHandler io);

        int GetMonthsDuration();
        void GetMonthsDurationRef(int& t_monthsDuratioin);
        void SetMonthsDuration(int t_monthsDuration);

        double GetInitialDeposit();
        void GetInitialDepositRef(double& t_initialDeposit);
        void SetInitialDeposit(double t_initialDeposit);

        double GetMonthlyDeposit();
        void GetMonthlyDepositRef(double& t_monthlyDeposit);
        void SetMonthlyDeposit(double t_monthlyDeposit);

        double GetInterest();
        void GetInterestRef(double& t_interest);
        void SetInterest(double t_interest);

        double GetOpeningAmount();
        void GetOpeningAmountRef(double& t_openingAmount);
        void SetOpeningAmount(double t_openingAmount);

        double GetClosingAmount();
        void GetClosingAmountRef(double& t_closingAmount);
        void SetClosingAmount(double t_closingAmount);

    private: // private membets
        int m_monthsDuration;
        double m_initialDeposit;
        double m_monthlyDeposit;
        double m_interest;
        double m_openingAmount;
        double m_closingAmount;
};

#endif
