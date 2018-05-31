/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions


//array of all positions on board with corresponding amount
int test(int [],int, int);
int turnSkip(int[],int&,int&,bool,bool,int,int);
int computerRoll(int);
int cantPay(int [],int[],int,int&,int&,int,int,int,int);
int ROLL(int);
int BUY(int[],int[],bool,bool,int,int,int&,int&,int&,int&,int,int);
int jail(bool, bool, int&, int&);
int mustPay( int *,int&,int&,int,int,bool,bool,int,int );
int cards(int[],int[],int,int,int&,int&, int,int,int&,int&);

void rowStar()
{
cout<<"*****************************************\n"<<endl;
}
int main(int argc, char** argv) {
    //seed srand ("ONCE AT THE TOP")
    srand(static_cast<unsigned int>(time(0)));
    //test to figure out what im going to to do for swapping yoki value
    int SIZE =24;
    int testing;
    int MAXSIZE = 7;
    int p1YokiArr[MAXSIZE];
    int positionsValue[SIZE] = {2,1,1,0,1,1,0,2,2,0,2,2,0,3,3,0,3,3,0,4,4,0,5,5};
     int *pV = positionsValue;
     
   

    //Positions to be used as booleans (testing) 1 is propertys buyable
    // default 0 are unbuyable spots. If bought prop changes to 0
    //IF P1 BUYS/OWNDS ifOpen POSITION = 3, IF P2 BUYS/OWNDS POSITION ifOpen position = 4
    int ifOpen[24] = {0,1,1,8,1,1,0,3,3,8,1,1,0,1,1,8,1,1,0,1,1,8,1,1};
    int *IO = ifOpen;
    
    int p1Money = -300,p2Money = 300;
    int p1Position = 0,p2Position = 0;
    int p1Yoki = 2,p2Yoki = 0;
    int roll = 0;
    int p1Buy = 0, p2Buy = 0;
    bool notOwnd = true,p1Turn = true, p2Turn = true;
    bool pay = false;
    int p1Skip = 0, p2Skip = 0;
    int i = 0; //test var
    
    //beginign of do while loop till someone has 5 yoki (wins)
    do{
        if(p1Skip != 0){
        p2Turn = true;
        p1Turn = false;
    }else if (p1Skip == 0)
        p2Turn = false;
        p1Turn = true;
    
//p1 turn is true so he rolls, after his turn = false and p2 turn is true;
    if(p1Turn == true && p1Skip == 0){
            roll = ROLL(p1Skip);
    cout<<"You rolled a "<<roll<<endl;
    
    //position is current position + roll.
    p1Position = p1Position + roll;
    //if position passes 24, subtract 24 from position (resetting position)
    if(p1Position >= 24){
        p1Position = p1Position - 24;
     //pay the player 2 dollars for circling the map(when resetting by -24)
        cout<<"p1 circled the map and recieved $2 from the bank"<<endl;
    p1Money = p1Money + positionsValue[0];
    }
    
    //TRICKY USING THE ARRAYS FOR VALUE AND BOOL IS AWSOMRE!!!!!!! DONT FORGET
    if(ifOpen[p1Position] == 1 && p1Money >= positionsValue[p1Position] && p1Skip == 0 && p1Turn)
    {
         BUY(positionsValue,ifOpen,p1Turn,p2Turn,p2Position,p1Position,p1Money,p2Money,p1Yoki,p2Yoki,p1Skip,p2Skip);
        
        //what happends if he buys it, the value goes from 1 to 3 for p1
        //this is a return from the buy function
       
        
        //logic for if p1 lands on a spot owned by p2 and has enough $$$$
    } else if (ifOpen[p1Position] == 4 && p1Money >= positionsValue[p1Position] && p1Skip == 0)
    {
        mustPay(pV,p1Money,p2Money,p1Position,p2Position,p1Turn,p2Turn,p1Skip,p2Skip);
        
    }else if(ifOpen[p1Position] == 4 && p1Money < positionsValue[p1Position] && p1Yoki >= 1)
    {
        testing = test(ifOpen,p1Turn,p2Turn);
        cantPay(ifOpen,positionsValue,testing,p1Yoki,p2Yoki,p1Turn,p2Turn,p1Skip,p2Skip);

        
    }else if (p1Turn && ifOpen[p1Position] == 4 && p1Money < positionsValue[p1Position] && p1Yoki == 0 && p1Skip == 0 )
    {
           turnSkip(positionsValue,p1Skip,p2Skip,p1Turn,p2Turn,p1Position,p2Position);
           
           //cards!!!
     }else if(p1Skip == 0 && ifOpen[p1Position] == 8 && p1Turn)
     {
         
      cards(ifOpen,positionsValue,p1Turn,p2Turn,p1Yoki,p2Yoki,p1Position,p2Position,p1Skip,p2Skip);
     
   
     }

    
    cout<<"Your position is "<<p1Position<<"\t"<<
  "Money "<<p1Money<<"\t\t"<<
    "Your Yoki "<<p1Yoki<<"\n";
    
 /*
  * 
  * 
                   !!!!!!!END OF PLAYER 1'S TURN!!!!!!!
  * 
  * 
  
  */   
    if(p2Skip != 0)
    {
        p1Turn = true;
        p2Turn = false;
    }else if (p2Skip == 0)
    
        p1Turn = false;
        p2Turn = true;
    
    }
    //decoration stars
    cout<<endl;
        rowStar();

        
    //same thing for p1 but for p2!
    //roll function wont work with p2
    if(p2Turn && p2Skip == 0){
         roll = computerRoll( p2Skip);
    cout<<"\t\tPlayer2[computer] rolled a ["<<roll<<"]"<<endl;
   
    //updates p2[computer] Position
     p2Position = (p2Position + roll);
     
       if(p2Position >= 24){
        p2Position = p2Position - 24;
     //pay the player 2 dollars for circling the map(when resetting by -24)
        cout<<"\t\tp2[computer] circled the map and recieved $2 from the bank"<<endl;
    p2Money = p2Money + positionsValue[0];
       }
     
     /////////// logic for if player 2 lands on a open spot he buys, value set to 2
     if(ifOpen[p2Position] == 1 && p2Money >= positionsValue[p2Position] && p2Skip == 0 && p2Turn)
     {
               BUY(positionsValue,ifOpen,p1Turn,p2Turn,p2Position,p1Position,p1Money,p2Money,p1Yoki,p2Yoki,p1Skip,p2Skip);

     
     //logic for if p2 lands on a spot owned by p1 and has enough money
     // he pays p1 the money and loses that amount
     } else if (p2Turn && ifOpen[p2Position] == 3 && p2Money >= positionsValue[p2Position] && p2Skip == 0){
        
         mustPay(pV,p1Money,p2Money,p1Position,p2Position,p1Turn,p2Turn,p1Skip,p2Skip);
             
         
     //if player 2 lands on a spot owned by player 1 and cannot pay must
     //forfeit a yoki
     }else if (p2Turn && ifOpen[p2Position] == 3 && p2Money < positionsValue[p2Position] && p2Yoki >= 1 && p2Skip == 0){
         
       
         testing = test(ifOpen,p1Turn,p2Turn);
         cantPay(ifOpen,positionsValue,testing,p1Yoki,p2Yoki,p1Turn,p2Turn,p1Skip,p2Skip);
         
      
         
         //to skip a turn if no yoki or money
     }else if(p2Turn && ifOpen[p2Position] == 3 && p2Money < positionsValue[p2Position] && p2Yoki == 0 && p2Skip == 0)
     {
         
         turnSkip(positionsValue,p1Skip,p2Skip,p1Turn,p2Turn,p1Position,p2Position);
         
         
         
         
       //if p2 lands on a open position but does not have enough money to buy it
     }else if(ifOpen[p2Position] == 1 && p2Money < positionsValue[p2Position])
     {
         cout<<"P2[COMPUTER] landed on a free yoki worth "<<positionsValue[p2Position];
         cout<<" but did not have enough to buy it!"<<endl;
         //WORKING JAIL FUNCTION!!! WILL WORK FOR P1 AND P2!!
     } else if(p2Turn && p2Position == 18 && p2Skip == 0)
    {
        p2Skip = jail(p1Turn,p2Turn,p1Position,p2Position);
        
    }else if (p2Skip == 0 && ifOpen[p2Position] == 8 && p2Turn)
       {
         
      cards(ifOpen,positionsValue,p1Turn,p2Turn,p1Yoki,p2Yoki,p1Position,p2Position,p1Skip,p2Skip);
    }
     
     
     
     cout<<"p2[computer] position is "<<p2Position<<
    "\tp2[computer] Money is "<<p2Money<<"\t\tP2 has "<<p2Yoki<<" Yoki! "<<endl;
    
        p2Turn = false;
        p1Turn = true;
    
    }
        cout<<"\n"<<endl;
        rowStar();
        
        //to skip a turn p2Skip is = 2, 2 will be -1 twice so p2loses a turn
        if(p2Skip != 0)
       {
           p2Skip--;
       }
       //testing skip for p1 also
        if(p1Skip != 0)
        {
            p1Skip--;
        }
        
        
        //end of do while loop till soeone has 5 yoki (winner)
    }while(p1Yoki < 20 && p2Yoki < 20);
   
   return 0;

    
    
/*
 *
 *                      Beginning of Functions!
 * 
 */
}
int ROLL(int skip)
{
   int ROLL = 0;
    char input = 0;
    int i = 0;
    if(skip == 0)
    {
   
    
    cout<<"Press R to roll\n";
        rowStar();
    cin>>input;

    //ask user to input r to roll.
    if(input == 'R' || input == 'r')
    //while loop to do rand 5 times than output the number
    while( i < 5 && skip == 0){
    //rolls only between 2-12 (maxium and minimum for two dice
    ROLL = rand()%11+2;
    i++;
    }
    
     return ROLL;
    }
}
int computerRoll(int Skip)
{
    
    //roll for the computer as human roll ask for input
    int ROLL = 0;
    int i = 0;
    if(Skip == 0){
    while( i < 5){
    //rolls only between 2-12 (maxium and minimum for two dice
    ROLL = rand()%11+2;
    i++;
    }
     return ROLL;
    
   }
}


