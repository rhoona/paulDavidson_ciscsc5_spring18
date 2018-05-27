/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

int num();
int days(int);
//Execution Begins Here
int main(int argc, char** argv) {
    int numEmployees;
    int dayNum;
    int total,zero=0;
    
 numEmployees = num();  
 for(int counter = 0; counter <numEmployees; counter++)
 {
 dayNum = days(numEmployees);
 total += dayNum;
 }
 cout<<"Your total average of days missed to employees is "<<total/numEmployees;
 
    return 0;
}

int num()
{
    int num;
    cout<<"How many employees in the company? "<<endl;
    cin>>num;
    
    return num;
}
int days(int num)
{
    int dMissed;
    cout<<"Enter the amount of days missed per employee!  ";
    cin>>dMissed;
    
    return dMissed;

    
       
}