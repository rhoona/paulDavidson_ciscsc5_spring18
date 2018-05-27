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
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions


//array of all positions on board with corresponding amount

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
    int positionsValue[24] = {2,1,1,0,1,1,0,2,2,0,2,2,0,3,3,0,3,3,0,4,4,0,5,5};
    //Positions to be used as booleans (testing) 1 is propertys buyable
    // default 0 are unbuyable spots. If bought prop changes to 0
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
    }
    
    
    cout<<"Your position is "<<p1Position<<endl;
    cout<<"Money "<<p1Money<<endl;
    
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
     p2Position = p2Position + roll;
     
       if(p2Position >= 24){
        p2Position = p2Position - 24;
     //pay the player 2 dollars for circling the map(when resetting by -24)
        cout<<"\t\tp2[computer] circled the map and recieved $2 from the bank"<<endl;
    p2Money = p2Money + positionsValue[0];
    }
     cout<<"\t\tp2[computer] position is "<<p2Position<<endl;
    cout<<"\t\tp2[computer] Money is "<<p2Money;
    
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
            input = 5;
    return input;
    }
    
}