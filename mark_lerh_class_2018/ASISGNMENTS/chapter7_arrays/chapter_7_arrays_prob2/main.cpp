/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on April 1, 2018, 6:22 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;







void rainFall();
int main(int argc, char** argv) {

  

    
    rainFall();
    
    
    return 0;
    
    
}

void rainFall()
{
    const int SIZE = 12;
    string months[SIZE] = { "January", "Feburary", "March", "April",
    "May","June","July","August","Septemeber", "October", " Novemeber", "Decemeber"};
    int rain[SIZE];
    int amount[SIZE];
    int total = 0;
    int highest;
    int lowest;
   string wtf;
   string wtf2;
  
    
    for(int count = 0; count < SIZE; count++)
    {
        cout<<"Enter how much rain for "<<months[count]<<endl;
        cin>>amount[count];
        total += amount[count];
       
        if(amount[count] > highest)
        {
                    wtf = months[count];

            highest =  amount[count];        
            
        }
        
        if(amount[count]< lowest)
        {
            wtf2=months[count];
            lowest = amount[count];
        }

        
    }       
    cout<<"The highests rain fall was "<<wtf<<" "<<"with "<<highest<<" inches"<<endl;
    cout<<"The lowest rain fall was "<<wtf2<<" "<<"with "<<lowest<<" inches"<<endl;
    
        cout<<"The average rain fall is! "<<total/SIZE<<endl;

    }

