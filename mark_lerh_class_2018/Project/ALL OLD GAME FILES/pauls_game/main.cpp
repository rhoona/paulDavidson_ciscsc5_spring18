/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //if i can figure out how to input this from a file i can get that one done easy
    //return to this once more progress done
    
    srand(time(0));
    //Declare Variables
    string test[5];
    test[0]= "ahead";
    test[1]= "apple";
    test[2]= "actor";
    test[3]= "acted";
    test[4]= "adore";
    string guess;
    string aWords = test[rand()%5];
    
    int attempts=0;
    
    //=======================//
    
    cout<<aWords<<endl;
    cout<<"******************************\n";
    cout<<"   Welcome to Paul's Game!\n";
    cout<<"******************************\n";
    cout<<"The objective of this game is for\n"
             "you to guess the correct word\n"
            "within the amount of chances given!\n\n";
    cout<<"        Lets begin!     \n "
        "************************\n";
      cout<<"The word begins with [a]\nand is [5] letters long\n";
    
    do{
        //works good  with empty space for a input to guess
        cout<<" ";
                cin>>guess;
    
    attempts++;
    //AWSOME!!!!!!!!!!!!!!!
    cout<<attempts<<endl;
    if(guess==aWords)
        cout<<"Winner!!";
    //Initialize Variables
  
    //Process/Map inputs to outputs
    }while(guess != aWords);
    
    //Output data
    
    //Exit stage right!
    return 0;
}