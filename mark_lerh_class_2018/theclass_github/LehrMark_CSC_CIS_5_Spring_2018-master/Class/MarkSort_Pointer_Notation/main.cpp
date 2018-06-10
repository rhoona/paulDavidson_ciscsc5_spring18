/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on May 15th, 2018, 10:05 AM
 * Purpose:  Investigate Sorts
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void fillAry(int *,int);
void prntAry(int *,int,int);
void mrkSort(int *,int);
void swap(int *,int *);
void swapLgc(int &,int &);
void smlList(int *,int,int);
int  binSrch(int *,int,int);

//Execution Begins Here
int main(int argc, char **argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    
    //Initialize Variables
    fillAry(array,SIZE);
    
    //Print the Array
    prntAry(array,SIZE,10);
    
    //Process/Map inputs to outputs
    mrkSort(array,SIZE);
    
    //Output data
    prntAry(array,SIZE,10);
    
    //Find an element
    int find=50;
    cout<<find<<" was found at index = "
            <<binSrch(array,SIZE,find)<<endl;
    
    //Exit stage right!
    return 0;
}

int  binSrch(int *a,int n,int val){
    //Declare and initialize variables
    int beg,end,middle;
    beg=0;
    end=n;
    //Loop and find
    do{
        middle=(end+beg)/2;
        if(*(a+middle)==val)return middle;
        else if(a[middle]>val){
            end=middle-1;
        }else{
            beg=middle+1;
        }
    }while(end>=beg);
    return -1;
}

void mrkSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        smlList(a,n,i);
    }
}

void smlList(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        //if(a[i]<a[pos])swap((a+i),(a+pos));
        if(a[i]<a[pos])swap(&a[i],&a[pos]);
    }
}

void swapLgc(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
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