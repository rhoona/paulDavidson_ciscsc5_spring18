/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 9, 2018, 6:21 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

const float insurPrcnt=0.8;

int main(int argc, char** argv) {
    
    float a;
    
    cout<<"Enter your Property value for insurance quote"<<endl;
    cin>>a;
    
    a *=insurPrcnt;
    
    cout<<"Well for that much you should get about $"<<a<<" In insurance, or not"<<endl;
    
    
    

    return 0;
}

