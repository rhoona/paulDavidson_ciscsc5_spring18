/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 4, 2018, 8:54 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float payAmount=2200.0;
    float payPeriods=26;
    float annualPay;

    
    annualPay=payAmount*payPeriods;
   
    cout <<"The employyes annual pay is 26*2200.0 which is "<< annualPay <<endl;
    
    return 0;
}

