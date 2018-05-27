/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
float celsius(float);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float f=0,c=0;
    cout<<fixed<<showpoint<<setprecision(2);
    for(int i=0;i<20;i++)
    {
        f++;
         c = celsius(f);
    }
   
    return 0;
}
float celsius(float fNum)
{
    float c,f;
    
    c=(fNum-32)* 5/9;
    cout<<c;
    cout<<"\n";

}