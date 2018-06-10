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
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

char ROLL(char);
int MOVE(int, int);
int POSITION(int, int);
//function for star seperators(cosemetic)
void rowStar()
{
cout<<"*****************************************\n"<<endl;
}
//Execution Begins Here

int main(int argc, char** argv) {
  //seed random  
 srand(static_cast<unsigned int>(time(0)));   
 /*
 variables
  */
char test;
int player1Roll=0;
int player1Counter=0,player1Position=0;
    
/*
 START
 */ 
//test counter!
//remove soon
for(int a=0;a<5;a++){ //remove this soon
    
player1Roll=ROLL(player1Roll);


//hopefuly this will work to keep track of position;
player1Position = POSITION(player1Position,player1Roll);
   
}
cout<<"\n"<<"Is it adding them? "<<player1Position;

  








 return 0;
}
//function for rolling the dice! or getting the instructions!
char ROLL(char)
{
    int RRG;
    char roll;
    //ask user to roll, checks if input matches command
    
    do{
        cout<<"Press R to roll the Dice!"<<endl;
        rowStar();
        cin>>roll;
        rowStar();
        if(roll == 'r'||roll=='R')
        
            RRG = rand()%100,1;
             cout<<"Player 1 rolled ";
            cout<<static_cast<int>(RRG);
        
        if(roll == 'q'||roll=='Q')
        {
            cout<<"This is where instructions will go!\n";
        }
    }while (roll != 'r'||roll != 'R'||roll != 'q'||roll != 'Q');
  
    }
    

int POSITION(int position, int roll)
{
    int playerPosition;
    
    playerPosition=position+roll;
    if(playerPosition>25){
        playerPosition - 25;
    }
    return playerPosition;
    
}
  
    

//second function

