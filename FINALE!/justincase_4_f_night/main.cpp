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
int test(int []);
int computerRoll();
int ROLL();
int BUY(int[],bool,int);
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
    //Positions to be used as booleans (testing) 1 is propertys buyable
    // default 0 are unbuyable spots. If bought prop changes to 0
    //IF P1 BUYS/OWNDS ifOpen POSITION = 3, IF P2 BUYS/OWNDS POSITION ifOpen position = 4
    int ifOpen[24] = {0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1};
    int p1Money = 3,p2Money = 3;
    int p1Position = 0,p2Position = 0;
    int p1Yoki = 0,p2Yoki = 0;
    int roll = 0;
    int p1Buy = 0, p2Buy = 0;
    bool notOwnd = true,p1Turn = true, p2Turn = true;
    bool pay = false;
    int i = 0; //test var
    
    //beginign of do while loop till someone has 5 yoki (wins)
    do{
//p1 turn is true so he rolls, after his turn = false and p2 turn is true;
    if(p1Turn){
            roll = ROLL();
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
    if(ifOpen[p1Position] == 1 && p1Money >= positionsValue[p1Position])
    {
        p1Buy = BUY(positionsValue,p1Turn,p1Position);
        
        //what happends if he buys it, the value goes from 1 to 3 for p1
        if(p1Buy == 3)
        {
            //logic for changing the array element to 3 for p1 and subtracting money
            
            ifOpen[p1Position] = 3;
           
            cout<<"p1 bought position "<<p1Position<<"'s yoki for "
                    <<positionsValue[p1Position]<<endl;
            p1Money = p1Money - positionsValue[p1Position];
            p1Yoki = p1Yoki + 1;
        }
        
    }
    
    
    cout<<"Your position is "<<p1Position<<"\t"<<
  "Money "<<p1Money<<"\t\t"<<
    "Your Yoki "<<p1Yoki<<"\n";
    
        p1Turn = false;
        p2Turn = true;
    
    }
    //decoration stars
    cout<<endl;
        rowStar();

        
    //same thing for p1 but for p2!
    //roll function wont work with p2
    if(p2Turn){
         roll = computerRoll();
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
     if(ifOpen[p2Position] == 1 && p2Money >= positionsValue[p2Position])
     {
         cout<<"P2 landed on a Yoki worth $"<<positionsValue[p2Position]<<endl;
         cout<<"P2 bought the Yoki position on space #"<<p2Position<<endl;
         ifOpen[p2Position] = 4;
         p2Money = p2Money - positionsValue[p2Position];
         p2Yoki = p2Yoki + 1;
     
     //logic for if p2 lands on a spot owned by p1 and has enough money
     // he pays p1 the money and loses that amount
     } else if (ifOpen[p2Position] == 3 && p2Money >= positionsValue[p2Position]){
         cout<<"P2[computer] landed on a spot owned by P1 worth "<<positionsValue[p2Position]
                 <<" P2[computer] has enough money thus will pay p1 the value of the positon"<<endl;
         p2Money = p2Money - positionsValue[p2Position];
         p1Money = p1Money + positionsValue[p2Position];
         cout<<"p1 Recived "<<positionsValue[p2Position]<<endl;
             
         
     //if player 2 lands on a spot owned by player 1 and cannot pay must
     //forfeit a yoki
     }else if (ifOpen[p2Position] == 3 && p2Money < positionsValue[p2Position] && p2Yoki >= 1){
         
         cout<<"OH NO! P2[comptuer] landed on your yoki but cannot pay!"
                 "you are awarded one of his yoki!"<<endl;
         //function to detmine highest value yoki ownds to give to p1
         testing = test(ifOpen);
         cout<<testing<<" HEEEREE??"<<endl;
         cout<<"Giving p1 yoki at position "<<testing<<" Worth "<< positionsValue[testing]<<endl;
         ifOpen[testing] = 3;
         p2Yoki = p2Yoki - 1;
         p1Yoki = p1Yoki + 1;
     }
     
     
     cout<<"p2[computer] position is "<<p2Position<<
    "\tp2[computer] Money is "<<p2Money<<"\t\tP2 has "<<p2Yoki<<" Yoki! "<<endl;
    
        p2Turn = false;
        p1Turn = true;
    
    }
        cout<<"\n"<<endl;
        rowStar();
    
        
        
        //end of do while loop till soeone has 5 yoki (winner)
    }while(p1Yoki < 5 || p2Yoki < 5);
        
  
    
    



    
   
    
   
    
    return 0;
}
int ROLL()
{
    int ROLL = 0;
    char input = 0;
    int i = 0;
    
    cout<<"Press R to roll\n";
        rowStar();
    cin>>input;

    //ask user to input r to roll.
    if(input == 'R' || input == 'r')
    //while loop to do rand 5 times than output the number
    while( i < 5){
    //rolls only between 2-12 (maxium and minimum for two dice
    ROLL = rand()%11+2;
    i++;
    }
     return ROLL;
    }

int computerRoll()
{
    
    //roll for the computer as human roll ask for input
    int ROLL = 0;
    int i = 0;
    
    while( i < 5){
    //rolls only between 2-12 (maxium and minimum for two dice
    ROLL = rand()%11+2;
    i++;
    }
     return ROLL;
    
   }



//function to buy (look at line 62-67
int BUY(int positionsValue[],  bool p1Turn, int position)
{
    char input = 0;
    cout<<"You landed on a Yoki Position worth "<<positionsValue[position]<<endl;
    cout<<"Do you wish to buy it?";
    cin>>input;
    if(input == 'y' || input == 'Y')
    {
        input = 3;
        return input;
    }else {
        if(input != 'y' && input != 'Y')
            input = 1;
    return input;
    }
    
}
//WORKS!! SEND P2[COMPUTER] HERE TO GIVE UP HIGHEST YOKI TO P1!
int test(int ifOpen[])
{
    int SIZE = 24;
    int count = 24;
    
    count = ifOpen[SIZE];
    while(ifOpen[SIZE] != 4)
        SIZE--;
    if(ifOpen[SIZE] == 4)
       // cout<<"DID IT!! "<<SIZE<<endl;
    return SIZE;
    
    /*
    for(int SIZE = 24; SIZE > 0; SIZE-- )
    {
        if(ifOpen[SIZE] == 3)
               cout<<SIZE<<"WTTFFF"<<endl;
    }
*/
    
}