 /*
* File:   main.cpp
 * Author: Paul Davidson
 * Completely finished  on 6/7/18 1:47 pm! :D
 * Purpose:  to be an awsome learning game and to get good grades!
 */

//System Libraries
#include <iostream>
#include <string> //added
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip> //for precision
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions


//array of all positions on board with corresponding amount
int test(int [],int, int);
int trnSK(int[],int&,int&,bool,bool,int,int);
int cantPay(int [],int[],int,int&,int&,int,int,int,int);
int ROLL(int,int,int,int,string);
int BUY(int[],int[],bool,bool,int,int,int&,int&,int&,int&,int,int);
int jail(bool, bool, int&, int&,int&,int&,int&,int&);
int mustPay( int *,int&,int&,int,int,bool,bool,int,int );
//cards see line 130 @@ 229
int cards(int[],int[],int,int,int&,int&, int,int,int&,int&,int&,int&,int&,int&);
int card1(int[],int[],int,int,int&,int&,int,int,int&,int&);
int card2(int[],int[],int,int,int&,int&,int,int,int&,int&);
int card3(int[],int[],int,int,int&,int&,int,int,int&,int&);
int card4(int[],int[],int,int,int&,int&,int,int,int&,int&,int&,int&);
int card5(int[],int[],int,int,int&,int&,int,int,int&,int&,int&,int&);
void rowStar(string); //function for stars(pure cosmetic/seperator)

