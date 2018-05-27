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
int function(int [], int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    int arrNumb;
    int arrFill = 0;
    
    int results;
    int N;
    
   
    
    cout<<"Enter how many numbers in the array";
    cin>>arrNumb;
    int arr[arrNumb];
    
    for(int i = 0; i < arrNumb; i++)
    {
        cout<<"Enter "<<arrNumb<<" numbers to fill the array! "<<endl;
        cin>>arr[i];
        
    }
  
    cout<<"Enter a number for N "<<endl;
    cin>>N;
    
  function (arr,arrNumb,N);
    
    
    return 0;
}
int function(int arr[], int numb,   int N)
{
    for(int i = 0; i < numb; i++)
        if(i > N)
            cout<<i;
    
}