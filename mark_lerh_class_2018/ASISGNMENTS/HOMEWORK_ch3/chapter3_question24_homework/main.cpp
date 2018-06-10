/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 10, 2018, 10:56 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    float   v,
            r,
            e,
            s;
          
    
    cout<<"Enter the length of the row in feet"<<endl;
    cin>>r;
    
    cout<<"Enter amount of space used by the post in feet"<<endl;
    cin>>e;
    
    cout<<"Enter the space between the vines in feet"<<endl;
    cin>>s;
    
    v = (r - 2*e) / s;
            
    cout <<"You can plant "<<v<<" Plants with that space :)"<<endl;
    
    

    return 0;
}

