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
    char a,b,c;
    char p1, p2, p3, p4,begin,test1;
    
    char start=0,card='c',jail='j',jailVst='v',choice,roll;
    
    int money,payment,p1Position = start,p2Position = start,p3Position = start,
            p4Position = start,p1Roll,p2Roll,p3Roll,p4Roll,p1Turn=0,turn,p2Turn=0,p3Turn=0,
            dice,test,p1Money=5,p2Money=5,p3Money=5,p1Yoki=0,p2Yoki=0,p3Yoki=0,count=0;
   
    
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
        count++;
        //THIS IS GOOD TO DECIDE TURNS ++ AND THAN -- them 
        
        do{
            cout<<"Press R to roll the dice!\n"
                    "*****************************************\n";
            cin>>roll;
            cout<<"*****************************************\n";
            
            cout<<"===================================================================================================================================================================================================================";
        cout<<"\n"<<setw(40)<<"Your yo-kai: ["<<p1Yoki<<"] Your money: ["<<p1Money<<"] Current Position ["
                <<p1Position<<"]"<<setw(28)<<"ROUND ["<<count<<"]"<<setw(40)<<
                "Player 2s yo-kai: ["<<p2Yoki<<"] Player 2s money: "<<p2Money<<
                " Player 2's position ["<<p2Position<<"]"<<setw(38)<<endl;
        cout<<"===================================================================================================================================================================================================================\n";
            
            if(roll=='r'||roll=='R')
            {
                p1Turn++;
                //PLAYERS ROLL!
                do{
             p1Roll = rand()%13,2;
                }while(p1Roll<2 || p1Roll >12);
                 p1Position = p1Position + p1Roll;
                cout<<"*****************************************"<<endl;
                cout<<"You rolled "<<p1Roll<<endl;
                cout<<"*****************************************"<<endl;
            }
        
        /* This is what keeps track of when players complete a roation
         around the board. There are 24 spots with start being 0.
         players position is a combined sum of their rolls untill it reaches 23 
         than it -23 to reset the position back to 0 which is start. Than awards
         the player the money from the bank $3
         */
            if(p1Position>=23)
            {
                cout<<"You whent around the board and recieve $3 from the bank"<<endl;
                p1Money = p1Money + 3;
                p1Position = p1Position - 23;
            }
            
            /* THIS IS A VERY IMPORTANT AREA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
             THIS IS WHERE I WILL SET THE VALUE FOR EACH POSITION ON THE BOARD
             TOTAL 23
             
             WILL NEED TO WORK IN JAIL AND CARDS*/
        
            if(p1Position == 1)
            {
                cout<<"You landed on a yo-ka that cost $2\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 3){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 3){
                p1Money = p1Money-3;
             
                cout<<"Ok you bought it for $3 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"good choice!\n"
                       "*****************************************\n";
           }
            }
                
                   }
                
                
              
            

            
            
           //position needs to ve saved though whole thing
            
             //this is what decided when to change!!!
          
        }while(p1Turn==0);
        
  /*=========================================================================================
   end of player 1's turn start of player 2s                |
                                                            |    
                                                            |        
   *                                                        |
   *                                                        |
   *                                                        |
   * =====================================================================================*/
        
               do{
       
        
            
            p2Roll=rand()%13,2;
        }while(p2Roll<2 || p2Roll > 12);
        p2Position = p2Position + p2Roll;
    
        if(p2Position>=23){
            p2Money = p2Money + 3;
            p2Position = p2Position - 23;
          
        }
        cout<<setw(120)<< "***************************************"<<endl;
        cout<<setw(115)<<" It is now Player 2's turn!\n"<<endl;
        cout<<setw(120)<<" *************************************"<<endl;
        cout<<setw(105)<<"Playr[2] rolled a "<<p2Roll<<" Position "<<endl;
        cout<<setw(120)<<" *************************************"<<endl;
       
       
        
                    if(p2Position == 2 || p2Position == 3 || p2Position==4 ||p2Position==5){
            
                cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
                cout<<setw(120)<<        "*****************************************"<<endl;
                    
                     if(p2Money < 3){
                    
                        cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                     }
                       
                 if(p2Money >= 3){
                    p2Money=p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 
                  
                   
                   
                    
                    
                          
                             p2Roll++;
                 
                               
                     }
               
                    }while(p2Roll==0);
               
    }while(p1Yoki != 5 && p2Yoki != 5 );
    if(p2Yoki > p1Yoki)
    {
        cout<<"PLAYER 2 WINS";
    }
    if(p1Yoki > p2Yoki)
    {
        "PLAYER 1 WINS!!";
    }
    
   
    
    //Exit stage right!
    return 0;
}           
