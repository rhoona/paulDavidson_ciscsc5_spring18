/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

int linearSearch(const int[], int, int);
int main(int argc, char** argv) {

    const int SIZE =10;
    int tests[SIZE] = {13579,26791,33445,55555,62483,77777,79422,85647,93121};
    int results;
    int number;
    
    cout<<"Enter your number to see if you won! ";
    cin>>number;
    
    results = linearSearch(tests, SIZE,number);
    
    if(results == -1)
        cout<<"Aww sorry you did not win! ";
    else
    {
        cout<<"YOU WON OMG! ";
    }
    return 0;
}

int linearSearch(const int arr[], int size, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        if(arr[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}