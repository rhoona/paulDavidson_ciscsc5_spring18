/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int coinToss(int);
//Execution Begins Here
int main(int argc, char** argv) {
  
    srand(static_cast<unsigned int>(time(0)));
    int cTn;//coin toss number
    
    cout<<"Enter how many times you would like to toss the coin!\n";
    cin>>cTn;
    
    coinToss(cTn);
    
    return 0;
}

int coinToss(int cTn)
{
    float hcount=0.0, tcount=0.0;
    float prcnt=0.0,prcnt2=0.0;

   for(int i=0; i<cTn; i++)
   {
       int test=rand()%2+1;
       if(test==1){
           cout<<"Heads! \n";
           hcount = hcount+1;
       }else{
           cout<<"Tails! \n";
           tcount = tcount + 1;
       }
   }
    prcnt=tcount/(tcount+hcount)*100.0;
    prcnt2=hcount/(hcount+tcount)*100.0;
    cout<<" total number of tails =: "<<tcount<<" equals = "<<fixed<<showpoint<<setprecision(1)<<prcnt<<"%"<<endl;
    cout<<" total number of heads =: "<<setprecision(0)<<hcount<<"equals = "<<fixed<<showpoint<<setprecision(1)<<prcnt2<<endl;
    
}