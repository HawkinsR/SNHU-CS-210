# Airgead Bankind App Pseudocode

## Project 2
## Richard Hawkins
## July 27, 2025

### Summary:
Airgead Banking would like to develop an application to help users understand the interest and return for their investments.
Users should be enter different sets of values for an investment plan, and see the expected returns for their plan.

### Requirements:
Users should be able to enter their investment plan with the values:
- Initial investment amount (a positive real number)
- Monthly deposit ammount (a positive real number)
- Annual interest (a decimal number, ) 
- Length of investment (positive whole number, in years)

The application should calculate and display:
- The number of months in the length of investment
- The 'opening amount' for the month (previous months closing OR initial investment)
- The monthly deposit amount
- Total value for the month before interest calculation (opening + deposit)
- Interest payment for the month, based on the annual interest (round to nearest cent)
- The closing balance for the month (total + interest, rounded to nearest cent)

Stretch Goals (for funsies!)
- Minimize the variables in the main method
- Minimize the number of varialbes passed to methods
- Minimize the lines in the main method
- Localize all user IO operations to one class, preferably one instance of the class.

### Pseudocode:

START PROGRAM
    CREATE an IOHandler object
    Greet users
    CREATE an InvestmentPlan object
    LOOP UNTIL user chooses to exit
        LOOP UNTIL all required values entered
            Accept initial investment ($)
            Accept monthly deposit ($)
            Accept annual interest (%)
            Accept length of investment (years)
        END LOOP
        LOOP the number of years in the InvestmentPlan
            LOOP the number of months in the year
                CALCULATE and print annual compoud interest WITHOUT monthly deposits
            END LOOP
        END LOOP
        LOOP the number of years in the InvestmentPlan
            LOOP the number of months in the year
                CALCULATE and print annual compound interest WITH monthly deposits
            END LOOP
        PROMPT user to run again or exit
    END LOOP
EXIT PROGRAM
    
