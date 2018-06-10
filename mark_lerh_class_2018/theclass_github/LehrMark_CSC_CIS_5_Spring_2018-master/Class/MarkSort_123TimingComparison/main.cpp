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
void fillAry(int [],int);
void prntAry(int [],int,int);
void mrkSort1(int [],int);
void mrkSort2(int [],int);
void mrkSort3(int [],int);
void swap1(int &,int &);
void swapLgc(int &,int &);
void smlList(int [],int,int);
void smlList2(int [],int,int);
int  binSrch(int [],int,int);
void copy(int [],int[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=2000;
    int a[SIZE],b[SIZE],c[SIZE];
    
    //Initialize Variables
    fillAry(a,SIZE);
    copy(b,a,SIZE);
    copy(c,a,SIZE);
    
    //Print the Array
    //prntAry(a,SIZE,10);
    //prntAry(b,SIZE,10);
    //prntAry(c,SIZE,10);
    
    //Process/Map inputs to outputs
    int beg=time(0);
    mrkSort1(a,SIZE);//1 Function Sort
    int end=time(0);
    cout<<"Total Time in 1 Function Mark Sort = "<<end-beg<<" secs"<<endl;
    beg=time(0);
    mrkSort2(b,SIZE);//2 Function Sort
    end=time(0);
    cout<<"Total Time in 2 Function Mark Sort = "<<end-beg<<" secs"<<endl;
    beg=time(0);
    mrkSort3(c,SIZE);//3 Function Sort
    end=time(0);
    cout<<"Total Time in 3 Function Mark Sort = "<<end-beg<<" secs"<<endl;
    
    //Output data
    //prntAry(a,SIZE,10);
    //prntAry(b,SIZE,10);
    //prntAry(c,SIZE,10);
    
    //Find an element
    /*int find=50;
    cout<<find<<" was found at index = "
            <<binSrch(a,SIZE,find)<<endl;
    cout<<find<<" was found at index = "
            <<binSrch(b,SIZE,find)<<endl;
    cout<<find<<" was found at index = "
            <<binSrch(c,SIZE,find)<<endl;
    */
    
    //Exit stage right!
    return 0;
}

int  binSrch(int a[],int n,int val){
    //Declare and initialize variables
    int beg,end,middle;
    beg=0;
    end=n;
    //Loop and find
    do{
        middle=(end+beg)/2;
        if(a[middle]==val)return middle;
        else if(a[middle]>val){
            end=middle-1;
        }else{
            beg=middle+1;
        }
    }while(end>=beg);
    return -1;
}

void copy(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

void mrkSort1(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void mrkSort3(int a[],int n){
    for(int i=0;i<n-1;i++){
        smlList(a,n,i);
    }
}

void smlList(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        for(int i=pos+1;i<n;i++){
            if(a[i]<a[pos]){
                swapLgc(a[i],a[pos]);
            }
        }
    }
}

void swapLgc(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

void swap1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void mrkSort2(int a[],int n){
    for(int i=0;i<n-1;i++){
        smlList2(a,n,i);
    }
}

void smlList2(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[i]<a[pos]){
            int temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
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
        a[i]=rand();
    }
}