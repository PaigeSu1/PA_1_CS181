/*
# Author: Paige Su
# BannerID: 001395655
# Course: CS 181
# Assignment: PA1
# Date Assigned: Tuesday, January 16, 2024
# Date/Time Due: Friday, January 26, 2024 -- 11:55 pm
# Description: This program will exercise on procedural
programming concepts with C++.
# Certification of Authenticity:
I certify that this assignment is entirely my own work.
*/

//the thought process
//------------------------------------------------------------------------------
//The well being of the bank math formula

// BankTotalAsset = currentBalance + loansToOtherBanks
//
// if BankTotalAsset is less than certain limit
//  then bank is labeled as unsafe
//      if the bank is unsafe the lender cannot count total asset
//          then bank receiving money subtract that from total asset
// [then check to see if the lender is unsafe and total asset are under the limit]



//-------------------------------------------------------------------------------
//Current Balance

//There are 5 banks in total with each of a currentBalance
// bank0 = 25 million dollars
// bank1 = 123 million dollars
// bank2 = 175 million dollars
// bank3 = 75 million dollars
// bank4 = 181 million dollars
//-------------------------------------------------------------------------------------
// loans
//
// Bank0 loans 100.5 million to Bank1
// Bank0 loans 320.5 million to Bank4
// ************************************
// Bank1 loans 40 million to Bank2
// Bank1 loans 85 million to Bank3
//**************************************
// Bank2 loans 75 million to Bank3
// Bank2 loans 125 million to Bank0
//*************************************
// Bank3 loans 125 million to Bank0
//************************************
// Bank4 loans 125 million to Bank2

//-------------------------------------------------------------------------------------------
//How to use the Data that has been given
//reads in input

//int n (represents the number of banks)
// int limit (The minimum asset for keeping a bank safe)

//ask user to enter the number of banks (the highlighted yellow area)
// ask user to enter the limit for a bank to be safe

//display the bank data (highlighted in yellow) (ask what dose any of this mean?)
// (sorting through strings?)


//print the result out to the user of the banks that would be unsafe.





//Code work starts here
//Header files
#include <iostream>
using namespace std;

//global variables
const int MAX_BANKS = 100;
const int MAX_LOANS = 100;   //This was the problem ##########

int main()
{
    //Variable declaration
    int n;              //(represents the number of banks)
    int limit;          //(The minimum asset for keeping a bank safe)

    //Ask for user input for number of banks
    cout << "Enter the number of banks: " << endl;
    cin >> n;

    cout << "Enter the minimum limit asset for keeping the bank safe: " << endl;
    cin >> limit;

    //Make an Array to store the bank information
    double currentBalance[MAX_BANKS];
    pair<int, double> loans[MAX_BANKS][MAX_LOANS];     //max banks was placed twined when it should have not been #########

    //This was problem solution #########3
    //Initialize loans array
    for (int i = 0; i < MAX_BANKS; ++i) {
        for (int j = 0; j < MAX_LOANS; ++j) {
            loans[i][j] = make_pair(-1, 0.0); //Indicates no loan with borrower ID -1
        }
    }

    //Array to store the banks that are not safe
    bool unsafe[MAX_BANKS] = {false};

    //Read in the Entered Bank information
    for (int i = 0; i < n; i++){
        //print out current Balance for each bank
        cout << "Enter the current Balance for bank " << i << " : " << endl;
        cin >> currentBalance[i];

        //Read loan information in each Bank
        int numLoans;
        cout << "Enter the number of loans for the bank " << i << " : " << endl;
        cin >> numLoans;

        cout << "Enter loan details (borrower ID and amount) for bank " << i << ": ";
        for (int j = 0; j < numLoans; ++j){
            cin >> loans[i][j].first >> loans[i][j].second;
        }
    }

    bool changed;
    do {
        changed = false;

        //Calculate the total assets for each bank and update their unsafe status
        for (int i = 0; i < n; ++i) {
            if (!unsafe[i]) {
                //Calculate the total asset for the current bank
                double totalAssets = currentBalance[i];
                for (int j = 0; j < MAX_LOANS && loans[i][j].first != -1 ; ++j) {
                    int borrowerId = loans[i][j].first;
                    if (!unsafe[borrowerId]) {
                        totalAssets += loans[i][j].second;
                    }
                }

                //Update if bank is unsafe or not
                if (totalAssets < limit) {
                    unsafe[i] = true;
                    changed = true;
                }
            }
        }
    } while (changed);

    //Output the unsafe bank info to the user
    cout << "Unsafe Banks: " << endl;
    for (int i = 0; i < n; ++i) {
        if (unsafe[i]){
            cout << "Bank " << i << " ";
        }
    }
    cout << endl;

    /*    original code with the logic error
    //The logic on how to determine if a bank is unsafe     // BankTotalAsset = currentBalance + loansToOtherBanks
    for(int i = 0; i < n; ++i) {
        //Calculate the total asset for the current bank
        double totalAssets;
        totalAssets = currentBalance[i];
        for(int j = 0; j < MAX_BANKS && loans[i][j].first != -1 ; ++j){
            totalAssets += loans[i][j].second;
        }

        //update if bank is unsafe or not
        if(totalAssets < limit){
            //put that bank into the unsafe list
            unsafe[i] = true;
            for(int j = 0; j < MAX_BANKS && loans[i][j].first != -1; ++j){
                unsafe[loans[i][j].first] = true;
            }
        }

    } //end of main brace


    //output the unsafe bank info to the user
    cout << "Unsafe Banks: " << endl;
    for(int i = 0; i < n; ++i){
        if(unsafe[i]){
            cout << "Bank " << i << " " ;
        }
    }
    cout << endl;

    */

    return 0;
} //end of program brace
