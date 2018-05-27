/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */



///issue with p2prison not going to posiion 6
//System Libraries
#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <random>
#include <string>
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
    
    int money,payment,p1Position = 0,p2Position = 0,p3Position = start,
            p4Position = start,p1Roll,p2Roll,p3Roll,p4Roll,p1Turn=0,turn,p2Turn=0,p3Turn=0,
            dice,test,p1Money=5,p2Money=5,p3Money=5,p1Yoki=0,p2Yoki=0,p3Yoki=0,count=0,turnskip=0,jail,p1TurnSkip=0,
            p1Sp1Ownd=0,p1Sp2Ownd=0,p1Sp4Ownd=0,p1Sp5Ownd=0,p1Sp7Ownd=0,p1Sp8Ownd=0,p1Sp10Ownd=0,p1Sp11Ownd=0,
            p1Sp13Ownd=0,p1Sp14Ownd=0,p1Sp16Ownd=0,p1Sp17Ownd=0,p1Sp19Ownd=0,p1Sp20Ownd=0,p1Sp22Ownd=0,p1Sp23Ownd=0;
           
    int p2Sp1Ownd=0,p2Sp2Ownd=0,p2Sp4Ownd=0,p2Sp5Ownd=0,p2Sp7Ownd=0,p2Sp8Ownd=0,p2Sp10Ownd=0,p2Sp11Ownd=0,
            p2Sp13Ownd=0,p2Sp14Ownd=0,p2Sp16Ownd=0,p2Sp17Ownd=0,p2Sp19Ownd=0,p2Sp20Ownd=0,
            p2Sp22Ownd=0,p2Sp23Ownd=0, Jdebt=0,Jailasst=0;
    
    bool yes = true, no = false;
    
    string rules = "Welcome to pauls game! ";
    
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
    cout<<"Before you start i would like to appolgize, i had alot of fun\n"
      "making this game and spent alot of time but its not near complete\n"
      "or at the level i wanted it to be before turning it in. I got \n"
      "disracted with mid term and when i came to clean it up/add comments\n"
      "at the last few hours i had a catastrophic failure occure.\n"
       "so im using a 1 day older version. It needs clean up and shorten name\n"
            "It also has a terrible glitch i spent many hours trying to \n"
            "identify(where r && R && Y all work but if you input y bad things\n"
            "occure. Besides that the game is almost complete. I had hoped to\n"
            "implement cin/cout with the cards for the 4 empty spaces but \n"
            "was unable. Thank you for your time and enjoy.\n\n";
   
     cout<<"******************************\n";
    cout<<"(1)\"you are\" Player 1, the computer is players 2-4\n";
    cout<<"{2}All players start the game with $5 from the bank\n";
    cout<<"(3)First player to gather 10 yo-ka-watches wins.\n\n";
     /*     
 ===============================================================================
  * 
  *                         Start of Player[1] turn
  *                         And set 
  * 
 ===============================================================================
  */ 
     do{
         /*if(p1Position == 18 && p1TurnSkip !=1 && p1Jail != 'Y' && Jdebt !=2){
            p1TurnSkip++;
            Jdebt++;
            goto test;
        }
        if(p1Position == 18  && p1Jail != 'Y' && p1TurnSkip ==1){
            p1Position = 6;
            p1TurnSkip = 0;
            Jdebt = 0;
            
        }
          * */
      
        count++;
        //THIS IS GOOD TO DECIDE TURNS ++ AND THAN -- them 
      
        
        do{
            do{
            cout<<"\nPress R to roll the dice!"<<endl;
            cout<<"\033[22;32m*****************************************\n";
            cin>>roll;
            cout<<"*****************************************\n";
            /* I know this looks UGLY! but it actuarly looks nice! Its the
             bar showing your money, yokis and position. the lines were super long
             so */
            }while(roll != 'r' && roll != 'R');
            
            if(roll=='r'||roll=='R')
            
                p1Turn++;
                //PLAYERS ROLL!
                do{
             p1Roll = rand()%13,2;
                }while(Jdebt == 0 && Jailasst == 0 && p1Roll<2 || p1Roll >12  );
               
                p1Position = p1Position + p1Roll;
                cout<<"*****************************************"<<endl;
                cout<<"You rolled "<<p1Roll<<endl;
                cout<<"*****************************************"<<endl;
                
           
                
            
        
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
        //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 1 && p2Sp1Ownd == true  && p1Money < 1){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
          Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 1 && p1Sp1Ownd == false && p2Sp1Ownd == true && p1Money >= 1){
            p1Money = p1Money - 1;
            p2Money = p2Money + 1;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $1\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 1  && p1Sp1Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 1 && p1Money < 1 && p1Sp1Ownd == false && p2Sp1Ownd == false){
            cout<<"You landed on a yoki that worth [$1]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else  if (p1Position == 1 && p1Sp1Ownd == false && p2Sp1Ownd == false && p1Money >=1){
            cout<<"You landed on a yo-ka that cost $1\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 1 && p1Money >= 1 && p2Sp1Ownd == false && p1Sp1Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-1;
                p1Sp1Ownd = true;
            cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 1 && choice != 'Y' && choice != 'y' && p2Sp1Ownd == false && p1Sp1Ownd == false && p1Money >= 1){
               cout<<"You had enough to buy Position [1] but chose not to...ok\n"
                       "*****************************************\n";
        }
            
        
    
  /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 2
  * 
 ===============================================================================
  */ 
      //If player[1] lands on spot/position [2] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
        if(p1Position == 2 && p2Sp2Ownd == true  && p1Money < 1){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                    "Because of this player[1] \n"
                    "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
            if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
        }
        
           
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 2 && p1Sp2Ownd == false
                     && p2Sp2Ownd == true && p1Money >= 1){
        // long If exspression broken into 2 lines
            p1Money = p1Money - 1;
            p2Money = p2Money + 1;
            cout<<"this spot is OWND by player 2!!\n"
                  "You must pay $1\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 2  && p1Sp2Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [2] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 2 && p1Money < 1 && p1Sp2Ownd == false && p2Sp2Ownd == false){
            cout<<"You landed on a yoki that worth [$1]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else  if (p1Position == 2 && p1Sp2Ownd == false && p2Sp2Ownd == false && p1Money >=1){
            cout<<"You landed on a yo-ka that cost $1\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purachse the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
             if (p1Position == 2  && p1Money >= 1 && p2Sp2Ownd == false && p1Sp2Ownd == false && choice == 'Y' || choice == 'y'){
                p1Money = p1Money-1;
                p1Sp2Ownd = true;
            cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        //If player[1] Could have bought the position but didnt cout message
             if (p1Position == 2 && choice != 'Y' && choice != 'y' && p2Sp2Ownd == false && p1Sp2Ownd == false && p1Money >= 1 && count > 1){
               cout<<"You had enough to buy position [2] but chose not to weirdo\n"
                       "*****************************************\n";
        }
            
               
            
              /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 4
  * 
 ===============================================================================
  */ 
        //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 4 && p2Sp4Ownd == true  && p1Money < 1){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 4 && p1Sp4Ownd == false && p2Sp4Ownd == true && p1Money >= 1){
            p1Money = p1Money - 1;
            p2Money = p2Money + 1;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $1\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 4  && p1Sp4Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 4 && p1Money < 1 && p1Sp4Ownd == false && p2Sp4Ownd == false){
            cout<<"You landed on a yoki that worth [$1]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else  if (p1Position == 4 && p1Sp4Ownd == false && p2Sp4Ownd == false && p1Money >=1){
            cout<<"You landed on a yo-ka that cost $1\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 4 && p1Money >= 1 && p2Sp4Ownd == false && p1Sp4Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-1;
                p1Sp4Ownd = true;
            cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 4 && choice != 'Y' && choice != 'y' && p2Sp4Ownd == false && p1Sp4Ownd == false && p1Money >= 1){
               cout<<"You had enough to buy Position [1] but chose not to...ok\n"
                       "*****************************************\n";
        }
        
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 5
  * 
 ===============================================================================
  */ 
   //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 5 && p2Sp5Ownd == true  && p1Money < 1){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
           Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 5 && p1Sp5Ownd == false && p2Sp5Ownd == true && p1Money >= 1){
            p1Money = p1Money - 1;
            p2Money = p2Money + 1;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $1\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 5  && p1Sp5Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 5 && p1Money < 1 && p1Sp5Ownd == false && p2Sp5Ownd == false){
            cout<<"You landed on a yoki that worth [$1]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else  if (p1Position == 5 && p1Sp5Ownd == false && p2Sp5Ownd == false && p1Money >=1){
            cout<<"You landed on a yo-ka that cost $1\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 5 && p1Money >= 1 && p2Sp5Ownd == false && p1Sp5Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-1;
                p1Sp5Ownd = true;
            cout<<"Ok you bought it for $1 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 5 && choice != 'Y' && choice != 'y' && p2Sp5Ownd == false && p1Sp5Ownd == false && p1Money >= 1){
               cout<<"You had enough to buy Position [1] but chose not to...ok\n"
                       "*****************************************\n";
        }
        
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 6
  * 
 ===============================================================================
  */ 
    if(p1Position == 6 && Jdebt == 0){
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
             //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 7 && p2Sp7Ownd == true  && p1Money < 2){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 7 && p1Sp7Ownd == false && p2Sp7Ownd == true && p1Money >= 2){
            p1Money = p1Money - 2;
            p2Money = p2Money + 2;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $2\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 7  && p1Sp7Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 7 && p1Money < 2 && p1Sp7Ownd == false && p2Sp7Ownd == false){
            cout<<"You landed on a yoki that worth [$2]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 7 && p1Sp7Ownd == false && p2Sp7Ownd == false && p1Money >=2){
            cout<<"You landed on a yo-ka that cost $2\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 7 && p1Money >= 2 && p2Sp7Ownd == false && p1Sp7Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-2;
                p1Sp7Ownd = true;
            cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 7 && choice != 'Y' && choice != 'y' && p2Sp7Ownd == false && p1Sp7Ownd == false && p1Money >= 2){
               cout<<"You had enough to buy Position [7] but chose not to...ok\n"
                       "*****************************************\n";
        }
        
        
                  /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 8
  * 
 ===============================================================================
  */ 
   //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 8 && p2Sp8Ownd == true  && p1Money < 2){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
           Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 8 && p1Sp8Ownd == false && p2Sp8Ownd == true && p1Money >= 2){
            p1Money = p1Money - 2;
            p2Money = p2Money + 2;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $2\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 8  && p1Sp8Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 8 && p1Money < 2 && p1Sp8Ownd == false && p2Sp8Ownd == false){
            cout<<"You landed on a yoki that worth [$2]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 8 && p1Sp8Ownd == false && p2Sp8Ownd == false && p1Money >=2){
            cout<<"You landed on a yo-ka that cost $2\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 8 && p1Money >= 2 && p2Sp8Ownd == false && p1Sp8Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-2;
                p1Sp8Ownd = true;
            cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 8 && choice != 'Y' && choice != 'y' && p2Sp8Ownd == false && p1Sp8Ownd == false && p1Money >= 2){
               cout<<"You had enough to buy Position [8] but chose not to...ok\n"
                       "*****************************************\n";
        }
                        /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 10
  * 
 ===============================================================================
  */ 
        //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 10 && p2Sp10Ownd == true  && p1Money < 2){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 10 && p1Sp10Ownd == false && p2Sp10Ownd == true && p1Money >= 2){
            p1Money = p1Money - 2;
            p2Money = p2Money + 2;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $2\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 10  && p1Sp10Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 10 && p1Money < 2 && p1Sp10Ownd == false && p2Sp10Ownd == false){
            cout<<"You landed on a yoki that worth [$2]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 10 && p1Sp10Ownd == false && p2Sp10Ownd == false && p1Money >=2){
            cout<<"You landed on a yo-ka that cost $2\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 10 && p1Money >= 2 && p2Sp10Ownd == false && p1Sp10Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-2;
                p1Sp10Ownd = true;
            cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 10 && choice != 'Y' && choice != 'y' && p2Sp10Ownd == false && p1Sp10Ownd == false && p1Money >= 2){
               cout<<"You had enough to buy Position [10] but chose not to...ok\n"
                       "*****************************************\n";
        }
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 11
  * 
 ===============================================================================
 */ 
     //If player[1] lands on spot/position [1] and player[2] ownds its and
     //player[1]'s money is less than the set amount, player[1] has to 
     //forfeit one of his yoki's instead.
           if(p1Position == 11 && p2Sp11Ownd == true  && p1Money < 2){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            Jailasst = 1;
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 11 && p1Sp11Ownd == false && p2Sp11Ownd == true && p1Money >= 2){
            p1Money = p1Money - 2;
            p2Money = p2Money + 2;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $2\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 11  && p1Sp11Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 11 && p1Money < 2 && p1Sp11Ownd == false && p2Sp11Ownd == false){
            cout<<"You landed on a yoki that worth [$2]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 11 && p1Sp11Ownd == false && p2Sp11Ownd == false && p1Money >=2){
            cout<<"You landed on a yo-ka that cost $2\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 11 && p1Money >= 2 && p2Sp11Ownd == false && p1Sp11Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-2;
                p1Sp11Ownd = true;
            cout<<"Ok you bought it for $2 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 11 && choice != 'Y' && choice != 'y' && p2Sp11Ownd == false && p1Sp11Ownd == false && p1Money >= 2){
               cout<<"You had enough to buy Position [11] but chose not to...ok\n"
                       "*****************************************\n";
        }               
  /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 12
  * 
 ===============================================================================
  */ 
            //MAYBE SHARE?
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
        //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 13 && p2Sp13Ownd == true && p1Sp13Ownd == false && p1Money < 3){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
          Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 13 && p1Sp13Ownd == false && p2Sp13Ownd == true && p1Money >= 3){
            p1Money = p1Money - 3;
            p2Money = p2Money + 3;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $3\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 13  && p1Sp13Ownd == true && p2Sp13Ownd == false){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 13 && p1Money < 3 && p1Sp13Ownd == false && p2Sp13Ownd == false){
            cout<<"You landed on a yoki that worth [$3]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 13 && p1Sp13Ownd == false && p2Sp13Ownd == false && p1Money >=3){
            cout<<"You landed on a yo-ka that cost $3\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 13 && p1Money >= 3 && p2Sp13Ownd == false && p1Sp13Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-3;
                p1Sp13Ownd = true;
            cout<<"Ok you bought it for $3 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 13 && choice != 'Y' && choice != 'y' && p2Sp13Ownd == false && p1Sp13Ownd == false && p1Money >= 3){
               cout<<"You had enough to buy Position [13] but chose not to...ok\n"
                       "*****************************************\n";
        }       