//function to buy (look at line 62-67

//switching buy function for p1 and p2 to this function
int BUY(int positionsValue[],int ifOpen[],  bool p1Turn,bool p2Turn,int p2position, int p1position,int &p1Money, int &p2Money, int &p1Yoki,int &p2Yoki,int p1Skip,int p2Skip)
{
    if(p1Turn == true  && p1Skip == 0)
    {
        
    char input = 0;
    cout<<"You landed on a Yoki Position worth "<<positionsValue[p1position]<<endl;
    cout<<"Do you wish to buy it?";
    cin>>input;
    if(input == 'y' || input == 'Y')
    {
        ifOpen[p1position] = 3;
                p1Money = p1Money - positionsValue[p1position];
        p1Yoki = p1Yoki + 1;
        cout<<"p1 bought position "<<p1position<<"'s yoki for "<<positionsValue[p1position]<<endl;


    }else if(input != 'y' && input != 'Y')
     return 0;
    
    //mayube trouble

    } else if (p2Turn == true && p2Skip == 0)
{
    
    cout<<"P2 landed on a Yoki worth $"<<positionsValue[p2position]<<endl;
         cout<<"P2 bought the Yoki position on space #"<<p2position<<endl;
         //LOGIC FOR CHANGING THE ARRAY ELEMENT TO 4 TO SHOW P2 OWNERSHIP
         ifOpen[p2position] = 4;
         p2Money = p2Money - positionsValue[p2position];
         p2Yoki = p2Yoki + 1;
    
    
}
    return 0;
    

    
}
//WORKS!! SEND P2[COMPUTER] HERE TO GIVE UP HIGHEST YOKI TO P1!
int test(int ifOpen[],int p1Turn,int p2Turn)
{
    int SIZE = 24;
    int count = 24;
    
    if(p2Turn)
    {
   count = ifOpen[SIZE];
    while(ifOpen[SIZE] != 4)
        SIZE--;
    if(ifOpen[SIZE] == 4)
    {
         return SIZE;
      }
        }else if(p1Turn)
        {
    count = ifOpen[SIZE];
    while(ifOpen[SIZE] != 3)
        SIZE--;
    if(ifOpen[SIZE] == 3)
    {
        return SIZE;
    }
}

    
}
int jail(bool p1, bool p2, int & p1Pos, int & p2Pos)
{
    if(p2)
    {
        cout<<"P2[computer] Landed on position 18! AKA ""GO TO JAIL\n";
        cout<<"P2[COMPUTER] Is moved to position #6 and loses a turn!"<<endl;
        p2Pos = 6;
        
    
    }else if(p1)
    {
        cout<<"OH NO! p1 AKA YOU! landed on ""GO TO JAIL! \n";
        cout<<"You lose 1 turn and are moved to position #6!";
    }
    return 2;
    }

