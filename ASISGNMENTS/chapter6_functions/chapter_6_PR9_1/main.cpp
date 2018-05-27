/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
float prsentValue(float, float, float);
//Execution Begins Here
int main(int argc, char** argv) {
     float futureV, interstRate, numYr,prValuel,results;
    
    
    
    //p present value
    // f is the future value // 10,000
    //r is the annual interest rate
    //n number of years
    
    
    cout<<"Enter the annual interest rate and number of years \n";
    cin>>interstRate>>numYr>>futureV;
    
   results= prsentValue(interstRate,numYr,futureV);
   
    return 0;
}

float prsentValue(float r, float n, float f)
{
    float first,second,third;
    
    first =(1+r/100);
    for(int i=0;i<n;i++)
    {
        second= pow(first,n);
    }
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    cout<< f / second ;
    
}