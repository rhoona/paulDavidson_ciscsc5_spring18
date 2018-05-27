

/* 
 * File:   main.cpp
 * Author: Paul
 */


 

#include <iostream>
using namespace std;
 
const float companyGenerated = .58; // percent of sales company keeps
const float MLLN = 1e6f;
const float yearSales = (8.6 * MLLN);


int main(int argc, char** argv) {
    
   int result = (yearSales*companyGenerated);
    
    cout << yearSales/MLLN << " Million" <<" Based off .58 aka 58% of sales the company would generate "<< result <<" Thousand"<<endl;
    
    
    
    

   return 0;
}

