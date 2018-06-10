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
const float g = 9.80; // gravity should be ok here it dosnt change!
//Function Prototypes



//Execution Begins Here

float fallingDistance(float );
int main(int argc, char** argv) {

    float time=0,distance;
    
    cout<<fixed<<showpoint<<setprecision(2);
    
    cout<<"This program will show falling distance for 1-10 seconds\n";
    for(int i=0;i<10;i++)
    {
        time++;
       distance = fallingDistance(time);
    }
    

    
    
    
    return 0;
}

float fallingDistance(float time )
{
    float Distance=0;
    
    Distance = .5*(g*(time*time));
    cout<<Distance<<endl;
    
    
    //distance =
    
}
