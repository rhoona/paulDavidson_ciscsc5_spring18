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
    char p1, p2, p3, p4,begin,test1,p1Jail;
    
    char start=0,card='c',jailVst='v',choice,roll;
    
    int money,payment,p1Position = start,p2Position = start,p3Position = start,
            p4Position = start,p1Roll,p2Roll,p3Roll,p4Roll,p1Turn=0,turn,p2Turn=0,p3Turn=0,
            dice,test,p1Money=5,p2Money=5,p3Money=5,p1Yoki=0,p2Yoki=0,p3Yoki=0,count=0,turnskip=0,jail,p1TurnSkip=0,
            p1Sp1Ownd=0,p1Sp2Ownd=0,p1Sp4Ownd=0;
           
    int p2Sp1Ownd=0,p2Sp2Ownd=0;
   
    
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
        if(p1Position == 18 && p1Jail != 'Y' && p1TurnSkip !=1){
            p1TurnSkip++;
            goto test;
        }
        if(p1Position == 18  && p1Jail != 'Y' && p1TurnSkip ==1){
            p1Position = 6;
            p1TurnSkip = 0;
        }
      
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
        
        
           /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 1
  * 
 ===============================================================================
  */ 
        //if player 2 owns spot 1
        
        if(p1Position == 1 && p1Sp1Ownd == 0 && p2Sp1Ownd == 1 && p1Money >= 1)
        {
            p1Money = p1Money - 1;
            p2Money = p2Money + 1;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $1 if you have enough money!\n"
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        }
        
        
        if(p1Position == 1 && p1Sp1Ownd == 1){
                    cout<<"YOU OWN THIS PROPERTY!"<<endl;
                }
            if(p1Position == 1 && p1Sp1Ownd == 0 && p2Sp1Ownd == 0)
            {
                cout<<"You landed on a yo-ka that cost $1\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 1 && p1Sp1Ownd == 0 && p2Sp1Ownd == 0){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(p1Position == 1 && choice == 'Y' && p1Money >= 1 && p2Sp1Ownd == 0){
                p1Money = p1Money-1;
                p1Sp1Ownd = 1;
             
                cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
                
            }
                
                   }
        
        
                  /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 2
  * 
 ===============================================================================
  */ 
        
         if(p1Position == 2 && p1Sp2Ownd == 1){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        }
            if(p1Position == 2 && p1Sp2Ownd == 0)
            {
                cout<<"You landed on a yo-ka that cost $1\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 1 && p1Sp2Ownd == 0){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 1 && p1Sp2Ownd == 0){
                p1Money = p1Money-1;
                p1Sp2Ownd = 1;
             
                cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
             cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                
                   }
        
              /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 4
  * 
 ===============================================================================
  */ 
                    if(p1Position == 4 && p1Sp4Ownd == 1){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        }
        
        if(p1Position == 4 && p1Sp4Ownd == 0)
            {
                cout<<"You landed on a yo-ka that cost $1\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 1 && p1Sp4Ownd == 0){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 1 && p1Sp4Ownd == 0){
                p1Sp4Ownd = 1;
                p1Money = p1Money-1;
             
                cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                
                   }
                
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 5
  * 
 ===============================================================================
  */ 
        //START if spot 5 for player 1
                    if(p1Position == 5)
            {
                cout<<"You landed on a yo-ka that cost $1\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 1){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 1){
                p1Money = p1Money-1;
             
                cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                
                   }
                //start if spot 6 for player 1
                // this spot is "visiting jail"
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 6
  * 
 ===============================================================================
  */ 
                                   if(p1Position == 6){
                                         
  
                    
                
                    cout<<"AHHH! YOU landed on Jail {no worries JUST VISITING"<<endl;
                    cout<<"You gains nothing, loses nothing and ends turn."<<endl;
                    cout<<"*****************************************"<<endl;
                    
     
                 }          
        /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 7
  * 
 ===============================================================================
  */ 
                            if(p1Position == 7)
            {
                cout<<"You landed on a yo-ka that cost $2\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 2){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 2){
                p1Money = p1Money-2;
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                  /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 8
  * 
 ===============================================================================
  */ 
                            if(p1Position == 8)
            {
                cout<<"You landed on a yo-ka that cost $2\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 2){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 2){
                p1Money = p1Money-2;
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                        /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 10
  * 
 ===============================================================================
  */ 
                 if(p1Position == 10)
            {
                cout<<"You landed on a yo-ka that cost $2\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 2){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 2){
                p1Money = p1Money-2;
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 11
  * 
 ===============================================================================
  */ 
         if(p1Position == 11)
            {
                cout<<"You landed on a yo-ka that cost $2\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 2){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 2){
                p1Money = p1Money-2;
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                                       /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 12
  * 
 ===============================================================================
  */ 
                            if(p1Position == 12){
                     
                    cout<<"oHHH you landed on the ""Just Parking spot"<<endl;
                    cout<<"You gains nothing, loses nothing and ends turn."<<endl;
                    cout<<"*****************************************"<<endl;
                    
     
                 }
        
        

                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 13
  * 
 ===============================================================================
  */ 
                 if(p1Position == 13)
            {
                cout<<"You landed on a yo-ka that cost $3\n "
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
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                       /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 14
  * 
 ===============================================================================
  */ 
        
                      if(p1Position == 14)
            {
                cout<<"You landed on a yo-ka that cost $3\n "
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
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
            
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 16
  * 
 ===============================================================================
  */ 
                      if(p1Position == 16)
            {
                cout<<"You landed on a yo-ka that cost $3\n "
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
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                                       /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 17
  * 
 ===============================================================================
  */ 
                      if(p1Position == 17)
            {
                cout<<"You landed on a yo-ka that cost $3\n "
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
             
                cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                      }
    
                               
               
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 18
                            * (THIS IS JAIL)
  * 
 ===============================================================================
  */ 
        
        if(p1Position == 18 ){
            
        }
  
                       if(p1Position == 18 )
            {
                cout<<"DO YOU WANT TO BREAK OUT??????t\n?"
                        "*****************************************\n";
                cin>>p1Jail;
                cout<<"*****************************************\n";
                       }
                       if(p1Jail == 'Y' && p1Money >= 1 && p1Position == 18 ){
                       p1Position = 6;
                       p1Money = p1Money - 1;
                       p1TurnSkip == 1;
            
                cout<<"You payed $1 to escape jail early !!!!"<<endl;
                       }
        if(p1Jail != 'Y' && p1Position == 18){
            p1Position == 6;
            cout<<"YOU ARE STUCK IN JAIL!!!!\n"
                    "Player{2} will now go twice, and you are moved to Spot 12;";
        }
               
                       
                       
                       
     
        
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 19
  * 
 ===============================================================================
  */ 
                       
                       
                                      if(p1Position == 19)
            {
                cout<<"You landed on a yo-ka that cost $4\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 4){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 4){
                p1Money = p1Money-4;
             
                cout<<"Ok you bought it for $4 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                         /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 20
  * 
 ===============================================================================
  */ 
                                  if(p1Position == 20)
            {
                cout<<"You landed on a yo-ka that cost $3\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 4){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 4){
                p1Money = p1Money-4;
             
                cout<<"Ok you bought it for $4 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 22
  * 
 ===============================================================================
  */ 
            
                                  if(p1Position == 22)
            {
                cout<<"You landed on a yo-ka that cost $5\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 5){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 5){
                p1Money = p1Money-5;
             
                cout<<"Ok you bought it for $5 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 23
  * 
 ===============================================================================
  */ 
                                       if(p1Position == 23)
            {
                cout<<"You landed on a yo-ka that cost $5\n "
                        "Do you wanna buy it\n?"
                        "*****************************************\n";
                cin>>choice;
                cout<<"*****************************************\n";
                
                   if(choice == 'Y' && p1Money < 5){
            
                cout<<"Not enuf money\n"
                        "*****************************************\n"<<endl;
                   }
            
            if(choice == 'Y' && p1Money >= 5){
                p1Money = p1Money-5;
             
                cout<<"Ok you bought it for $5 you have $"<<p1Money<<" Left and "
                        <<++p1Yoki<<" of 5 yoki medals\n"
                        "*****************************************\n"<<endl;
            
                
          
           if (choice != 'Y'){
               cout<<"You chose Not to buy this yoki!\n"
                       "*****************************************\n";
           }
            }
                            }
        
    
        
    
    
  /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    
 ===============================================================================
  * 
  *                         
                   * 
                   * 
                   *        END OF PLAYER 1 TURN
                   * 
                   * 
  * 
 ===============================================================================
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   */ 
          
        }while(p1Turn==0);
        

        test:
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

 /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 2
  * 
 ===============================================================================
  */       
  
        
        
             
        do{
            p2Roll++;
            
                     if(p2Position == 2 && p2Sp2Ownd == 1)
            {
                cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
                cout<<setw(120)<< "*****************************************"<<endl;
            }
        if(p2Position == 2 && p1Sp2Ownd == 1 && p2Sp2Ownd==0 && p2Money < 1){
            cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
                    "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 2 && p2Sp2Ownd == 0 && p2Money >= 1 && p1Sp2Ownd==1)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $1 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 1;
            p1Money = p1Money + 1;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 2  && p1Sp2Ownd==0 && p2Sp2Ownd==0){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 2  && p1Sp2Ownd==0){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 2 && p1Sp2Ownd == 0 && p2Sp2Ownd == 0){
                     p2Sp2Ownd = 1;
                     p2Money = p2Money-1;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $1"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
                         
        
 
         /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 1
  * 
 ===============================================================================
  */ 
        // start position 1 for p2
            if(p2Position == 1 && p2Sp1Ownd == 1)
            {
                cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
                cout<<setw(120)<< "*****************************************"<<endl;
            }
        if(p2Position == 1 && p1Sp1Ownd == 1 && p2Sp1Ownd==0 && p2Money < 1){
            cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
                    "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 1 && p2Sp1Ownd == 0 && p2Money >= 1 && p1Sp1Ownd==1)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $1 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 1;
            p1Money = p1Money + 1;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 1  && p1Sp1Ownd==0 && p2Sp1Ownd==0){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 1  && p1Sp1Ownd==0){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 1 && p1Sp1Ownd == 0 && p2Sp1Ownd == 0){
                     p2Sp1Ownd = 1;
                     p2Money = p2Money-1;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $1"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }      
                     
   /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 4
  * 
 ===============================================================================
  */ 
        if(p2Position == 4 && p1Sp4Ownd == 1 && p2Money < 1){
            cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
                    "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 4 && p1Sp4Ownd == 1 && p2Money >= 1)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $1 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 1;
            p1Money = p1Money + 1;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 4  && p1Sp4Ownd==0){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 4  && p1Sp4Ownd==0){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 4 && p1Sp4Ownd == 0){
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
            
                    p2Position == 6;
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
         cout<<setw(120)<<"*****************************************"<<endl;
         cout<<setw(120)<<"This yoki cost $5 but Player[2] only has "<<p2Money<<endl;
      }
                               
                 if(p2Money >= 5 && p2Position == 22){
                    p2Money=p2Money-5;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $5"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
         
                 }
        
                      if(p2Money >= 5 && p2Position == 22){
                    p2Money=p2Money-5;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $5"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
         
   
                 }
        
        
             if(p2Money < 5 && p2Position == 23){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
       cout<<setw(120)<<"*****************************************"<<endl;
         cout<<setw(120)<<"This yoki cost $5 but Player[2] only has "<<p2Money<<endl;
      }
                               
                 if(p2Money >= 5 && p2Position == 23){
                    p2Money=p2Money-5;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $5"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
         
                 }
                
                    }while(p2Roll==0);
               
    }while(p1Yoki != 100 && p2Yoki != 100 );
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
