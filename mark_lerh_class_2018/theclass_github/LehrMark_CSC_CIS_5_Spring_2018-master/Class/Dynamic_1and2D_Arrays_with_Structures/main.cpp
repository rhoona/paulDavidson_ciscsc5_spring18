/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on May 31st, 2018, 10:35 AM
 * Purpose:  Dynamic 1 and 2 D Arrays
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Array1D.h"
#include "Array2D.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
Array1D *fillAry(int);
void prntAry(Array1D *,int);
Array2D *fillAry(int,int);
void prntAry(Array2D *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=100;
    int rows=10;
    int cols=10;
    
    //Initialize Variables
    Array1D *array=fillAry(size);
    Array2D *array2=fillAry(rows,cols);
    
    //Print the Array
    prntAry(array,10);
    prntAry(array2);
    
    //Clean up
    delete []array->data;
    delete array;
    //De-Allocate columns
    for(int row=0;row<rows;row++){
        delete []array2->data[row];
    }
    //De-Allocate the rows
    delete []array2->data;
    delete array2;
    
    //Exit stage right!
    return 0;
}

void prntAry(Array2D *a){
    cout<<endl;
    for(int row=0;row<a->row;row++){
        for(int col=0;col<a->col;col++){
            cout<<a->data[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

Array2D *fillAry(int rows,int cols){
    //Allocate the structure
    Array2D *a=new Array2D;
    //Allocate rows
    a->row=rows;
    a->col=cols;
    a->data=new int*[rows];
    //Allocate columns
    for(int row=0;row<rows;row++){
        a->data[row]=new int[cols];
    }
    //Fill the array
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            a->data[row][col]=rand()%90+10;
        }
    }
    return a;
}

void prntAry(Array1D *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array1D *fillAry(int n){
    //Allocate memory
    Array1D *a=new Array1D;
    a->size=n;
    a->data=new int[a->size];
    //Fill the array
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;//[10,99]
    }
    return a;
}