/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int countF(int);
int main(int argc, char** argv) {
    //Declare Variables
    const int BIG = 100;
    const int ROWS = 3;
    const int COLMS = 5;
   int probArray[ROWS][COLMS];
   int test3[BIG];
   int test,test2;
   int x;
   int mCount = 1;
   int lol = 0;
  static int total1;
   string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
   
    //Initialize Variables

       
   for(int i = 0; i < ROWS; i++)
   {
       cout<<"Give me the data for monkey # "<<mCount++<<endl;
       lol =0;
       
     
     
       for(int x = 0; x < COLMS; x++)
       {
           for(int y = 0; y<x;y++)
           {
           cout<<days[lol]<<endl;
           cin>>test3[y];
           lol++;
           }   //total1=countF(test);

           test2+=test;
           
       }
     
       
      // cout<<test2;
 //cout<<"AH HA! the sum of all your input is "<<total1;
   }
   //cout<<test3[0];


       
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}
int countF(int x)
{
   //  int total;
    
    //total += x;
   // return total;

}