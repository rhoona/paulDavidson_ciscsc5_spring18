/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on April 1, 2018, 6:22 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;






void function();
int main(int argc, char** argv) {
    
    function();
    
    
  //  function();
    
    return 0;
    }
void function()
{
    int spools,stock,nPrice = 10,charges,avail = stock%spools;
    
    
    cout<<"Enter how many spools ordered ";
    cin>>spools;
    cout<<"How many in stock? ";
    cin>>stock;
    cout<<"Are there special S/H charges? ";
    cin>>charges;
    if(spools > stock){
   cout<<"You ordered "<<spools<<" but there are only "<<stock<<" in stock!";
    cout<<"To buy all we have will cost $"<<stock*100+((nPrice+charges)*stock)<<endl;
    cout<<"And we will have to order "<<spools-stock<<" More for you! sorry";
    }
    else if(spools <= stock)
    {
        cout<<"You ordered "<<spools<<" and we have enough in stock for your purchase!\n";
        cout<<"Your order will cost $"<<stock*100+((nPrice+charges)*stock);
    }
  
    
   
    
    
}