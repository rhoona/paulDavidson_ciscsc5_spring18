/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 4, 2018, 9:05 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */



int main(int argc, char** argv) {

    float a=15.95,
          b=24.95,
          c=6.95,
          d=12.95,
          e=3.95;
    float total=(a+b+c+d+e);
    float tax=.07*total;
    
          
  
   
    
    cout << a <<endl;
    cout << b <<endl;
    cout << c <<endl;
    cout << d <<endl;
    cout << e <<endl;
    cout <<"The total of all these sums is "<< total << endl;
    cout <<"Total of all these sums plus, 7% tax is "<< tax+total <<endl;
   
    return 0;
}

