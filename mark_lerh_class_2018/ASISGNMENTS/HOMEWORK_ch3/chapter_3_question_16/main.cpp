/* 
 * File:   main.cpp
 * Author: Paul Davidson
 * Created on march 9 2018
 * Purpose:  chapter 3 homework problem #16
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

const float PRCNT=100;

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
  float  seniorDiscount=5e3f,
          homeValue,
          assedValue,
          tax,
          quartlyPay,
          result,
          assessed;
    
    
    
    //Initialize Variables
   

  
    //Process/Map inputs to outputs
  
    cout <<"What is your Home value? "<<endl;
  cin >> homeValue;
  
    assessed=homeValue*0.6;
  
  cout <<"Your assets are assessed at "<<assessed<<endl;
  
  cout <<"What is your tax rate? " <<endl;
  cin >> tax;
  
  cout << "With your senior discount of "<<seniorDiscount<<" you will pay\n";
  
  result= (assessed-seniorDiscount)*tax/PRCNT;
  
  
  cout<<result<<endl;
  
  cout <<"You are allowed to pay this in quartly payments of "<<result/4<<endl;
  
  
  
    
    //Output data
   
    
    //Exit stage right!
    return 0;
}


