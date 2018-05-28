/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
int linearSort(const int[], int, int);
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
void selectionSort(int[],int);
void swap(int &, int &);
int linearSor(const int[], int, int);
int main(int argc, char** argv) {
    int results;
    int number;
    const int SIZE = 18;
    int arr[SIZE] = {5658845,4520125,7895122,8777541,8451277,1302850,
                    8080152,4562555,5552012,5050552,7825877,1250255,
                    1005231,6546231,3852085,7576651,7881200,4581002};
    
    cout<<"Enter a number to search for!"<<endl;
    cin>>number;
    
    selectionSort(arr, SIZE);

    
    
    results = linearSor(arr,SIZE,number);
    
    if(results == -1)
        cout<<"No match was found! "<<endl;
    else 
    {
        cout<<"a match was located at number: "<<results+1<<endl;
    }
    
    cout<<"This is a output of all the numbers sorted to test/show sort is working\n";
        for(int i =0; i <SIZE; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    
    return 0;
}
void selectionSort(int array[], int size)
{
    int minIndex, minValue;
    
    
    for(int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for(int index = start + 1; index <size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}



///////////
int linearSor(const int arr[], int size, int number)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        if(arr[index] == number)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
    
}