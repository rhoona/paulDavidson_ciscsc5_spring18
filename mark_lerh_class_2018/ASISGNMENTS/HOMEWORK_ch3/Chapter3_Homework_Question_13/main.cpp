/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 9, 2018, 5:19 PM
 */

#include <iostream>



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float euro,yen,number;
    

    cout <<"enter number of Us dollars you wish to convert"<<endl;
    cin>>number;
    
    cout<<"What is the current euro / yen to US conversion rate?(if unknown use .74 for Euro and 98.93 for Yen"<<endl;
    cin>>euro;
    
    //euro*number could be declared here or inside?
    cout<<"At that conversion rate you will get "<<euro*number<<" Euros"<<" For "<<number<<" Us dollars"<<endl;
    
    
    
    return 0;
}

