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


//Execution Begins Here
int main(int argc, char** argv) {
    const int SIZE =10;
    int numbers[SIZE];
    int count,highest,lowest;
    
    highest = numbers[0];
    for(int count = 0; count < SIZE; count++)
    {
        cout<<"enter ten numbers to sort! \n";
        cin>>numbers[count];
        
        if(numbers[count] > highest)
        
            highest = numbers[count];
        }
            cout<<"The highest number sorted was "<<highest<<endl;

           lowest = numbers[0];
           for(int count = 0; count < SIZE; count++)
               if(numbers[count] < lowest)
                   lowest = numbers[count];
                           cout<<"The lowest number sorted was "<<lowest<<endl;
        

   
   
    
    return 0;
}