int mustPay(int *posValue, int & p1Money,int & p2Money,int p1Pos, int p2Pos, bool p1Turn, bool p2Turn,int p1Skip,int p2Skip)
{
    //WORKING OMG!! SEE line 97-100
    cout<<posValue[p1Pos]<<" pos value"<<endl;
    if(p1Turn == true && p1Skip == 0)
    {
        
        cout<<"ahhh SNAPS! you landed on a position owned by P2[computer]!\n";
        cout<<"You must pay P2[computer] $"<<posValue[p1Pos]<<endl;
        p1Money = p1Money - posValue[p1Pos];
        p2Money = p2Money + posValue[p1Pos];
        //player 2 function money swap if landing on p1 position
        //see lines 159-161
    }else if(p2Turn == true && p2Skip == 0)
     {
         cout<<"P2[computer] landed on a spot owned by P1 worth "<<posValue[p2Pos]
         <<" P2[computer] has enough money thus will pay p1 the value of the positon"<<endl;
         p2Money = p2Money - posValue[p2Pos];
         p1Money = p1Money + posValue[p2Pos];
         cout<<"p1 Recived "<<posValue[p2Pos]<<endl;
            
        }
     }
int cantPay(int ifOpen[],int posValue[],int testing,int& p1Yoki,int& p2Yoki,int p1Turn,int p2Turn,int p1Skip,int p2Skip)
{
    if(p2Turn && p2Skip == 0)
    {
        cout<<"OH NO! P2[comptuer] landed on your yoki but cannot pay!"
              "you are awarded one of his yoki!"<<endl;
        
         cout<<testing<<" HEEEREE??"<<endl;
         cout<<"Giving p1 yoki at position "<<testing<<" Worth "<< posValue[testing]<<endl;
         //changing ownership
         ifOpen[testing] = 3;
         p2Yoki = p2Yoki - 1;
         p1Yoki = p1Yoki + 1;
         
    }else if (p1Turn && p1Skip == 0 )
    {
        cout<<"YOU LANDED ON A YOKI OWNED BY P2[COMPUTER] AND DONT HAVE ENOUGH $$ TO PAY HIM =(\n";
        cout<<"So instead hes going to take your most vauable YOKI!";
        cout<<"You give P2[COMPUTER] your yoki at position "<<testing<<" worth "<<posValue[testing]<<endl;
        
        ifOpen[testing] = 4;
         p2Yoki = p2Yoki + 1;
         p1Yoki = p1Yoki - 1;
        
        
    }
    return 0;
    
    
}
int turnSkip(int posValue[],int& p1Skip,int& p2Skip,bool p1,bool p2,int p1Pos,int p2Pos)
{
    if(p2 && p2Skip == 0)
    {
         cout<<"P2[computer] landed on a position owned by P1. P2[computer] dosnt have enough money or yoki. So P2[computer] loses a turn!"<<endl;
         p2Skip = 2;
        
   
    
  
    }else if(p1 && p1Skip == 0)
    {
        cout<<"you landed on P2 YOKI on position "<<p1Pos<<" and dont have the "<<posValue[p1Pos]<<endl; 
        cout<<" or any yoki to give!!!!! So instead you must miss a turn!"<<endl;
            
                        p1Skip = 2;
    
    }

    return 0;
    
}
int cards(int ifOpen[],int posVal[],int p1,int p2,int& p1Yoki,int& p2Yoki, int p1Pos,int p2Pos,int& p1Skip,int& p2Skip)
{
    //rand 1-24 for cards
    //int card = rand()%24+1;
    int card = 1;
    int SIZE = 24;
    int count = 0;
    int size = 0;
    
    if(p1 && card == 1 && p1Yoki >= 1)
    {
        while(ifOpen[size] != 3)
            size++;
    
            if(p1 && ifOpen[size] == 3);
            {
            
                cout<<"P1 drew the WORST CARD! P1 must forfeit his lowest value yoki to P2[COMPUTER]!\n";
                cout<<"You lost the yoki at position "<<size<<endl;
                ifOpen[size] = 4;
                p1Yoki = p1Yoki - 1;
                p2Yoki = p2Yoki + 1;
            }
            
        
    }else if(p1 && card == 1 && p1Yoki < 1 && p1Skip == 0)
    {
     cout<<"You pulled the BAD card and had to give up a yoki but didnt have any yoki so you lose a turn!"<<endl;
     p1Skip = 2;
     
     
    
    }else if(p2 && card == 1 && p2Yoki >= 1)
    {
        while(ifOpen[size] != 4)
            size++;
    
            if(p2 && ifOpen[size] == 4);
            {
            
                cout<<"teeeeeeesttttt\n";
                cout<<"p2p2pp2p2p2pp2 You lost the yoki at position "<<size<<endl;
                ifOpen[size] = 3;
                p1Yoki = p1Yoki + 1;
                p2Yoki = p2Yoki - 1;
            }
            
        
    }else if(p2 && card == 1 && p2Yoki < 1)
    {
     cout<<"teeeeeeeesssssssst  p2p2p2p2 didnt have any yoki so loses turn!"<<endl;
     p2Skip = 2;
     
     }
    
  
}