/*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 14
  * 
 ===============================================================================
  */ 
        
              //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 14 && p2Sp14Ownd == true  && p1Money < 3){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n";
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n";
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
           Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 14 && p1Sp14Ownd == false && p2Sp14Ownd == true && p1Money >= 3){
            p1Money = p1Money - 3;
            p2Money = p2Money + 3;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $3\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 14  && p1Sp14Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 14 && p1Money < 3 && p1Sp14Ownd == false && p2Sp14Ownd == false){
            cout<<"You landed on a yoki that worth [$3]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 14 && p1Sp14Ownd == false && p2Sp14Ownd == false && p1Money >=3){
            cout<<"You landed on a yo-ka that cost $3\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 14 && p1Money >= 3 && p2Sp14Ownd == false && p1Sp14Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-3;
                p1Sp14Ownd = true;
            cout<<"Ok you bought it for $3 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 14 && choice != 'Y' && choice != 'y' && p2Sp14Ownd == false && p1Sp14Ownd == false && p1Money >= 3){
               cout<<"You had enough to buy Position [14] but chose not to...ok\n"
                       "*****************************************\n";
        }       
 /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 16
  * 
 ===============================================================================
*/ 
    //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 16 && p2Sp16Ownd == true  && p1Money < 3){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 16 && p1Sp16Ownd == false && p2Sp16Ownd == true && p1Money >= 3){
            p1Money = p1Money - 3;
            p2Money = p2Money + 3;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $3\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 16  && p1Sp16Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 16 && p1Money < 3 && p1Sp16Ownd == false && p2Sp16Ownd == false){
            cout<<"You landed on a yoki that worth [$3]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 16 && p1Sp16Ownd == false && p2Sp16Ownd == false && p1Money >=3){
            cout<<"You landed on a yo-ka that cost $3\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 16 && p1Money >= 3 && p2Sp16Ownd == false && p1Sp16Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-3;
                p1Sp16Ownd = true;
            cout<<"Ok you bought it for $3 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 16 && choice != 'Y' && choice != 'y' && p2Sp16Ownd == false && p1Sp16Ownd == false && p1Money >= 3){
               cout<<"You had enough to buy Position [16] but chose not to...ok\n"
                       "*****************************************\n";
        }                
             
 /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 17
  * 
 ===============================================================================
 */ 
      //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 17 && p2Sp17Ownd == true && p1Sp17Ownd == false && p1Money < 3){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n";
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n";
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n";
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n";
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n";
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n";
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n";
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n";
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            Jailasst = 1;
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 17 && p1Sp16Ownd == false && p2Sp17Ownd == true && p1Money >= 3){
            p1Money = p1Money - 3;
            p2Money = p2Money + 3;
            cout<<"this spot is OWND by player 2!!\n";
                    "You must pay $3\n";
        //shows updated money total for player[1] and player[2]
                 cout<<"You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 17  && p1Sp17Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 17 && p1Money < 3 && p1Sp17Ownd == false && p2Sp17Ownd == false){
            cout<<"You landed on a yoki that worth [$3]\n"
                  "but you only have " <<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 17 && p1Sp17Ownd == false && p2Sp17Ownd == false && p1Money >=3){
            cout<<"You landed on a yo-ka that cost $3\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 17 && p1Money >= 3 && p2Sp17Ownd == false && p1Sp17Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-3;
                p1Sp17Ownd = true;
            cout<<"Ok you bought it for $3 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 17 && choice != 'Y' && choice != 'y' && p2Sp17Ownd == false && p1Sp17Ownd == false && p1Money >= 3){
               cout<<"You had enough to buy Position [17] but chose not to...ok\n"
                       "*****************************************\n";
        }              
 /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 18
                            * (THIS IS JAIL)
  * 
 ===============================================================================
  */        if(p1Position == 18){
                  Jdebt = Jdebt + 1;
              }
            if(p1Position == 18 && Jdebt == 1 && Jailasst == 0)
            {
                cout<<"DO YOU WANT TO BREAK OUT??????t\n?"
                        "*****************************************\n";
                cin>>p1Jail;
                cout<<"*****************************************\n";
            }
            if(p1Jail == 'Y' && p1Money >= 1 && p1Position == 18 ){
               p1Position = 6;
               p1Money = p1Money - 1;
               Jdebt = 0;
            
        //p1TurnSkip = 1;
                cout<<"You payed $1 to escape jail early !!!!\n"<<endl;
            }
                       
           if(p1Position == 18 && p1Jail != 'Y' && Jdebt != 3 &&  p1Money < 1 ){
               cout<<"YOU ARE STUCK IN JAIL!!!!\n"
           "Player{2} will now go twice, and you are moved to Spot 6\n";
           }
        
            
            
 /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 19
  * 
 ===============================================================================
 */ 
                       
         //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 19 && p2Sp19Ownd == true  && p1Money < 4){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
          
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 19 && p1Sp19Ownd == false && p2Sp19Ownd == true && p1Money >= 4){
            p1Money = p1Money - 4;
            p2Money = p2Money + 4;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $4\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 19  && p1Sp19Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 19 && p1Money < 4 && p1Sp19Ownd == false && p2Sp19Ownd == false){
            cout<<"You landed on a yoki that worth [$4]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 19 && p1Sp19Ownd == false && p2Sp19Ownd == false && p1Money >=4){
            cout<<"You landed on a yo-ka that cost $4\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 19 && p1Money >= 4 && p2Sp19Ownd == false && p1Sp19Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-4;
                p1Sp19Ownd = true;
            cout<<"Ok you bought it for $4 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 19 && choice != 'Y' && choice != 'y' && p2Sp19Ownd == false && p1Sp19Ownd == false && p1Money >= 4){
               cout<<"You had enough to buy Position [19] but chose not to...ok\n"
                       "*****************************************\n";
        }     
 /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 20
  * 
 ===============================================================================
