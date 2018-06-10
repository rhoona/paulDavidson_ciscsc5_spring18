/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 4, 2018, 7:26 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

const float taxed = .0675*88.67;
const float tip = .20;


int main(int argc, char** argv) {

    float sales = 88.67, taxTotal;
    float result;
    

    
    
    cout <<"Your tax amount will be " << taxed << endl;
    
    cout << "Add your taxed amunt to total for " << taxed + sales << endl;
    
    cout << "Now to find a 20% tip of your total taxed amount is " << (taxed + sales)*.20 << endl;
    
    cout << "Now your total bill is " << (taxed + sales) * .20 + sales << endl;

      
    
             
             
    
     
   
    
    
    return 0;
}

