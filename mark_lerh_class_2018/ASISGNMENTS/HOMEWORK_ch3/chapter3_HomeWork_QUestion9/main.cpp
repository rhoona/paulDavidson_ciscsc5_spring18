/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul Davidson
 *
 * Created on March 9, 2018, 7:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float cookies;
    int cal;
    
    cout<<"How many cookies did you eat? "<<endl;
    cin>>cookies;
    
    cal = cookies * 100;
    
    cout<<"You have consumed approx "<<cal<<" Calories"<<endl;
    
    
    return 0;
}