*/ 
    //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 20 && p2Sp20Ownd == true  && p1Money < 4){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 20 && p1Sp20Ownd == false && p2Sp20Ownd == true && p1Money >= 4){
            p1Money = p1Money - 4;
            p2Money = p2Money + 4;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $4\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 20  && p1Sp20Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 20 && p1Money < 4 && p1Sp20Ownd == false && p2Sp20Ownd == false){
            cout<<"You landed on a yoki that worth [$4]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 20 && p1Sp20Ownd == false && p2Sp20Ownd == false && p1Money >=4){
            cout<<"You landed on a yo-ka that cost $4\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 20 && p1Money >= 4 && p2Sp20Ownd == false && p1Sp20Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-4;
                p1Sp20Ownd = true;
            cout<<"Ok you bought it for $4 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 20 && choice != 'Y' && choice != 'y' && p2Sp20Ownd == false && p1Sp20Ownd == false && p1Money >= 4){
               cout<<"You had enough to buy Position [20] but chose not to...ok\n"
                       "*****************************************\n";
        }         
/*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 22
  * 
 ===============================================================================
  */ 
            //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 22 && p2Sp22Ownd == true  && p1Money < 5){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 22 && p1Sp22Ownd == false && p2Sp22Ownd == true && p1Money >= 5){
            p1Money = p1Money - 5;
            p2Money = p2Money + 5;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $5\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 22  && p1Sp22Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 22 && p1Money < 5 && p1Sp22Ownd == false && p2Sp22Ownd == false){
            cout<<"You landed on a yoki that worth [$5]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 22 && p1Sp22Ownd == false && p2Sp22Ownd == false && p1Money >=5){
            cout<<"You landed on a yo-ka that cost $5\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 22 && p1Money >= 5 && p2Sp22Ownd == false && p1Sp22Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-5;
                p1Sp22Ownd = true;
            cout<<"Ok you bought it for $5 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 22 && choice != 'Y' && choice != 'y' && p2Sp22Ownd == false && p1Sp22Ownd == false && p1Money >= 5){
               cout<<"You had enough to buy Position [22] but chose not to...ok\n"
                       "*****************************************\n";
        }    
                   /*     
 ===============================================================================
  * 
  *                         PLAYER 1 POSITION 23
  * 
 ===============================================================================
  */ 
     //If player[1] lands on spot/position [1] and player[2] ownds its and
        //player[1]'s money is less than the set amount, player[1] has to 
        //forfeit one of his yoki's instead.
           if(p1Position == 23 && p2Sp23Ownd == true  && p1Money < 5){
            cout<<"You landed on player[2]'s property but dont have enough to pay!\n";
                  "Because of this player[1] \n"
                  "MUST GIVE UP [1] yoki to player[2]\n";
           
        // This is a series of if/else if statements that cover all positions
        // On the board. This will insure that the player will forfeit their
        // most valuable yoki(the one with the highest value) first.
           if(p1Sp23Ownd == true ){
            p1Sp23Ownd = false;
            p2Sp23Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
              cout<<"Space 23 worth $5 was taken and given to player[2]\n"
                    "to cover your debt\n"; 
           
        }else if(p1Sp22Ownd == true){
            p1Sp22Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 22 worth $5 was taken and given to player[2]\n"
                  "to cover your debt\n";     
        }else if(p1Sp20Ownd == true){
            p1Sp20Ownd = false;
            p2Sp22Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 20 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";    
        }else if(p1Sp19Ownd == true){
            p1Sp19Ownd = false;
            p2Sp19Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 19 worth $4 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp17Ownd == true){
            p1Sp17Ownd = false;
            p2Sp17Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 17 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp16Ownd == true){
            p1Sp16Ownd = false;
            p2Sp16Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 16 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp14Ownd == true){
            p1Sp14Ownd = false;
            p2Sp14Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        } else if (p1Sp13Ownd == true){
            p1Sp13Ownd = false;
            p2Sp13Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 14 worth $3 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp11Ownd == true){
            p1Sp11Ownd = false;
            p2Sp11Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 11 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp10Ownd == true){
            p1Sp10Ownd = false;
            p2Sp10Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 10 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp8Ownd == true){
            p1Sp8Ownd = false;
            p2Sp8Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 8 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp7Ownd == true){
            p1Sp7Ownd = false;
            p2Sp7Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 7 worth $2 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp5Ownd == true){
            p1Sp5Ownd = false;
            p2Sp5Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 5 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";  
        }else if (p1Sp4Ownd == true){
            p1Sp4Ownd = false;
            p2Sp4Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 4 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp2Ownd == true){
            p1Sp2Ownd = false;
            p2Sp2Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 2 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else if (p1Sp1Ownd == true){
            p1Sp1Ownd = false;
            p2Sp1Ownd = true;
            p1Yoki = p1Yoki - 1;
            p2Yoki = p2Yoki + 1;
            cout<<"Space 1 worth $1 was taken and given to player[2]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        //If player[1] lands on a property owned by player[2] AND has enough
        // Money, the amount of subtracted from player[1] and added to player[2]
             if(p1Position == 23 && p1Sp23Ownd == false && p2Sp23Ownd == true && p1Money >= 5){
            p1Money = p1Money - 5;
            p2Money = p2Money + 5;
            cout<<"this spot is OWND by player 2!!\n"
                    "You must pay $5\n"
        //shows updated money total for player[1] and player[2]
                    "You now have $"<<p1Money<<" And player[2] has "<<p2Money<<endl;
        //This is if player[1] lands on a property he already owns.
        }else if (p1Position == 23  && p1Sp23Ownd == true){
            cout<<"YOU OWN THIS PROPERTY!"<<endl;
        //if player[1] is on position [1] and dosnt have the minimum amount of money
        // and he player[1] and player[2] dont own the position
        // cout a message informing player[1] and showing his current balance
        }else if (p1Position == 23 && p1Money < 5 && p1Sp23Ownd == false && p2Sp23Ownd == false){
            cout<<"You landed on a yoki that worth [$5]\n"
                  "but you only have "<<p1Money<<endl;
            cout<<"*****************************************\n";
        //If no one owns the Property player[1] will be prompted to buy.
        //If he enters 'Y' or 'y' 
        }else if (p1Position == 23 && p1Sp23Ownd == false && p2Sp23Ownd == false && p1Money >=5){
            cout<<"You landed on a yo-ka that cost $5\n "
                   "Do you wanna buy it\n?"
                   "*****************************************\n";
            cin>>choice;
            cout<<"*****************************************\n";
        }
        //If user enters y or Y to purchase the position, p1Sp1Ownd changes to true
        // and the amount is subtracted than player[1]s new balance is posted
            if (p1Position == 23 && p1Money >= 5 && p2Sp23Ownd == false && p1Sp23Ownd == false && choice == 'Y' || choice == 'y' ){
                p1Money = p1Money-5;
                p1Sp23Ownd = true;
            cout<<"Ok you bought it for $5 you have $"<<p1Money<<" Left and "
                <<++p1Yoki<<" of 5 yoki medals\n"
                  "*****************************************\n"<<endl;
            }
        
         if (p1Position == 23 && choice != 'Y' && choice != 'y' && p2Sp23Ownd == false && p1Sp23Ownd == false && p1Money >= 5){
               cout<<"You had enough to buy Position [23] but chose not to...ok\n"
                       "*****************************************\n";
        }    
    
  /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    
 ===============================================================================
  * 
  *                         
                   * 
                   * 
                   *        END OF PLAYER[1] TURN
   *                        Start of Player[2]'s
                   * 
                   * 
  * 
 ===============================================================================
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   */ 
          
        }while(p1Turn==0);
        
        do{
        do{
        cout<<setw(120)<< "***************************************\n"<<endl;
        cout<<setw(115)<<" It is now Player 2's turn\n"<<endl;
     do{
    
        p2Roll = rand()%13,2;
                }while(p2Roll<2 || p2Roll >12 );
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
  
        
        
             
        
            p2Roll++;
            
                     if(p2Position == 2 && p2Sp2Ownd == true && p1Sp2Ownd == false)
            {
                cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
                cout<<setw(120)<< "*****************************************"<<endl;
            }
        if(p2Position == 2 && p1Sp2Ownd == true && p2Sp2Ownd==false && p2Money < 1){
            cout<<setw(120)<<"@@You landed on player[1]'s property but dont have enough to pay!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"Because of this player[2]"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"MUST GIVE UP [1] yoki to player[1]"<<endl;
          
            if(p2Sp23Ownd == true ){
            p2Sp23Ownd = false;
            p1Sp23Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
              cout<<setw(110)<<"Space 23 worth $5 was taken and given to player[21\n"
                    "to cover your debt\n"; 
           
        }else if(p2Sp22Ownd == true){
            p2Sp22Ownd = false;
            p1Sp22Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 22 worth $5 was taken and given to player[1]\n"
                  "to cover your debt\n";     
        }else if(p2Sp20Ownd == true){
            p2Sp20Ownd = false;
            p1Sp22Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 20 worth $4 was taken and given to player[1]\n"
                  "to cover your debt\n";    
        }else if(p2Sp19Ownd == true){
            p2Sp19Ownd = false;
            p1Sp19Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 19 worth $4 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp17Ownd == true){
            p2Sp17Ownd = false;
            p1Sp17Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 17 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp16Ownd == true){
            p2Sp16Ownd = false;
            p1Sp16Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 16 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp14Ownd == true){
            p2Sp14Ownd = false;
            p1Sp14Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 14 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        } else if (p2Sp13Ownd == true){
            p2Sp13Ownd = false;
            p1Sp13Ownd = true; 
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 14 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp11Ownd == true){
            p2Sp11Ownd = false;
            p1Sp11Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 11 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp10Ownd == true){
            p2Sp10Ownd = false;
            p1Sp10Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 10 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp8Ownd == true){
            p2Sp8Ownd = false;
            p1Sp8Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 8 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp7Ownd == true){
            p2Sp7Ownd = false;
            p1Sp7Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 7 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp5Ownd == true){
            p2Sp5Ownd = false;
            p1Sp5Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 5 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp4Ownd == true){
            p2Sp4Ownd = false;
            p1Sp4Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 4 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";
        }else if (p2Sp2Ownd == true){
            p2Sp2Ownd = false;
            p1Sp2Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 2 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";
        }else if (p2Sp1Ownd == true){
            p2Sp1Ownd = false;
            p1Sp1Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 1 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
        
        if(p2Position == 2 && p2Sp2Ownd == false && p2Money >= 1 && p1Sp2Ownd==true)
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
                      if(p2Position == 2  && p1Sp2Ownd==false && p2Sp2Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 2  && p1Sp2Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 2 && p1Sp2Ownd == false && p2Sp2Ownd == false){
                     p2Sp2Ownd = true;
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
            if(p2Position == 1 && p2Sp1Ownd == true)
            {
                cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
                cout<<setw(120)<< "*****************************************"<<endl;
            }
        
         if(p2Position == 1 && p1Sp1Ownd == true && p2Sp1Ownd==false && p2Money < 1){
            cout<<setw(120)<<"@@You landed on player[1]'s property but dont have enough to pay!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"Because of this player[2]"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"MUST GIVE UP [1] yoki to player[1]"<<endl;
          
            if(p2Sp23Ownd == true ){
            p2Sp23Ownd = false;
            p1Sp23Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
              cout<<setw(110)<<"Space 23 worth $5 was taken and given to player[21\n"
                    "to cover your debt\n"; 
           
        }else if(p2Sp22Ownd == true){
            p2Sp22Ownd = false;
            p1Sp22Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 22 worth $5 was taken and given to player[1]\n"
                  "to cover your debt\n";     
        }else if(p2Sp20Ownd == true){
            p2Sp20Ownd = false;
            p1Sp22Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 20 worth $4 was taken and given to player[1]\n"
                  "to cover your debt\n";    
        }else if(p2Sp19Ownd == true){
            p2Sp19Ownd = false;
            p1Sp19Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 19 worth $4 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp17Ownd == true){
            p2Sp17Ownd = false;
            p1Sp17Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 17 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp16Ownd == true){
            p2Sp16Ownd = false;
            p1Sp16Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 16 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp14Ownd == true){
            p2Sp14Ownd = false;
            p1Sp14Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 14 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        } else if (p2Sp13Ownd == true){
            p2Sp13Ownd = false;
            p1Sp13Ownd = true; 
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 14 worth $3 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp11Ownd == true){
            p2Sp11Ownd = false;
            p1Sp11Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 11 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp10Ownd == true){
            p2Sp10Ownd = false;
            p1Sp10Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 10 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp8Ownd == true){
            p2Sp8Ownd = false;
            p1Sp8Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 8 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp7Ownd == true){
            p2Sp7Ownd = false;
            p1Sp7Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 7 worth $2 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp5Ownd == true){
            p2Sp5Ownd = false;
            p1Sp5Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 5 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";  
        }else if (p2Sp4Ownd == true){
            p2Sp4Ownd = false;
            p1Sp4Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 4 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";
        }else if (p2Sp2Ownd == true){
            p2Sp2Ownd = false;
            p1Sp2Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 2 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";
        }else if (p2Sp1Ownd == true){
            p2Sp1Ownd = false;
            p1Sp1Ownd = true;
            p1Yoki = p1Yoki + 1;
            p2Yoki = p2Yoki - 1;
            cout<<setw(110)<<"Space 1 worth $1 was taken and given to player[1]\n"
                  "to cover your debt\n";
        }else{
            p1Position = 18;
            
            
            cout<<"You had no yoki to give so you must go to jail!";
        }
           }
            
            
            
            
            
            
        
        if(p2Position == 1 && p2Sp1Ownd == false && p2Money >= 1 && p1Sp1Ownd==true)
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
                      if(p2Position == 1  && p1Sp1Ownd==false && p2Sp1Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 1  && p1Sp1Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 1 && p1Sp1Ownd == false && p2Sp1Ownd == false){
                     p2Sp1Ownd = true;
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
        if(p2Position == 4 && p2Sp4Ownd == true)
            {
                cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
                cout<<setw(120)<< "*****************************************"<<endl;
            }
        if(p2Position == 4 && p1Sp4Ownd == true && p2Sp4Ownd==false && p2Money < 1){
            cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
                cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 4 && p2Sp4Ownd == false && p2Money >= 1 && p1Sp4Ownd==true)
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
                      if(p2Position == 4  && p1Sp4Ownd==false && p2Sp4Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 4  && p1Sp4Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 4 && p1Sp4Ownd == false && p2Sp4Ownd == false){
                     p2Sp4Ownd = true;
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
  *                         PLAYER 2 POSITION 5
  * 
 ===============================================================================
  */ 
            
            
                    if(p2Position == 5 && p2Sp5Ownd == true && p1Sp5Ownd == false)
            {
                cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
                cout<<setw(120)<< "*****************************************"<<endl;
            }
        if(p2Position == 5 && p1Sp5Ownd == true && p2Sp5Ownd==false && p2Money < 1){
            cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
                    "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 5 && p2Sp5Ownd == false && p2Money >= 1 && p1Sp5Ownd==true)
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
                      if(p2Position == 5  && p1Sp5Ownd==false && p2Sp5Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $1"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 1 && p2Position == 5  && p1Sp5Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 1 && p2Position == 5 && p1Sp5Ownd == false && p2Sp5Ownd == false){
                     p2Sp5Ownd = true;
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
  *                         PLAYER 2 POSITION 6
  * 
 ===============================================================================
  */ 
        
                                      if(p2Position == 6){
                                         
  
                    
                
                    cout<<setw(130)<<"AHHH! Player[2] landed on Jail {no worries JUST VISITING"<<endl;
                    cout<<setw(130)<<"player[2] gains nothing, loses nothing and ends turn."<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                    
     
                 }
           
        
                 /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 7
  * 
 ===============================================================================
  */ 
        
           
               if(p2Position == 7 && p2Sp7Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 7 && p1Sp7Ownd == true && p2Sp7Ownd==false && p2Money < 2){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
  cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 7 && p2Sp7Ownd == false && p2Money >= 2 && p1Sp7Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $2 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 2;
            p1Money = p1Money + 2;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 7  && p1Sp7Ownd==false && p2Sp7Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 7  && p1Sp7Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 7 && p1Sp7Ownd == false && p2Sp7Ownd == false){
                     p2Sp7Ownd = true;
                     p2Money = p2Money-2;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }  
                          
                       /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 8
  * 
 ===============================================================================
  */ 
                
               if(p2Position == 8 && p2Sp8Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 8 && p1Sp8Ownd == true && p2Sp8Ownd==false && p2Money < 2){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
       "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 8 && p2Sp8Ownd == false && p2Money >= 2 && p1Sp8Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $2 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 2;
            p1Money = p1Money + 2;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 8  && p1Sp8Ownd==false && p2Sp8Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 8  && p1Sp8Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 8 && p1Sp8Ownd == false && p2Sp8Ownd == false){
                     p2Sp8Ownd = true;
                     p2Money = p2Money-2;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }  
                 /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 10
  * 
 ===============================================================================
  */ 
                    if(p2Position == 10 && p2Sp10Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 10 && p1Sp10Ownd == true && p2Sp10Ownd==false && p2Money < 2){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
   cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 10 && p2Sp10Ownd == false && p2Money >= 2 && p1Sp10Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $2 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 2;
            p1Money = p1Money + 2;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 10  && p1Sp10Ownd==false && p2Sp10Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 10  && p1Sp10Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 10 && p1Sp10Ownd == false && p2Sp10Ownd == false){
                     p2Sp10Ownd = true;
                     p2Money = p2Money-2;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }  
          
/* ===============================================================================
  * 
  *                         PLAYER 2 POSITION 11
  * 
 ===============================================================================
  */ 
        
                           if(p2Position == 11 && p2Sp11Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 11 && p1Sp11Ownd == true && p2Sp11Ownd==false && p2Money < 2){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
 cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 11 && p2Sp11Ownd == false && p2Money >= 2 && p1Sp11Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $2 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 2;
            p1Money = p1Money + 2;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 11  && p1Sp11Ownd==false && p2Sp11Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $2"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 2 && p2Position == 11  && p1Sp11Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 2 && p2Position == 11 && p1Sp11Ownd == false && p2Sp11Ownd == false){
                     p2Sp11Ownd = true;
                     p2Money = p2Money-2;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $2"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      }  
                             /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 12
  * 
 ===============================================================================
  */ 
                                    if(p2Position == 12){
                     
                    cout<<setw(120)<<"oHHH you landed on the ""Just Parking spot"<<endl;
                    cout<<setw(125)<<"player[2] gains nothing, loses nothing and ends turn."<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                    
     
                 }
        //combine???
                      /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 13
  * 
 ===============================================================================
  */ 
                
                          if(p2Position == 13 && p2Sp13Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 13 && p1Sp13Ownd == true && p2Sp13Ownd==false && p2Money < 3){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
   cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 13 && p2Sp13Ownd == false && p2Money >= 3 && p1Sp13Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $3 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 3;
            p1Money = p1Money + 3;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 13  && p1Sp13Ownd==false && p2Sp13Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 3 && p2Position == 13  && p1Sp13Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 3 && p2Position == 13 && p1Sp13Ownd == false && p2Sp13Ownd == false){
                     p2Sp13Ownd = true;
                     p2Money = p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
           
                      } 
                             /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 14
  * 
 ===============================================================================
  */ 
                                if(p2Position == 14 && p2Sp14Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 14 && p1Sp14Ownd == true && p2Sp14Ownd==false && p2Money < 3){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
   cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 14 && p2Sp14Ownd == false && p2Money >= 3 && p1Sp14Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $3 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 3;
            p1Money = p1Money + 3;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 14  && p1Sp14Ownd==false && p2Sp14Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 3 && p2Position == 14  && p1Sp14Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 3 && p2Position == 14 && p1Sp14Ownd == false && p2Sp14Ownd == false){
                     p2Sp14Ownd = true;
                     p2Money = p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
                      }
           
                                 /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 16
  * 
 ===============================================================================
  */ 
                 if(p2Position == 16 && p2Sp16Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 16 && p1Sp16Ownd == true && p2Sp16Ownd==false && p2Money < 3){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
       "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 16 && p2Sp16Ownd == false && p2Money >= 3 && p1Sp16Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $3 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 3;
            p1Money = p1Money + 3;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 16  && p1Sp16Ownd==false && p2Sp16Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 3 && p2Position == 16  && p1Sp16Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 3 && p2Position == 16 && p1Sp16Ownd == false && p2Sp16Ownd == false){
                     p2Sp16Ownd = true;
                     p2Money = p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
                      }
                              /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 17
  * 
 ===============================================================================
  */ 
        if(p2Position == 17 && p2Sp17Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 17 && p1Sp17Ownd == true && p2Sp17Ownd==false && p2Money < 3){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
    cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 17 && p2Sp17Ownd == false && p2Money >= 3 && p1Sp17Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $3 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 3;
            p1Money = p1Money + 3;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 17  && p1Sp17Ownd==false && p2Sp17Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $3"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 3 && p2Position == 17  && p1Sp17Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 3 && p2Position == 17 && p1Sp17Ownd == false && p2Sp17Ownd == false){
                     p2Sp17Ownd = true;
                     p2Money = p2Money-3;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $3"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
                      }
            
                       /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 18
  * 
 ===============================================================================
  */ 
        if(p2Position == 18 && turnskip != 2 && p2Money < 1)
        {
            ++turnskip;
         
        
            cout<<setw(110)<<"REAL JAIL!!! MUST MISS A TURN"<<endl;
           
            
        }
        
        if(p2Position == 18 && turnskip == 2)
        {
           
          p2Position = 6;
            turnskip = turnskip - 2;
        }
        if(p2Position == 18 && p2Money >= 1)
        {
            cout<<setw(115)<<"Player[2] landed IN JAIL!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(115)<<"Player[2] payed $1 to get out of jail"<<endl;
            cout<<setw(120)<<        "*****************************************"<<endl;
            cout<<setw(110)<<"Player[2] now has $"<<p2Money - 1<<" left"<<endl;
            
                    p2Position = 6;
            p2Money = p2Money - 1;
        }
        
                         /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 19
  * 
 ===============================================================================
  */ 
         if(p2Position == 19 && p2Sp19Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 19 && p1Sp19Ownd == true && p2Sp19Ownd==false && p2Money < 4){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
   cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 19 && p2Sp19Ownd == false && p2Money >= 4 && p1Sp19Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $4 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 4;
            p1Money = p1Money + 4;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 19  && p1Sp19Ownd==false && p2Sp19Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $4"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 4 && p2Position == 19  && p1Sp19Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 4 && p2Position == 19 && p1Sp19Ownd == false && p2Sp19Ownd == false){
                     p2Sp19Ownd = 1;
                     p2Money = p2Money-4;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $4"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
                      }
            
                         /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 20
  * 
 ===============================================================================
  */ 
             if(p2Position == 20 && p2Sp20Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 20 && p1Sp20Ownd == true && p2Sp20Ownd==false && p2Money < 4){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
       "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 20 && p2Sp20Ownd == false && p2Money >= 4 && p1Sp20Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $4 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 4;
            p1Money = p1Money + 4;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 20  && p1Sp20Ownd==false && p2Sp20Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $4"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 4 && p2Position == 20  && p1Sp20Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 4 && p2Position == 20 && p1Sp20Ownd == false && p2Sp20Ownd == false){
                     p2Sp20Ownd = true;
                     p2Money = p2Money-4;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $4"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
                      }
        
        
                      /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 22
  * 
 ===============================================================================
  */ 
        
        
                
             if(p2Position == 22 && p2Sp22Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 22 && p1Sp22Ownd == true && p2Sp22Ownd==false && p2Money < 5){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!"<<endl;
   cout<<setw(120)<<"Because of this player[2] loses [1] yoki and player[1] gains [1] yoki"<<endl;
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 22 && p2Sp22Ownd == false && p2Money >= 5 && p1Sp22Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $5 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 5;
            p1Money = p1Money + 5;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 22  && p1Sp22Ownd==false && p2Sp22Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $5"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 5 && p2Position == 22  && p1Sp22Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 5 && p2Position == 22 && p1Sp22Ownd == false && p2Sp22Ownd == false){
                     p2Sp22Ownd = true;
                     p2Money = p2Money-5;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $5"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
                      }
        
        
                         /*     
 ===============================================================================
  * 
  *                         PLAYER 2 POSITION 23
  * 
 ===============================================================================
  */ 
        
                    if(p2Position == 23 && p2Sp23Ownd == true)
            {
           cout<<setw(120)<< "*****************************************"<<endl;
                
                cout<<setw(120)<<"You own this property!"<<endl;
             cout<<setw(120)<< "*****************************************"<<endl;
            }
     if(p2Position == 23 && p1Sp23Ownd == true && p2Sp23Ownd==false && p2Money < 5){
cout<<setw(120)<<"You landed on player[1]'s property but dont have enough to pay!\n"
       "Because of this player[2] loses [1] yoki and player[1] gains [1] yoki";
            p2Yoki = p2Yoki - 1;
            p1Yoki = p1Yoki + 1;
        }
        
        if(p2Position == 23 && p2Sp23Ownd == false && p2Money >= 5 && p1Sp23Ownd==true)
        {
            cout<<setw(120)<<"YOU LANDED ON A YOKI SOMEONE ELS OWNDS!!"<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            cout<<setw(120)<<"You have to pay $5 "<<endl;
            cout<<setw(120)<< "*****************************************"<<endl;
            p2Money = p2Money - 5;
            p1Money = p1Money + 5;
            cout<<setw(120)<<"One dollar was given to player[1], he now has "
                    <<p1Money<<" And you have "<<p2Money<<endl;
        }
                      if(p2Position == 23  && p1Sp23Ownd==false && p2Sp23Ownd==false){
         cout<<setw(120)<<"Player[2] landed on a yo-ka that cost $5"<<endl;
      cout<<setw(120)<<        "*****************************************"<<endl;
                          
      
      if(p2Money < 5 && p2Position == 23  && p1Sp23Ownd==false){
          
      cout<<setw(120)<<"Player[2] did not have enough to buy this yo-ka"<<endl;
                      }
                               
                 if(p2Money >= 5 && p2Position == 23 && p1Sp23Ownd == false && p2Sp23Ownd == false){
                     p2Sp23Ownd = true;
                     p2Money = p2Money-5;
                    
                
                    cout<<setw(120)<<"Player[2] bought the Yo-ka for $5"<<endl;
                    cout<<setw(120)<<"*****************************************"<<endl;
                     cout<<setw(100)<<"Player[2] now has $"<<p2Money<<" Left and "
                    <<++p2Yoki<<" of 5 yokis"<<endl;
                      cout<<setw(120)<< "*****************************************"<<endl;
                 }
                      }
                                         /*     
 ===============================================================================
  * 
  *                         END OF PLAYER 2'S TURN
  * 
 ===============================================================================
  */  cout<<"===================================================================================================================================================================================================================\n\n";
        cout<<"\n"<<setw(40)<<"Your yo-kai: ["<<p1Yoki<<"] Your money: ["<<p1Money<<"] Current Position ["
                <<p1Position<<"]"<<setw(28)<<"ROUND ["<<count<<"]"<<setw(40)<<
                "Player 2s yo-kai: ["<<p2Yoki<<"] Player 2s money: "<<p2Money<<
                " Player 2's position ["<<p2Position<<"]"<<setw(38)<<endl;
        cout<<"===================================================================================================================================================================================================================";
       
        
     
        if(Jdebt != 0){
            Jdebt = Jdebt + 1;
        }
        if(Jdebt >= 3){
            Jdebt = 0;
            Jailasst = 0;
            p1Position = 6;
        }
        
          
        
                
        }while (Jdebt != 0);  
                    }while(p2Roll==0);
               
    }while(p1Yoki != 10 && p2Yoki != 10);
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
