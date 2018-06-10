/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 9, 2018, 11:05 AM
 * chapter3_prob_15
 * 
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float assValue, //assessed value of property is 60% proValue
            proValue, //Property value * .6 for assValue
            proTax,  //property tax is 75cents for each 100 dollars4
            PRCNT=100;
            
            
            
    cout <<"What is your property Value? "<<endl;
    cin>>proValue;
    
    assValue=proValue*.6;
    
    cout <<"Your assessed vallue is "<<assValue<<endl;
    
    
 
    cout << "What is your Property tax? "<<endl;
    cin>>proTax;
    
    cout<<"You will pay "<<assValue*proTax/PRCNT<<endl;
    
    
   
            
    
    
    

    return 0;
}
