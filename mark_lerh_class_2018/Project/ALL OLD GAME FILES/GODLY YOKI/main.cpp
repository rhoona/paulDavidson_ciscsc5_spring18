/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <random>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    
    //players
    char p1, p2, p3, p4,begin,test1;
    
    char start=0,card='c',jail='j',jailVst='v',choice,roll;
    
    int money,payment,p1Position = start,p2Position = start,p3Position = start,
            p4Position = start,p1Roll,p2Roll,p3Roll,p4Roll,p1Turn=0,turn,p2Turn=0,p3Turn=0,
            dice,test,p1Money=5,p2Money=5,p3Money=5,p1Yoki=0,p2Yoki=0,p3Yoki=0;
   
    
    short spots;/* spot1 = 0, spot2=1, spot3=1,spot4=card,spot5=1,spot6=1,
         spot7=jailVst, spot8 =2, spot9=2, spot10=card,spot11=2,spot12=2,spot13=0,
         spot14=3,spot15=3,spot16=card,spot17=3,spot18=3,spot19=jail,spot20=4,
         spot21=4,spot22=card,spot23=5,spot24=5;*/
    //seed rand (one time)
    srand(static_cast<unsigned int>(time(0)));
    
    //Initialize Variables
    
    //for (2) dice, rolls 2-12
 
 
                           
 
    
    
    //Process/Map inputs to outputs
    
    cout<<"******************************\n";
    cout<<"   Welcome to Paul's Game!\n";
    cout<<"******************************\n";
    cout<<"(1)\"you are\" Player 1, the computer is players 2-4\n";
    cout<<"{2}All players start the game with $5 from the bank\n";
    cout<<"(3)First player to gather 5 yo-ka-watches wins.\n\n";
    
    do{
    cout<<" enter [S] to start!     \n ";
            cin>>begin;
        "************************\n\n";
        //THIS IS GOOD TO DECIDE TURNS ++ AND THAN -- them 
        
        
            cout<<"Press R to roll the dice!";
            cin>>roll;
            if(roll=='r'||roll=='R')
            {
                //PLAYERS ROLL!
                do{
             p1Roll = rand()%13,2;
                }while(p1Roll<2 || p1Roll >12);
                 p1Position = p1Position + p1Roll;
                cout<<"You rolled "<<p1Roll<<endl;
            }
            
            
            //TESTING TO SEE IF IT LANDS ON NUMBERS ON BOARD!
            if(p1Position == 2 || p1Position == 3 || p1Position==4 ||p1Position==5)
            {
                cout<<"You landed on a yo-ka that cost $2\n "
                        "Do you wanna buy it";
                cin>>test1;
                
                   if(test1 == 'Y' && p1Money < 3){
            
                cout<<"Not enuf money\n\n"<<endl;
             }
            
            if(test1 == 'Y' && p1Money >= 3){
                p1Money = p1Money-3;
                cout<<"Ok you bought it for $3 you have $"<<p1Money<<" Left and "
                        <<p1Yoki+1<<" of 5 yoki medals\n\n"<<endl;
            }
                
          
           if (test1 != 'Y'){
               cout<<"good choice!\n\n";
           }
            }
                
              
            

            
            
           //position needs to ve saved though whole thing
            
             //this is what decided when to change!!!
          p1Turn++;
          break;
        }while(p1Turn==0 && p3Turn==0);
        
    ///////////////////////////////////////////////////////////////////////
        //end of p1turn now p2
        /////////////////////////////
        do{
       
        
            cout<<"It is now Player 2's turn!\n";
            p2Roll=rand()%13,2;
        }while(p2Roll<2 || p2Roll > 12);
        p2Position = p2Position + p2Roll;
        cout<<p2Roll;
        
        do{
                    if(p2Position == 2 || p2Position == 3 || p2Position==4 ||p2Position==5)
            {
                cout<<"You landed on a yo-ka that cost $2\n "
                        "Do you wanna buy it";
                cin>>test;
                if(test=='Y');
                cout<<"press test";
                    }
                    p2Roll++;
                    }while(p2Roll==0);
    
        
        
        /*
        {
          do{
            p2Roll = rand()%13,2;
            }while(p2Roll<2 || p2Roll >12);
             
             cout<<p2Roll<<endl;
            
            
            cout<<"WE DID IT"<<endl;
        }
       
 // starting
 */
    
    //Exit stage right!
    return 0;
}           
