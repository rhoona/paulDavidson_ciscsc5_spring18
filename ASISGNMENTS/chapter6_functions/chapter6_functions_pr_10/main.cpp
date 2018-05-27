/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
float futureValue(float, float, float);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float pv,ir,nm,results=0;
    //Initialize Variables
    cout<<"Enter the Present value, the interest rate and how many months";
    cin>>pv>>ir>>nm;
    //Process/Map inputs to outputs
    results = futureValue(pv,ir,nm);
   // cout<<results;
    //Output data
    
    //Exit stage right!
    return 0;
}

float futureValue(float pv, float ir, float nm)
{
    float fv,first,second,third; 
    
    first = (1+ir/100);
    
    for(int i=0;i<nm;i++)
    {
        second = pow(first,nm);
    }
    
    fv = pv*second;
    cout<<fv;
    
}