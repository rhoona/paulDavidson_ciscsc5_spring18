/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here


        int main(int argc, char** argv) {
            srand(time(0));
             int ARRAY_SIZE;
             int count = 1;
             int total = 0;
             ofstream outputFile;
             ifstream inputFile;
             int x;
    
         cout<<"Enter how many numbers we gunna sort :)";
        cin>>ARRAY_SIZE;
        
        //chooses the array size also have lowest start here so it can be initiaslized 
        //with numbers chosen array size! works sweet oh also highest is here but could be
        //probably set to 0 or 1
         int numbers[ARRAY_SIZE];
   unsigned int lowest=numbers[0];
            for(count = 0; count < ARRAY_SIZE; count++)
             numbers[count]=rand()%99+1;
         
            outputFile.open("SavedNumbers.txt");
    
         for(count = 0; count < ARRAY_SIZE; count++)
         
         outputFile << numbers[count] <<'\n';
         outputFile.close();
         
         
        ///////////////////////////////////
         
         inputFile.open("SavedNumbers.txt");
         
         while(count < ARRAY_SIZE && inputFile >> numbers[count])
             count++;
         
         inputFile.close();
         cout<<"Here are all the numbers generated friend :)\n";
         for(int x = 0; x< ARRAY_SIZE; x++)
         {
             cout<<numbers[x]<<" ";
         }
            unsigned int highest=numbers[0];

         for(int x = 0; x < ARRAY_SIZE; x++)
         {
             if (numbers[x] > highest)
             highest = numbers[x];
         }
         {
             cout<<"\nThe highest number in the set is! "<<highest<<endl;
         }
         for(int x = 0; x < ARRAY_SIZE; x++)
         {
             if(numbers[x] < lowest)
                 lowest = numbers[x];
         }
         {
             cout<<"The lowest number in your set is! "<<lowest<<endl;
         }
         for(int x = 0; x < ARRAY_SIZE; x++)
         {
             total += numbers[x];
         
         } 
         {
             cout<<"The total sum is! "<<total<<endl;
         }
         float avg = total/ARRAY_SIZE;
         cout<<fixed<<showpoint<<setprecision(2);
         cout<<"The average of all these numbers is! "<<avg<<endl;
         cout<<"\n\n";
         cout<<"if you run this and see this i have two issues with this code\n"
                 "first, i had to make lowest a unsigned int otherwise it broke\n"
                 "than i had to make highest one also cause than that broke if now\n"
                 "than i wanted the average to be a float (last part of code)\n"
                 "but for some reason wont work strange...";
         return 0;
}


    
   
    
 


   
  