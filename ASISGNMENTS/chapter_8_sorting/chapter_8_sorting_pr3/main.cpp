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

int binarySearch(const int[], int, int);
int main(int argc, char** argv) {
    const int SIZE = 10;
    int numbers[SIZE]={13579,26791,26792,33445,55555,62483, 77777,79422,85647,93121};
    int numb;
    int results;

    
    cout<<"This is a binary search to see if you got the winning lotto numbers!\n";
    cout<<"Enter your numbers to see if you win!\t";
    cin>>numb;
    
    results = binarySearch(numbers, SIZE, numb);
    
    if(results == -1)
        cout<<"Sorry your numbers didnt match, LOSER!";
    else
        cout<<"OH MAN YOU WON WOW!!!";
    
    
    
    return 0;
}

int binarySearch(const int arr[], int size, int value)
{
    int first = 0;
    int last = size;
    int middle;
    int position = -1;
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if (arr[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}