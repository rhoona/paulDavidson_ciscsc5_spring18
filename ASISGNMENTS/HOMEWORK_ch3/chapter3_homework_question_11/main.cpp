/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 9, 2018, 6:04 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float loanPayment,insurance,gas,oil,tires,maintance,total;
    
    
    cout<<"Enter how much you pay for your car loanPayments,Insurance,Gas,Oil,tires and maintaince"<<endl;
    cin>>loanPayment>>insurance>>gas>>oil>>tires>>maintance;
    
    total = loanPayment+insurance+gas+oil+tires+maintance;
    
    cout<<"Your total is "<<total<<endl;
    
    

    return 0;
}

