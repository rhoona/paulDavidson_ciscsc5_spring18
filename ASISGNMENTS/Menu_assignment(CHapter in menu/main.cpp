/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int choice;
    char N,Y,test;
    
    //Display Menu
    cout<<"Welcome to my Menu Professor Leah."<<endl;
    cout<<"You may choose from one of the follow choices"<<endl;
    cout<<"Press [1] for Chapter 4 Problem 27"<<endl;
    cout<<"Press [2] for chapter 4 Problem 25"<<endl;
    cout<<"Press [3] for chapter 4 problem 16"<<endl;
    cout<<"Press [4] for chapter 4 problem 9"<<endl;
    cout<<"Press {5} for chapter 4 problem 10"<<endl;
    cout<<"Press [6] for chapter 4 problem 10"<<endl;
    cout<<"Press [7] for chapter 4 problem 2"<<endl;
    cin>>choice;

switch (choice) {
    case 1: {
         cout << "Ahh you seem to be having technical difficulty!\n" 
                "First Step, reboot your computer than try to connect\n"
                "Did that work? Y for yes N for no"<< endl;
        cin>>test;
        
        if(test=='Y'){
        cout<<"Hey it worked!!! Im glad i could help ;)"<<endl;
        }
        else if(test=='N') {
            cout<<"Ok lets go to next step \n"
                  "Now try to reboot the Router\n" 
                   "Did that work? Y/N"<<endl;
            cin>>test;
            if(test=Y){
                cout<<"WELL glad we figured it out!"<<endl;
            }
            else if(test==N){
                cout<<"HMM what a tricky sitution \n"
                      "Well dont panic!\n"
                      "I cant help you but atleast now you "
                      "know two things that wont fix it!"<<endl;
                
                      
            }
        }
        
        
        break;
    }
    //end of 1 start of 2
    case 2: {
        int Agig,Bgig;
        
        float A,B,C,Gigamount,result,resultB;
        char Ptype;
        
        A=39.99;
        Agig=10.00;  // 10$ per gig plan A
        B=59.99;
        Bgig=5.00;  //$5 per gig with plan B
        C=69.99;
        
        
        cout<<"Which package did you purchase?"<<endl;
        cin>>Ptype;
        cout<<"How many gigs did you use?"<<endl;
        cin>>Gigamount;
        
       
        if(Ptype=='A'){
            cout<<"You chose plan A, and used "<<Gigamount<<" Gigs\n"
                  "My calculations show your total is"<<endl;
             result=(Gigamount - 4.00)*10.00+A;
            cout<<result<<endl;
        }
            
         if(Ptype=='B' && Ptype !='A'){
            cout<<"You chose plan B, and used "<<Gigamount<<" Gigs\n"
                  "My calculations show your total is"<<endl;
             result=(Gigamount - 8.00)*5.00+B;
            cout<<result<<endl;
                   }
        
        if(Ptype=='C'){
            cout<<"You chose plan C and used "<<Gigamount<<" Gigs\n"
                   "My calculations show your total is"<<endl;
            result=C;
            cout<<result<<endl;
        }
            
           
        

       
        break;
}
      case 3: {
          
          string name1,name2,name3;
          float time1,time2,time3;
          
          
        cout << "Enter the name of the [3] runners."<< endl;
        cin>>name1>>name2>>name3;
        
        cout<<"Now enter the [3] times in order"<<endl;
        cin>>time1>>time2>>time3;
        
        if(time1 >time2 && time3){
            
            cout<<name1<<" Was in first"<<endl;
        }
        else if(time2 >time1 && time3){
            cout<<name2<<" Was in first"<<endl;
        }
       else if(time3 > time2 && time1){
            cout<<name3<<" Was in first"<<endl;
        
       }
        else if(time3 > time1 && time2){
            cout<<name3<<" was the winner"<<endl;
        }
        
        break;
    }
            case 4: {
                float quarterNum,dollarNum,penniesNum,quarter,dollar,pennies,dime,dimeNum;
                float result, total;
                
                
                quarter = 0.25;
                dollar = 1.00;
                pennies = 0.01;
                dime = 0.10;
                
                cout<<"How many Quarters do you have?"<<endl;
                cin>>quarterNum;
                
                cout<<"How many dimes do you have?"<<endl;
                cin>>dimeNum;;
                
                cout<<"How many pennies do you have?"<<endl;
                cin>>penniesNum;
                
                result=(quarterNum*quarter) + (dimeNum*dime) + (pennies*penniesNum);
                cout<<"Lets count this money"<<endl;
                cout<<"Your total  = "<<result<<endl;
                
                if(result==dollar){
                    cout<<"Hey you did it perfect!"<<endl;
                }
                else if(result>dollar){
                    cout<<"Man you whent $"<<result-dollar<<" over"<<endl;
                }
                else{
                    cout<<"Aww im sorry  you were short " <<dollar-result<<endl;
                    
                }
                
              
                

        break;
}
            case 5: {
                
                int month,year;
                
                cout<<"Enter the month (1-12)"<<endl;
                cin>>month;
                        
                cout<<"Enter the year"<<endl;
                cin>>year;
                
                if(year%100 ==0){
                  
                }
                if(year%400==0){
                    cout<<"This is leap year"<<endl;
                    
                    
                   
                }else{
                    cout<<"This is not a leap year"<<endl;
                }
                        
                    
                

                
             
                
        break;
            }
            case 6: {
                
                float num1,num2;
                
        cout << "Enter two numbers to compare"<< endl;
        cin>>num1>>num2;
        
        if(num1>num2){
            cout<<num1<<" Is larger than "<<num2<<endl;
        }
        else if(num2>num1){
            cout<<num2<<" is larger than "<<num1<<endl;
        }
        
        break;
            }
            case 7: 
                int num;
            
                cout<<"enter 1-10"<<endl;
                cin>>num;
                
                switch(num){
                    case 1:{
                        cout<<"the roman numeral for 1 is I"<<endl;
                        break;
                    }
                    case 2:{
                        cout<<"2 is II"<<endl;
                        break;
                    }
                    case 3:{
                        cout<<"3 is III"<<endl;
                        break;
                    }
                    case 4:{
                        cout<<"4 is IIII"<<endl;
                        break;
                    }
                        
        cout << "it works!!" << endl;
        break;
            }
            case 8: {
        cout << "it works!!" << endl;
        break;
            }
            case 9: {
        cout << "it works!!" << endl;
        break;
            }
            case 10: {
        cout << "it works!!" << endl;
        break;
            }default:
                cout<<"UMMM does try reading the rules and ENTER a number 1-9"<<endl;
                break;
            }

            
            

    
                        
                        
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}