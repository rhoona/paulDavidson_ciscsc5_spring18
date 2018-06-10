/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on May 29th, 2018, 11:35 AM
 * Purpose:  Static 1 and 2 D Arrays
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COLS=10;//Columns for 2-D Array

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void fillAry(int [][COLS],int);
void prntAry(int [][COLS],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    const int ROWS=10;
    int array[SIZE],array2[ROWS][COLS];
    
    //Initialize Variables
    fillAry(array,SIZE);
    fillAry(array2,ROWS);
    
    //Print the Array
    prntAry(array,SIZE,10);
    prntAry(array2,ROWS);
    
    //Exit stage right!
    return 0;
}

void prntAry(int a[][COLS],int rows){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[][COLS],int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            a[row][col]=rand()%90+10;
        }
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
}