int main(int argc, char** argv) {
    //seed srand ("ONCE AT THE TOP")
    srand(static_cast<unsigned int>(time(0)));
    //test to figure out what im going to to do for swapping yoki value
    const int SIZE =24;
    int testing;
    int pozVal[SIZE] = {2,1,1,0,1,1,0,2,2,0,2,2,0,3,
                                3,0,3,3,0,4,4,0,5,5};
    int *pV = pozVal; //a pointer for pozVal array
    //Positions to be used as booleans (testing) 1 is propertys buyable
    // default 0 are unbuyable spots. If bought prop changes to 0
    //IF P1 BUYS/OWNDS ifOpen POSITION = 3, IF P2 BUYS/OWNDS POSITION 
    //ifOpen position = 4
    int ifOpen[24] = {0,1,1,8,1,1,0,1,1,8,1,1,0,1,1,8,1,1,0,1,1,8,1,1};
    int *IO = ifOpen; //a pointer for ifOpen array
    int p1Money = 3,p2Money = 3; //player 1 and 2's money, starting with $3
    int p1Poz = 0,p2Poz = 0;// start is position 0 
    int p1Yoki = 0,p2Yoki = 0; //keeps track of players yoki, starting with 0
    int roll = 0; //simple roll variable
    //int p1Buy = 0, p2Buy = 0; //
    bool p1Turn = true, p2Turn = true; //boolean statement for turn switching
    int p1Skip = 0, p2Skip = 0; //var for if players turn is to be skipped
    int p1Jfc = 0, p2Jfc = 0; //get out of jail free cards for p1/p2
    int i = 0; //test var
    string star ="*****************************************\n";
    
    //beginning of do while loop till someone has 5 yoki (wins)
    do{
    //if its player 1 turn and his turn is not to be skipped
    if(p1Skip != 0){
    p2Turn = true;
    p1Turn = false;
    // if player 2 turn and his turn is not to be skipped
    }else if (p1Skip == 0)
    p2Turn = false;
    p1Turn = true;
    //p1 turn is true so he rolls, after his turn = false and p2 turn is true;
    if(p1Turn == true && p1Skip == 0){
    //roll function returns the value for roll
      roll = ROLL(p1Skip,p2Skip,p1Turn,p2Turn,star);
    cout<<"You rolled a "<<roll<<endl;
    //position is current position + roll.
    p1Poz = p1Poz + roll;
    //if position passes 24, subtract 24 from position (resetting position)
    if(p1Poz >= 24){
    p1Poz = p1Poz - 24;
    //pay the player 2 dollars for circling the map(when resetting by -24)
    cout<<"p1 circled the map and recieved $2 from the bank"<<endl;
    //position 0 aka start value set to #2, when go around the map
    //player gets the pozVal as money ($2)
    p1Money = p1Money + pozVal[0];
    }
    //if p1 position is a open buyable one, and he has >= enough money for it
    // and its his turn and his turn is not to be skipped
    if(ifOpen[p1Poz] == 1 && p1Money >= pozVal[p1Poz] && 
       p1Skip == 0 && p1Turn)
    {
    //if parameters are met, calls upon function "BUY"
    BUY(pozVal,ifOpen,p1Turn,p2Turn,p2Poz,p1Poz,p1Money,
        p2Money,p1Yoki,p2Yoki,p1Skip,p2Skip);
    //what happends if he buys it, the value goes from 1 to 3 for p1
    //this is a return from the buy function
    //logic for if p1 lands on a spot owned by p2 and has enough $$$$
    } else if (ifOpen[p1Poz] == 4 && p1Money >= pozVal[p1Poz] 
               && p1Skip == 0)
    {
    //else if parameters are met the function "mustPay" is inacted
    mustPay(pV,p1Money,p2Money,p1Poz,p2Poz,p1Turn,p2Turn,p1Skip,p2Skip);
    //if p1 lands on a position ownd by p2, and p1 money is less than its value
    // and p1 has 1 or more yoki
    }else if(ifOpen[p1Poz] == 4 && p1Money < pozVal[p1Poz] 
             && p1Yoki >= 1)
    {
    //test function is used to deterine lowest valued yoki
    testing = test(ifOpen,p1Turn,p2Turn);
    //if p1 cant pay p2, the function "cantPay" is encated using the 
    //returned value of test sent to testing (above)
    cantPay(ifOpen,pozVal,testing,p1Yoki,p2Yoki,p1Turn,p2Turn,
            p1Skip,p2Skip);
    //else if its p1 turn, p1 is on a position owned by p2, and p1 dosnt 
    //have enough money to pay and p1 has 0 yoki to give, and his turn is 
    //current no tot be skipped
    }else if (p1Turn && ifOpen[p1Poz] == 4 && p1Money < 
             pozVal[p1Poz] && p1Yoki == 0 && p1Skip == 0 )
    {
    //the trnSK function is  self explanatory
    trnSK(pozVal,p1Skip,p2Skip,p1Turn,p2Turn,p1Poz,p2Poz);
    //if p1 lands on a position in the ifOpen array thats == 8
    // this is a card position 
    }else if(p1Skip == 0 && ifOpen[p1Poz] == 8 && p1Turn)
    {
    //the function cards is enacted to simulate drawling a card
    cards(ifOpen,pozVal,p1Turn,p2Turn,p1Yoki,p2Yoki,p1Poz,
    p2Poz,p1Skip,p2Skip,p1Jfc,p2Jfc,p1Money,p2Money);
    //else if its p1 turn and his position == 18 and his turn is not to be
    //skipped. Position 18 is "Jail"
    } else if(p1Turn && p1Poz == 18 && p1Skip == 0)
    {
    //The jail function is enacted to move p1 to position 6
    //and he will miss a turn
    jail(p1Turn,p2Turn,p1Poz,p2Poz,p1Jfc,p2Jfc,p1Skip,p2Skip);
    }
    //displays p1 position,money,# of yoki and # of jail cards
    cout<<"Your position is "<<p1Poz<<"\t"<<
    "Money "<<p1Money<<"\t\t"<<
    "Your Yoki "<<p1Yoki<<"\tYour Jail cards ["<<p1Jfc<<"/2]\n"<<"You are " <<fixed<<showpoint<<setprecision(1)<<((static_cast<float>(p1Yoki)/9)*100)<<"% to victory!"<<endl;
  /*
  * 
  * 
                   !!!!!!!END OF PLAYER 1'S TURN!!!!!!!
  * 
  * 
  
  */   
    //used for starting/deciding if its player's 2 turn/should go
    if(p2Skip != 0)
    {
    p1Turn = true;
    p2Turn = false;
    }else if (p2Skip == 0)
    p1Turn = false;
    p2Turn = true;
    }
    //decoration stars
    cout<<endl; //this is just making a new line to seperate
    rowStar(star);
    //same thing for p1 but for p2!
    //if its p2 turn and its not to be skiped, continue
    if(p2Turn && p2Skip == 0){
    //p1 and p2 roll function combined. ROLL function returns roll
    roll = ROLL( p1Skip,p2Skip,p1Turn,p2Turn,star);
    //reports what p2 rolled
    cout<<"\t\tPlayer2[computer] rolled a ["<<roll<<"]"<<endl;
    //updates p2[computer] Position
    p2Poz = (p2Poz + roll);
    if(p2Poz >= 24){
    p2Poz = p2Poz - 24;
    //pay the player 2 dollars for circling the map(when resetting by -24)
    cout<<"\t\tp2[computer] circled the map and recieved $2 from the bank"<<endl;
    p2Money = p2Money + pozVal[0];
    }
    //logic for if player 2 lands on a open spot he buys, value set to 4
    if(ifOpen[p2Poz] == 1 && p2Money >= pozVal[p2Poz]
       && p2Skip == 0 && p2Turn)
    {
    //if p2 lands on a position in array ifOpen == 1 (avliable) and has 
    //enough money and turn is not to be skiped oh and if its his turn!
    //the "BUY" function is triggered
    BUY(pozVal,ifOpen,p1Turn,p2Turn,p2Poz,p1Poz,p1Money,
        p2Money,p1Yoki,p2Yoki,p1Skip,p2Skip);
    //logic for if p2 lands on a spot owned by p1 and has enough money to pay
    //he pays p1 the money and loses that amount
    }else if(p2Turn && ifOpen[p2Poz] == 3 && p2Money
            >= pozVal[p2Poz] && p2Skip == 0){
    //the "mustPay" function is triggered to pay p1
    mustPay(pV,p1Money,p2Money,p1Poz,p2Poz,p1Turn,p2Turn,p1Skip,p2Skip);
    //if player 2 lands on a spot owned by player 1 and cannot pay p2 must
    //forfeit a yoki
    }else if (p2Turn && ifOpen[p2Poz] == 3 && p2Money < 
             pozVal[p2Poz] && p2Yoki >= 1 && p2Skip == 0){
    //test function is called to choose the yoki to forfeit
    //once test function returns the value to testing, it can be used in
    //the "cantPay" function
    testing = test(ifOpen,p1Turn,p2Turn);
    cantPay(ifOpen,pozVal,testing,p1Yoki,p2Yoki,p1Turn,p2Turn,
            p1Skip,p2Skip);
    //to skip a turn if no yoki or money
    }else if(p2Turn && ifOpen[p2Poz] == 3 && p2Money < 
            pozVal[p2Poz] && p2Yoki == 0 && p2Skip == 0)
    {
    //if p2 lands on p1 position can cannot pay and has no yoki to give
    //the trnSK function is called to skip his next turn
    trnSK(pozVal,p1Skip,p2Skip,p1Turn,p2Turn,p1Poz,p2Poz);
    //if p2 lands on a open position but does not have enough money to buy it
    }else if(ifOpen[p2Poz] == 1 && p2Money < pozVal[p2Poz])
    {
    cout<<"P2[COMPUTER] landed on a free yoki worth "<<pozVal[p2Poz];
    cout<<" but did not have enough to buy it!"<<endl;
    //just like for p1 if p2 lands on position 18 aka jail
    //if p2 turn and p2 position is 18 and turn to not be skipped
    }else if(p2Turn && p2Poz == 18 && p2Skip == 0)
    {
     //calling "Jail" function
    jail(p1Turn,p2Turn,p1Poz,p2Poz,p1Jfc,p2Jfc,p1Skip,p2Skip);
    // if p2 turn is not to be skipped and his position is on #8 and its p2 turn
    }else if (p2Skip == 0 && ifOpen[p2Poz] == 8 && p2Turn)
    {
    //the "cards" function is called to simulate p2 drawling from the deck
     cards(ifOpen,pozVal,p1Turn,p2Turn,p1Yoki,p2Yoki,p1Poz,
            p2Poz,p1Skip,p2Skip,p1Jfc,p2Jfc,p1Money,p2Money);
    }
    //this area is for showing p2's stats such as
    //p2 position/p2money/p2 # of Yoki and # of jail cards
    cout<<"p2[computer] position is "<<p2Poz<<
    "\tp2[computer] Money is "<<p2Money<<"\t\tP2 has "<<p2Yoki<<" Yoki! "<<
    " p2 Jail cards ["<<p2Jfc<<"/2]\n"<<"P2[COMPUTER] is "<<fixed<<showpoint<<setprecision(1)<<((static_cast<float>(p2Yoki)/9)*100)<<"% to victory!"<<endl;
    //at the end of p2 turn, p2 turn becomes false (off) and p2 turn becomes
    //true (on)
    p2Turn = false;
    p1Turn = true;
    }
    cout<<"\n"<<endl; //used just to make a new line/seperation
    rowStar(star);//simple calls the rowstar decoration function
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
    }while(p1Yoki < 9 && p2Yoki < 9);
    return 0;
/*
 *
 *                      Beginning of Functions!
 * 
 */
    }
    //this roll function handles the rolls for p1 and p2
    int ROLL(int p1skip,int p2Skip,int p1Turn,int p2Turn,string star)
    {
    int ROLL = 0;
    char input = 0;
    int i = 0;
    if(p1skip == 0 && p1Turn)
    {
    //loops untill user enters R or r correctly to trigger roll
    do{
    cout<<"Press R to roll\n";
    rowStar(star); //decoration/seperator
    cin>>input;
    }while(input != 'R' && input != 'r');
    //ask user to input r to roll.
    //continues once proper roll input received
    if(input == 'R' || input == 'r')
    //while loop to do rand 5 times than output the number
    while( i < 5 && p1skip == 0){
    //rolls only between 2-12 (maxium and minimum for two dice
    ROLL = rand()%11+2;
    i++;
    }
    return ROLL;
    //the roll function for P2[computer's] roll
    }else if (p2Turn &&  p2Skip == 0 )
    {
    for(int i = 0;i<10;i++){
    //rolls only between 2-12 (maxium and minimum for two dice
    ROLL = rand()%11+2;
    i++;
    }
    return ROLL;
    }
    }
    //switching buy function for p1 and p2 to this function
    //function handles the buying of Yoki/switching of elements on the
    //ifOpen array
    int BUY(int pozVal[],int ifOpen[],  bool p1Turn,bool p2Turn,
           int p2Poz, int p1Poz,int &p1Money, int &p2Money, //con
           int &p1Yoki,int &p2Yoki,int p1Skip,int p2Skip) //con
    {
    //for p1 if its p1's turn and its not to be skipped
    if(p1Turn == true  && p1Skip == 0)
    {
    //ask the user(p1) if he wishes to buy the position
    char input = 0;
    cout<<"You landed on a Yoki Position worth "<<pozVal[p1Poz]<<endl;
    cout<<"Do you wish to buy it?";
    cin>>input;
    //by default y or Y = yes anything else will be considered a NO
    if(input == 'y' || input == 'Y')
    {
    //this changes the element [1] on the ifOpen array to 3 representing
    //p1's ownership
    ifOpen[p1Poz] = 3;
    //p1 Money is reduced by the amount of the corrospoding positions value on
    //the pozVal array
    p1Money = p1Money - pozVal[p1Poz];
    p1Yoki = p1Yoki + 1;
    cout<<"p1 bought position "<<p1Poz<<"'s yoki for "<<
           pozVal[p1Poz]<<endl;
    //this is if any input not Y or y = no
    }else if(input != 'y' && input != 'Y')
    return 0;
    //start of the function to handle P2[COMPUTER]s purchases
    } else if (p2Turn == true && p2Skip == 0)
    {
    //output text and positions value
    cout<<"P2 landed on a Yoki worth $"<<pozVal[p2Poz]<<endl;
    cout<<"P2 bought the Yoki position on space #"<<p2Poz<<endl;
    //LOGIC FOR CHANGING THE ARRAY ELEMENT TO 4 TO SHOW P2 OWNERSHIP
    ifOpen[p2Poz] = 4;
    p2Money = p2Money - pozVal[p2Poz];
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
    //function to handle JAIL for p1 and p2
    int jail(bool p1, bool p2, int& p1Pos, int& p2Pos,int& p1Jfc,int& p2Jfc,
             int& p1Skip, int& p2Skip)
    {
    //if player2[computer's] turn and he does not have a get out of jail card
    if(p2 && p2Jfc == 0)
    {
    cout<<"P2[computer] Landed on position 18! AKA ""GO TO JAIL\n";
    cout<<"P2[COMPUTER] Is moved to position #6 and loses a turn!"<<endl;
    p2Pos = 6;
    p2Skip = 2;
    //if its p1 turn and he does not have a get out of jail card
    }else if(p1 && p1Jfc == 0)
    {
    cout<<"OH NO! p1 AKA YOU! landed on ""GO TO JAIL! \n";
    cout<<"You lose 1 turn and are moved to position #6!"<<endl;
    p1Pos = 6;
    p1Skip = 2;
    //if its p1 turn and he DOES have atleast 1 get out of jail free card != 0
    }else if(p1 && p1Jfc != 0)
    {
    cout<<"OHHHH SWEET DEAL! YOU LANDED ON JAIL, AND GET MOVED TO P6 BUT\n"
    "Because you have a ""Get out of jail free card"" You dont lose a turn!\n";
    //now remove one get out of jail free card from p1 inventory
    p1Jfc = p1Jfc - 1;
    p1Pos = 6;
    //if p2 turn and he DOES have atleast 1 get out of jail card
    }else if(p2 && p2Jfc  != 0)
    {
    cout<<"P2[COMPUTER] used a Get out of jail Free card! P2[COMPUTER] is moved "
            "to\n"
    "Position #6 but does not lose a turn!\n";
    //now removes one get out of jail card from P2[COMPUTER'S] inventory
    p2Jfc = p2Jfc - 1;
    p2Pos = 6;
    }
    }
    // this function is for when a player lands on a YOKi ownd by anothe player
    // and has enough money to pay them. Handles both players
    int mustPay(int *posValue, int & p1Money,int & p2Money,int p1Pos, 
                int p2Pos, bool p1Turn, bool p2Turn,int p1Skip,int p2Skip)
    {
    // if its player 1 turn and his turn is not to be skipped
    if(p1Turn == true && p1Skip == 0)
    {
    cout<<"ahhh SNAPS! you landed on a position owned by P2[computer]!\n";
    cout<<"You must pay P2[computer] $"<<posValue[p1Pos]<<endl;
    //subtracts money from p1 = to the value of the yoki (position)
    //he is on and adds it to P2[COMPUTER'S] money
    p1Money = p1Money - posValue[p1Pos];
    p2Money = p2Money + posValue[p1Pos];
    //player 2 function money swap if landing on p1 position
    //see lines 159-161
    }else if(p2Turn == true && p2Skip == 0)
    {
    cout<<"P2[computer] landed on a spot owned by P1 worth "<<posValue[p2Pos]
    <<" P2[computer] has enough money thus will pay p1 the value of the "
            "positon"<<endl;
    p2Money = p2Money - posValue[p2Pos];
    p1Money = p1Money + posValue[p2Pos];
    cout<<"p1 Recived "<<posValue[p2Pos]<<endl;
    }
    }
    //this function is for when a player lands on another players YOKI
    //and that player does not have enough money to pay him
    int cantPay(int ifOpen[],int posValue[],int testing,int& p1Yoki,
                int& p2Yoki,int p1Turn,int p2Turn,int p1Skip,int p2Skip)
    {
    //if P2[COMPUTER'S] turn and it is not to be skipped
    if(p2Turn && p2Skip == 0)
    {
    cout<<"OH NO! P2[comptuer] landed on your yoki but cannot pay!"
    "you are awarded one of his yoki!"<<endl;
    //output/informs which yoki is being given away and that yokis value
    cout<<"Giving p1 yoki at position "<<testing<<" Worth "<< posValue[testing]<<endl;
    //changing ownership of yoki by changing array value and subtracting
    //and adding yoki
    ifOpen[testing] = 3;
    p2Yoki = p2Yoki - 1;
    p1Yoki = p1Yoki + 1;
    //if P1 turn and it is not to be skipped
    }else if (p1Turn && p1Skip == 0 )
    {
    cout<<"YOU LANDED ON A YOKI OWNED BY P2[COMPUTER] AND DONT HAVE "
    "ENOUGH $$ TO PAY HIM =(\n";
    cout<<"So instead hes going to take your most vauable YOKI!";
    //informing which yoki and its value is being given away
    cout<<"You give P2[COMPUTER] your yoki at position "<<testing<<" worth "<<
    posValue[testing]<<endl;
    //changing yoki ownership by changing value in the array and adding
    //and subtracting yoki
     ifOpen[testing] = 4;
     p2Yoki = p2Yoki + 1;
     p1Yoki = p1Yoki - 1;
    }
    return 0;
    }
    //this function handles SKIPPING a players turn
    int trnSK(int posValue[],int& p1Skip,int& p2Skip,bool p1,bool p2,
                 int p1Pos,int p2Pos)
    {
    //if P2[COMPUTER']S turn and its not to be skipped
    if(p2 && p2Skip == 0)
    {
    cout<<"P2[computer] landed on a position owned by P1. P2[computer] dosnt "
    "have enough money or yoki. So P2[computer] loses a turn!"<<endl;
    //p2Skip =2 which will skip his next turn
    p2Skip = 2;
    //if P1 turn and it is not to be skipped
    }else if(p1 && p1Skip == 0)
    {
    cout<<"you landed on P2 YOKI on position "<<p1Pos<<" and dont have the "<<
    posValue[p1Pos]<<endl; 
    cout<<" or any yoki to give!!!!! So instead you must miss a turn!"<<endl;
    //turns p1Skip into 2 so his next turn will be skipped     
    p1Skip = 2;
    }
    return 0;
    }
    
    //this is the CARDS function which will draw which card which will
    //be another function per card to active
    int cards(int ifOpen[],int posVal[],int p1,int p2,int& p1Yoki,int& p2Yoki, 
            int p1Pos,int p2Pos,int& p1Skip,int& p2Skip,int& p1Jfc, //con
            int& p2Jfc,int& p1Money, int& p2Money) //con
    {
    int x = 0;
    //this randomly generate which card will be used based off paremeters
    x = rand()%21+1;
    // random generate which card.
    //if <= 3 card1 / if >3 and <=5 card2 /if >6 and <= 9 card3
    //if >9 and <=11 card4 and if >11 and <=21 card5
    if(x <= 3)
    {
    card1(ifOpen,posVal,p1,p2,p1Yoki,p2Yoki,p1Pos,p2Pos,p1Skip,p2Skip);
    }else if (x > 3 && x <= 6)
    {
    card2(ifOpen,posVal,p1,p2,p1Yoki,p2Yoki,p1Pos,p2Pos,p1Skip,p2Skip);
    }else if ( x > 6 && x <= 9 )
    {
    card3(ifOpen,posVal,p1,p2,p1Yoki,p2Yoki,p1Pos,p2Pos,p1Skip,p2Skip);
    }else if (x > 9 && x <= 11)
    {
    card4(ifOpen,posVal,p1,p2,p1Yoki,p2Yoki,p1Pos,p2Pos,p1Skip,p2Skip,p1Jfc,p2Jfc);
    }else if (x > 11 && x <= 21)
    {
    card5(ifOpen,posVal,p1,p2,p1Yoki,p2Yoki,p1Pos,p2Pos,p1Skip,p2Skip,p1Money,
            p2Money);
    }
    }
    
    //logic for card 1 which forces the player to surrender a card
    int card1(int ifOpen[],int posVal[],int p1,int p2,int& p1Yoki,int& p2Yoki, 
              int p1Pos,int p2Pos,int& p1Skip,int& p2Skip)
    {
    int card = 1;
    int SIZE = 24;
    int count = 0;
    int size = 0; //used to get the first lowest value to trade
    int size2 = 0; //used to get a second lowest value to trade
    //if p1 turn and p1Yoki >= 1
    if(p1 && card == 1 && p1Yoki >= 1 )
    {
    //goes through array till it locates the p1 lowest valued yoki
    while(ifOpen[size] != 3)
    size++;
    if(p1 && ifOpen[size] == 3 && p1Yoki >= 1 && p1Skip == 0);
    {
    cout<<"P1 drew the WORST CARD! P1 must forfeit his lowest "
    "value yoki to P2[COMPUTER]!\n";
    cout<<"You lost the yoki at position "<<size<<endl;
    //changing ownership of the array and subtracting/adding yoki 
    ifOpen[size] = 4;
    p1Yoki = p1Yoki - 1;
    p2Yoki = p2Yoki + 1;
    }
    //if player 1 has no yoki to give loses a turn instead
    }else if(p1 && card == 1 && p1Yoki < 1 && p1Skip == 0)
    {
    cout<<"You pulled the BAD card and had to give up a yoki but didnt have any "
    "yoki so you lose a turn!"<<endl;
    //adds 2 to p2Skip which will skip his next turn
    p1Skip = 2;
    //same logic now for player 2 as for player 1
    }else if(p2 && card == 1 && p2Yoki >= 1 && p2Skip == 0)
    {
    //finds player 2 lowest yoki if he has atleast 1
    while(ifOpen[size] != 4)
    size++;
    if(p2 && ifOpen[size] == 4);
    {
    cout<<"ohhh LUCKY FOR YOU! P2[COMPUTER] landed on the bad card and had to\n"
    "forfeit his lowest value yoki!"<<endl;
    cout<<"P2[COMPUTER] lost the yoki at position "<<size<<endl;
    //changings ownership of yoki based off numbers in the array and + - yoki
    ifOpen[size] = 3;
    p1Yoki = p1Yoki + 1;
    p2Yoki = p2Yoki - 1;
    }
    //if P2[COMPUTER] dosnt have any yoki to give he loses a turm instead
    }else if(p2 && card == 1 && p2Yoki < 1 && p2Skip == 0)
    {
    cout<<"HAHAHA P2[COMPUTER] GOT THE BAD CARD BUT DIDNT HAVE ANY YOKI TO GIVE, "
    "LOSES A TURN INSTEAD!"<<endl;
    //p2Skip will be 2 which will cause him to miss its next turn to roll
     p2Skip = 2;
    }
    }
    
    //card2 is where you trade your lowest yoki for the other players highest
    int card2(int ifOpen[],int posVal[],int p1,int p2,int& p1Yoki,int& p2Yoki, 
          int p1Pos,int p2Pos,int& p1Skip,int& p2Skip)
    {
    int card = 4;
    int SIZE = 24;
    int count = 0;
    int size = 0; //used to get the first lowest value to trade
    //if p1 turn and p1 has atleast 1 yoki and  so does p2 and p1 turn is not
    //to be skipped
    if (p1 && card == 4 && p1Yoki >= 1 && p2Yoki >= 1 && p1Skip == 0 )
    {
    cout<<"NICE! You landed on the ""CHANCE CARD"", YOU MUST trade your "
    "lowest value yoki for P2[COMPUTER] highest!\n";
    //logic for finding which yoki in the array to be traded
    while(ifOpen[size] != 3)
    size++; 
    while(ifOpen[SIZE] != 4)
    SIZE--;
    //if p1 turn and p2 has a highest valued yoki than your lowest and 
    //your turn is to not be skipped
    if(p1 && ifOpen[size] == 3 && posVal[size] < posVal[SIZE] && p1Skip == 0)
    {
    cout<<"OHHHHHH GOOD FOR YOU! This ""Chance"" card works in your favor!!\n";
    cout<<"Your lowest valued Yoki is at #"<<size<<" worth $"<<posVal[size]<<"\n"
    "While P2[COMPUTER]'S HIGHEST valued card was at #"<<SIZE<<" worth "<<
            posVal[SIZE]<<"\n"
    "so you traded P2[COMPUTER]'s $"<<posVal[SIZE]<<" Yoki for your $"<<
            posVal[size]<<" Yoki!\n";
    //logic for switching ownership in the array
    ifOpen[size] = 4;
    ifOpen[SIZE] = 3;
    //if p2 highest valued yoki is lower than your lowest
    }else if(p1 && ifOpen[size] == 3 && posVal[size] > posVal[SIZE] && 
             posVal[size] != posVal[SIZE] && p1Skip == 0)
    {
    cout<<"OH WHAT THE HECK! P2[COMPUTER] DOSNT have any Yoki more valuable "
    "than your LOWEST valued one!!\n"
    "P2[COMPUTER] highest valued Yoki is only worth $"<<posVal[SIZE]<<" on #"
            <<SIZE<<"\n"
    "while your lowest valued Yoki is worth $"<<posVal[size]<<" on #"<<size<<"\n"
    "so basicaly ......that sucks for you...must still trade your lowest for "
    "P2[COMPUTER]'s highest sadly."
    "P2[COMPUER] gets Your Yoki on #"<<size<<" Worth $"<<posVal[size]<<
    " And you get P2[COMPUTER'S yoki on "
    "#"<<SIZE<<" Worth $"<<posVal[SIZE]<<endl;
    //logic for switching ownership in the array
    ifOpen[size] = 4;
    ifOpen[SIZE] = 3;
    }else  if(p1 && ifOpen[size] == 3 && posVal[size] == posVal[SIZE] && 
            p1Skip == 0)
    {
    cout<<"UGGH!!! !!!\n"
    "YOUR LOWEST VALUED YOKI IS THE SAME AS P2[COMPUTER'S HIGHEST!:( UGH!!\n"
    "YOur lowest Valued yoki is the Yoki on #"<<size<<" worth $"<<posVal[size]<<"\n"
    "and P2[COMPUTER]'s highest is on #"<<SIZE<<" Worth $"<<posVal[SIZE]<<"\n"
    "SO BASICALY UNPRODUCTIVE TRADE!  =)\n"
    "P2[COMPUER] gets Your Yoki on #"<<size<<" Worth $"<<posVal[size]<<
    " And you get P2[COMPUTER'S yoki on "
    //outputing information on which yoki and positon swapped
    "#"<<SIZE<<" Worth $"<<posVal[SIZE]<<endl;
    //logic for switching yoki ownership in array
    ifOpen[size] = 4;
    ifOpen[SIZE] = 3;
    }
    //cant swap yoki because p1 has none so he loses a turn instead
    } else if (p1 && card == 4 && p1Yoki == 0 && p1Skip == 0)
    {
    cout<<"!!! YOU PULLED THE CHANCE CARD!!\n"
    "Usuarly this card allows you to swap your lowest Yoki with P2[COMPUTER]'S "
            "HIGHEST!!\n"
    "But since you have NO YOKI!! YOU lose a turn instead WHAHAH sorry!\n";
    //p1Skip = 2 so next turn is skipped
    p1Skip  = 2;
    //p2 swaps his lowest valued wit p1 highest if they both atleast have yoki                                                
    }else if(p2 && card == 4 && p1Yoki >= 1 && p2Yoki >= 1 && p2Skip  == 0)
    {
    cout<<"P2[COMPUTER] landed on a ""CHANCE"" card!\n"
    "This allows P2[COMPUTER] to swap his lowest value Yoki for Your highest!\n";
    //logic for finding which array to be swapped
    while(ifOpen[size] != 4)
    size++; 
    while(ifOpen[SIZE] != 3)
    SIZE--;     
    //swaps p2 lowest valued for p1 highest
    if(p2 && ifOpen[size] == 4 && posVal[size] < posVal[SIZE] && p2Skip  == 0)
    {
    cout<<"BAD LUCK!!\n"
    "P2[COMPUTER]'s lowest valued Yoki was #"<<size<<" Worth "<<posVal[size]<<"\n"
    "While your highest valued card was #"<<SIZE<<" valued at "<<posVal[SIZE]<<"\n"
    "P2[COMPUTER] took your $"<<posVal[SIZE]<<" Yoki for his "<<
            posVal[size]<<" Yoki!\n";
    ifOpen[size] = 3;
    ifOpen[SIZE] = 4;
    //p2 lowest valued yoki is highest than p1's highest
    } else if(p2 && ifOpen[size] == 4 && posVal[size] > posVal[SIZE] && 
    posVal[size] != posVal[SIZE] && p2Skip == 0)
    {
    cout<<"LOOOL! P2[COMPUTER] would have swaped you  his lowest valued Yoki "
            "for yout highest but\n"
    "his lowest valued Yoki is actuarly worth more than your HIGHEST LOL!!\n"
    "Your highest valued Yoki is only worth $"<<posVal[SIZE]<<" on #"<<SIZE<<"\n"
    "While P2[COMPUTER's lowest Yoki is "<<posVal[size]<<" on #"<<size<<"\n"
    "This works in your favor as he has to swap either way!\n "
    "P2[COMPUTER] gets your Yoki on #"<<SIZE<<" Worth "<<posVal[SIZE]<<" And you"
    " get his Yoki #"<<size<<" worth "<<posVal[size]<<"\n";
    ifOpen[size] = 3;
    ifOpen[SIZE] = 4;
   } else if(p2 && ifOpen[size] == 4 && posVal[size] == posVal[SIZE] && p2Skip == 0)
   {
   cout<< "UNFORTUNATLY FOR P2[COMPUTER] YOUR LOWEST VALUED YOKI IS THE SAME "
           "AS HIS highest!!!:(!\n"
    "P2[COMPUTER]'s lowest Valued yoki is on #"<<size<<" worth $"
           <<posVal[size]<<"\n"
    "While Your highest is "<<SIZE<<" worth $"<<posVal[SIZE]<<"\n"
    "Even if it seems pontless, you two still have to swap Yoki!\n"
    "P2[COMPUTER] gets #"<<SIZE<<" worth "<<posVal[SIZE]<<" and you get #"<<
    size<<" worth "<<posVal[size]<<"\n";
     ifOpen[size] = 3;
     ifOpen[SIZE] = 4;
    }
    }else if (p2 && card == 4 && p2Yoki == 0 && p2Skip == 0)
    {
    cout<<"!!! P2[COMPUTER] PULLED THE CHANCE CARD!!\n"
    "But P2[COMPUTER HAS [0] YOKI TO SWAP SO THIS CARD BACKFIRES!\n"
    "P2[COMPUTER LOSES A TURN!\n";
    p2Skip = 2;
    }else if (p2 && card == 4 && p2Yoki >= 1 && p1Yoki == 0 && p2Skip == 0) 
    {
    cout<<"!!!! alert !!!!\n";
    cout<<"P2[COMPUTER] LANDED ON THE ""CHANCE"" CARD to swap yoki but you had "
            "[0] SO you lose a turn!\n";
    p1Skip = 2;
    }
    }
    
    int card3(int ifOpen[],int posVal[],int p1,int p2,int& p1Yoki,int& p2Yoki, 
              int p1Pos,int p2Pos,int& p1Skip,int& p2Skip)
    {
    int card = 5;
    if(p1 && card == 5 && p1Skip == 0)
    {        
    //possible issue when no open cards, but probably not as game should have 
    //ended by that point!
    cout<<"OHHH You landed on a very nice card! This is the ""Free Yoki"" card!\n"
    "You get to move to the nearest Open Yoki, and claim it for FREE!!\n";
    while(ifOpen[p1Pos] != 1)
    p1Pos++;
    if(p1Pos >= 24)
    p1Pos = p1Pos - 24;
    while(ifOpen[p1Pos] != 1)
    p1Pos++;
    if(ifOpen[p1Pos] == 1)
    ifOpen[p1Pos] = 3;
    cout<<"You got the Yoki at #"<<p1Pos<<" For free!, it's value is "
            <<posVal[p1Pos]<<endl;
     p1Yoki = p1Yoki + 1;
    }else if(p2 && card == 5 && p2Skip == 0)
    {
    //possible issue when no open cards, but probably not as game should have 
    //ended by that point!
    cout<<"P2[COMPUTER] GOT A GOOD CARD! he gets to move to the nearest open "
    "YOKI and take it for FREE!\n";
    while(ifOpen[p2Pos] != 1)
    p2Pos++;
    if(p2Pos >= 24)
    p2Pos = p2Pos - 24;
    while(ifOpen[p2Pos] != 1)
    p1Pos++;
    if(ifOpen[p2Pos] == 1)
    ifOpen[p2Pos] = 4;
    cout<<"P2[COMPUTER] whent to #"<<p2Pos<< " and recieved the Yoki there "
            "worth $"<<
    posVal[p2Pos]<<" fOR FREE!\n";
    p2Yoki = p2Yoki + 1;
    }
    }
    
    int card4(int ifOpen[],int posVal[],int p1,int p2,int& p1Yoki,int& p2Yoki, 
              int p1Pos,int p2Pos,int& p1Skip,int& p2Skip,int& p1Jfc, int& p2Jfc)
    {
    int card = 6;
    if(p1 && card == 6 && p1Skip == 0 && p1Jfc < 2)
    {
    cout<<"OHH INteresting! You received a ""Get out of Jail free card! IM "
            "sure you know whats that for!\n";
    p1Jfc = p1Jfc + 1;
    }else if (p1&& card == 6 && p1Skip == 0 && p1Jfc >= 2)
    {
    cout<<"You drew a jail free card but have already reaced the maxium 2/2 JFC\n"
    "Thus this card is useless and does nothing.\n";
    p1Jfc = p1Jfc + 0;
    }else if(p2 && card == 6 && p2Skip == 0 && p2Jfc < 2)
    {
    cout<<"P2[COMPUTER] DREW A ""GET OUT OF JAIL FREE CARD!\n";
    p2Jfc = p2Jfc + 1;
    }else if(p2 && card == 6 && p2Skip == 0 && p2Jfc >= 2)
    {
    cout<<"P2[COMPUTER] DREW A ""GET OUT OF JAIL FREE CARD"" But already has "
            "the max of 2/2\n"
    "Thus this card has no affect at all!\n";
    p2Jfc = p2Jfc + 0;
    }
    }
    
    int card5(int ifOpen[],int posVal[],int p1,int p2,int& p1Yoki,int& p2Yoki, 
              int p1Pos,int p2Pos,int& p1Skip,int& p2Skip,int& p1Money,int& p2Money)
    {
    int card = 7;
    int rMoney = 0;
    if(p1 && card == 7 && p1Skip == 0)
    {
    cout<<"!! MONEY CARD!! MONEY CARD!! MONEY CARD!!\n"
    "You drew THE MONEY CARD!!\n";
    //random generate $1-5 to give     
    rMoney = rand()%5+1;
    cout<< "You get $"<<rMoney<<" From this card!\n";
    p1Money = p1Money + rMoney;
    }else if (p2 && card == 7 && p1Skip == 0)
    {
    rMoney = rand()%5+1;
    //generate $ 1-5 to give to p2 for the money card!
    cout<<"P2[COMPUTER] DREW A MONEY CARD!!\n"
    "P2[COMPUTER] received "<<rMoney<<" from the card!!\n";
    p2Money = p2Money + rMoney;
    }
    }

void rowStar(string star)
{
    cout<<star;
}


