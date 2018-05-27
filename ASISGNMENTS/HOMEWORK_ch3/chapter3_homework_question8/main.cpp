/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 9, 2018, 7:12 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    float palletWeight, 
          withWidets, 
          result,
          widgetWeight = 12.5; //pounds
    
    
    cout << "How much does the Pallet weigh?"<<endl;
    cin >> palletWeight;
    
    cout <<"How much does the pallet weigh with the widgets on it?"<<endl;
    cin >> withWidets;
    
    result = (withWidets - palletWeight) / widgetWeight;
    
    cout<<"Your Pallet has "<<result<<" widgets weighing it down man"<<endl;
          
            
        
            
    
    
    
    return 0;
}

