/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on May 31st, 2018, 11:45 AM
 * Purpose:  Dynamic 1 and 2 D Vectors
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void fillAry(vector<int> &,int);
void prntAry(vector<int> &,int);
void fillAry(vector< vector<int> > &,int,int);
void prntAry(vector< vector<int> > &);
void pause(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=100;
    int rows=10;
    int cols=10;
    vector<int> array;
    vector< vector<int> > array2;
    
    //Initialize Variables
    fillAry(array,size);
    fillAry(array2,rows,cols);
    
    //Print the Array
    prntAry(array,10);
    pause(10);
    prntAry(array2);
    
    //Exit stage right!
    return 0;
}

void pause(int secs){
    int beg=time(0);//Time at the beginning
    int end;
    do{
        end=time(0);
    }while((end-beg)<=secs);
}

void prntAry(vector< vector<int> > &a){
    cout<<endl;
    for(int row=0;row<a.size();row++){
        for(int col=0;col<a[row].size();col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void fillAry(vector< vector<int> > &a,int rows,int cols){
    //Fill the array
    for(int row=0;row<rows;row++){
        a.push_back(vector<int>());
        for(int col=0;col<cols;col++){
            a[row].push_back(rand()%90+10);
        }
    }
}

void prntAry(vector<int> &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(vector<int> &a,int n){
    //Fill the array
    for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);//[10,99]
    }
}