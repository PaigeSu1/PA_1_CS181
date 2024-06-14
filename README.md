Name of Project: Programming Assignment #1 (PA1)

Complete Assignment in C++ using Arrays, Loops

*The Directions Given were quite confusing 

Banks loan money to each other. In tough economic times, if a bank goes bankrupt, it may 
be unable to repay the loan. A bank’s total asset is its current balance plus its loans to other 
banks. Figure 8.7 is a diagram that shows five banks. The banks’ current balances are 25, 
125, 175, 75, and 181 million dollars, respectively. The directed edge from node 1 to node 
2 indicates that bank 1 loans 40 million dollars to bank 2.

![image](https://github.com/PaigeSu1/PA_1_CS181/assets/164946572/c51797c6-d543-45f0-9cec-8682fd4d1226)

Colored Version for Readability 

![image](https://github.com/PaigeSu1/PA_1_CS181/assets/164946572/e547216f-87b0-4ab4-a099-f964eae4733e)


If a bank’s total assets are under a certain limit, the bank is unsafe. If a bank is unsafe, the 
money it borrowed cannot be returned to the lender, and the lender cannot count the loan in its total assets.
Consequently, the lender may also be unsafe if its total assets are under the limit. 


Write a program to find all unsafe banks. Your program reads the input as follows. 

    It first reads two integers, n, and limit, where n indicates the number of banks and limit is 
    the minimum asset for keeping a bank safe. 
    
    It then reads n lines that describe the 
    information for n banks with id from 0 to n-1. 
    
    The first number in the line is the bank’s  balance, the second number indicates the number of banks that borrowed money from the
    bank, and the rest are pairs of two numbers. 
    
    Each pair describes a borrower. The first number in the pair is the borrower’s ID, and the second is the amount borrowed. 

    
Assume that the maximum number of banks is 100. 
For example, the input for the five banks 
in the above Figure is as follows (the limit is 201):

    5 201
    25 2 1 100.5 4 320.5
    125 2 2 40 3 85
    175 2 0 125 3 75
    75 1 0 125
    181 1 2 125

The total asset of bank 3 is (75 + 125), which is under 201. So, bank 3 is unsafe. After bank 
3 becomes unsafe, the total asset of bank 1 becomes 125 + 40. So, bank 1 is also unsafe. 
The output of the program should be:
Unsafe banks are 3 1

Sample Testing Data Oringally Wanted for Program (user data is enclosed by *stars*)

      Enter the number of banks: *5*
      Enter the limit: *201*
      *25 2 1 100.5 4 320.5*
      *125 2 2 40 3 85*
      *175 2 0 125 3 75*
      *75 1 0 125*
      *181 1 2 125*
      Unsafe banks are 3 1

Sample Testing Data easy readablity 
![image](https://github.com/PaigeSu1/PA_1_CS181/assets/164946572/89ab56e6-4944-42fc-bb83-51dc9812fce7)

*This was created using CLion IDE 












