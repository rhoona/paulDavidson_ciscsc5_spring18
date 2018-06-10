/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 4, 2018, 7:17 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

const float purchase = 95.0;
const float salesTax = .04;
const float countryTax = .02;

int main(int argc, char** argv) {
    
    
    cout <<"Ok your sales tax total on $95 is " << (salesTax + countryTax)*purchase <<" Dollars"<< endl;

    return 0;
}

