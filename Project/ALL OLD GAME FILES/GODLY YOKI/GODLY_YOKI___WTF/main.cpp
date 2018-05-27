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
#include <windows.h>
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
    
    char start=0,card='c',jailVst='v',choice,roll;
    
    int money,payment,p1Position = start,p2Position = start,p3Position = start,
            p4Position = start,p1Roll,p2Roll,p3Roll,p4Roll,p1Turn=0,turn,p2Turn=0,p3Turn=0,
            dice,test,p1Money=5,p2Money=5,p3Money=5,p1Yoki=0,p2Yoki=0,p3Yoki=0,count=0,turnskip=0,jail;
   
    
    short spots;/* spot1 = 0, spot2=1, spot3=1,spot4=card,spot5=1,spot6=1,
         spot7=jailVst, spot8 =2, spot9=2, spot10=card,spot11=2,spot12=2,spot13=0,
         spot14=3,spot15=3,spot16=card,spot17=3,spot18=3,spot19=jail,spot20=4,
         spot21=4,spot22=card,spot23=5,spot24=5;*/
    //seed rand (one time)
    srand(static_cast<unsigned int>(time(0)));
    
    //Initialize Variables
    
    //for (2) dice, rolls 2-12
 
 
                           
 //("\033[22;34mHello world!");
    
  
    //Process/Map inputs to outputs
    
    cout<<"******************************\n";
   system("colour, 0A");
   cout<<  "Welcome to Paul's Game!\n";
     cout<<("\033[22;32m******************************\n");
    cout<<"(1)\"you are\" Player 1, the computer is players 2-4\n";
    cout<<"{2}All players start the game with $5 from the bank\n";
    cout<<"(3)First player to gather 5 yo-ka-watches wins.\n\n";
    
    do{
        count++;
        //THIS IS GOOD TO DECIDE TURNS ++ AND THAN -- them 
        
        do{
            cout<<"Press R to roll the dice!"<<endl;
            cout<<"\033[22;32m*****************************************\n";
            cin>>roll;
            cout<<"*****************************************\n";
            /* I know this looks UGLY! but it actuarly looks nice! Its the
             bar showing your money, yokis and position. the lines were super long
             so */
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
                }while(p1Roll<2 || p1Roll >12 );
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
        cout<<setw(120)<< "***************************************"<<endl;
        cout<<setw(115)<<" It is now Player 2's turn!"<<endl;
      
           
        
        do{
    
        p2Roll = rand()%13,2;
                }while(p2Roll<2 || p2Roll >12 && turnskip == 0);
                if(turnskip == 0){
                 p2Position = p2Position + p2Roll;
                cout<<setw(120)<<"*****************************************"<<endl;
                cout<<setw(110)<<"Player[2] rolled "<<p2Roll<<endl;
                cout<<setw(120)<<"*****************************************"<<endl;
                }
                
                       if(p2Position>=23)
            {
                cout<<setw(130)<<"Player[2]whent around the board and recieve $3 from the bank"<<endl;
                p2Money = p2Money + 3;
                p2Position = p2Position - 23;
                cout<<setw(120)<<"*****************************************"<<endl;
            }
 
          
        
  
        
        
                // START IF ALL POSITIONS FOR P2
        do{
            
            //start of Position 2 for p2 
        p2Roll++;
                    if(p2Position == 0 ){
            
                cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
                cout<<setw(120)<<        "*****************************************"<<endl;
                    
                     if(p2Money < 1 && p2Position == 2){
                    
                        cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                     }
                       
                 if(p2Money >= 1 && p2Position == 2){
                    p2Money=p2Money-1;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $1"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 
           
                      
                    
                      
                   
                 }
                    }
        
        // start position 1 for p2
                      if(p2Position == 1){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 1){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 1){
                    p2Money=p2Money-1;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $1"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
                     
        //Start of position 4 for P2
        
                              if(p2Position == 4){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 4){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 4){
                    p2Money=p2Money-1;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $1"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
        
        //start of Position 5 for p2
        
                                      if(p2Position == 5){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 5){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 5){
                    p2Money=p2Money-1;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $1"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
        
        
        
        
        //start of position 6 for p2
        
                                      if(p2Position == 6){
                                         
  
                    
                
                    cout<<setw(130)<<"AHHH! Player[2] landed on Jail {no worries JUST VISITING"<<endl;
                    cout<<setw(130)<<"player[2] gains nothing, loses nothing and ends turn."<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                    
     
                 }
           
        
        //START IF position 7 for p2
        
           
                                      if(p2Position == 7){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 7){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 7){
                    p2Money=p2Money-2;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
                          
        //start of position 8 for p2
        
                                              if(p2Position == 8){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 8){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 8){
                    p2Money=p2Money-2;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
                          
        //Start of positon 10 for p2
        
            if(p2Position == 10){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 10){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 10){
                    p2Money=p2Money-2;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
        
        //start of position 11 for p2
        
             if(p2Position == 11){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 11){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 11){
                    p2Money=p2Money-2;
                    
                
                    cout<<setw(115)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
                                    if(p2Position == 12){
                     
                    cout<<setw(120)<<"oHHH you landed on the ""Just Parking spot"<<endl;
                    cout<<setw(125)<<"player[2] gains nothing, loses nothing and ends turn."<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                    
     
                 }
        
        // start of position 13 for P2
                
             if(p2Position == 13){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
             }
      
      if(p2Money < 3 && p2Position == 13){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
      }
                               
                 if(p2Money >= 3 && p2Position == 13){
                    p2Money=p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
      
                         
        
        
                  if(p2Position == 14){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
             }
      
      if(p2Money < 3 && p2Position == 14){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
      }
                               
                 if(p2Money >= 3 && p2Position == 14){
                    p2Money=p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
        
                
                  if(p2Position == 16){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
             }
      
      if(p2Money < 3 && p2Position == 16){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
      }
                               
                 if(p2Money >= 3 && p2Position == 16){
                    p2Money=p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
        
             
                               if(p2Position == 17){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
             }
      
      if(p2Money < 3 && p2Position == 17){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
      }
                               
                 if(p2Money >= 3 && p2Position == 17){
                    p2Money=p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
        /* ok finaly got it to work!
         
         this is for setting JAIL!, if player2 lands n jail */
        if(p2Position == 18 && turnskip != 2 && p2Money < 1)
        {
            
         ++turnskip;
         
            cout<<setw(110)<<"REAL JAIL!!! MUST MISS A TURN"<<endl;
           
            
        }
        
        if(p2Position == 18 && turnskip == 2)
        {
           
            p2Position == 12;
            turnskip = turnskip - 2;
        }
        if(p2Position == 18 && p2Money >= 1)
        {
            cout<<setw(115)<<"Player[2] landed IN JAIL!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(115)<<"Player[2] payed $1 to get out of jail"<<endl;
            cout<<setw(120)<<        "*****************************************"<<endl;
            cout<<setw(110)<<"Player[2] now has $"<<p2Money - 1<<" left"<<endl;
            
                    p2Position == 12;
            p2Money = p2Money - 1;
        }
        
        
        if(p2Position == 19){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $4"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
             }
      
      if(p2Money < 4 && p2Position == 19){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
      }
                               
                 if(p2Money >= 4 && p2Position == 19){
                    p2Money=p2Money-4;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $4"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
         
   
                 }
        
        
             if(p2Money < 4 && p2Position == 20){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
      }
                               
                 if(p2Money >= 4 && p2Position == 20){
                    p2Money=p2Money-4;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $4"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
         
                 }
        
        
        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
        
        
                if(p2Money >= 5 && p2Position == 22){
                    p2Money=p2Money-5;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $5"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
         
   
                 }
        
        
             if(p2Money < 5 && p2Position == 22){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
      }
                               
                 if(p2Money >= 5 && p2Position == 22){
                    p2Money=p2Money-5;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $5"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
         
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
