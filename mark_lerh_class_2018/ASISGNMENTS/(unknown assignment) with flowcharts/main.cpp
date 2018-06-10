/* 
 * File:   main.cpp
 * Author: Paul Davidson
 * Created not sure
 * Purpose:  Menu with construct examples
 * 
 * assignment 2!! chapter 5
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    
    char choice;
    
    //Display menu
    cout<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Chapter 5, Question 22!"<<endl;
    cout<<"Type 2 for Chapter 5, Question 20!"<<endl;
    cout<<"Type 3 for Chapter 5, Question 26!!"<<endl;   
    cout<<"Type 4 for Chapter 5, Question 23!"<<endl;
    cout<<"Type 5 for Chapter 5, Question 21!(Upgraded version of Question 20)"<<endl;
    cout<<"Type 6 for Chapter 5, Question 19!"<<endl;
    cin>>choice;
   
    //Process/Map inputs to outputs
    if(choice>='1'&&choice<='6'){
        switch(choice){
     /*=========================================================================
             FIRST CASE
     ========================================================================== 
      */       case '1':{
                
                int row,input;
        char symbol,again;
        
        do{
            
        cout<<"Enter a number";
        cin>>row;
        cout<<"Enter what symbol to use";
        cin>>symbol;
        
        for(int count = 1; count<=row; count++)
        {
            for(int count = 1; count<=row; count++)
            {
                cout<<symbol;
                }
            cout<<"\n";
        }
        cout<<"Ohhhh cool design man! If you wanna go again enter [Y]";
        cin>>again;
        
        }while(again=='y'|| again=='Y');
            
        break;
            }
            /*================================================================
                                       CASE TWO
             ==========================================================*/
            
            case '2':{
       
                    srand(time(0));
   
                    int guess, computer,zero=0;
    char again;
    do{
    computer=rand()%101,1; //random number 1-100
   
   //User enters name which will be their guess
    cout<<"Enter number \n";
    cin>>guess;
    //Added so if someone cin's somthing weird they are prompted to enter 1-100
    if(cin.fail()){
    cin.clear();
    cin.ignore();
    cout<<"Numbers 1-100 ONLY please\n";
    
    //This is a serious of else if's to catch wrong user input
    }
    else if(guess>100){
        cout<<"OVER!!! your number must be 100 or less\n";
    }
    else if(guess<zero){
            cout<<"UNDER!! number must be 1 or more\n";
    }
    else if(guess==computer){
        cout<<"YOU WON!!\n";
    }
    else if(guess!=computer){
        cout<<"Sorry you did not win, The winning number was " ""<<computer;
        
    }
    cout<<"\n\nWant to Play agin? Press [y]";
    cin>>again;
    
    //After user is prompted if they would like to continue
 
    }while(again=='y'||again=='Y');
    if(again != 'y'||again !='Y')
        cout<<"Ok bye!";
            exit(EXIT_SUCCESS);
            
            }
            /*===============================================================
                                    CASE THREE
             * ================================================================
             */
            case '3':{
              
                   string name; //name of person
                   string describ; // description of self
                   
    ofstream outputFile;
    outputFile.open("jaw3.html");
    
    // Professor Leahr if you read this i want you to know this part right here 
    //almost drove me crazy!!!! finaly figured i needed the cin.ignore at the start!
    
     //Get name of user
    cin.ignore();
    cout<<"enter name "<<setw(2)<<endl;
    getline (cin, name);
   cout<<"description"<<endl;
    getline (cin, describ);
  //output information gathered [name and description] into html template
    outputFile<<"<html>\n"
            "<head>\n"
            "</head>\n"
            "<body>\n"
            "<font color=”#FF69B4″>\n"
            "<center>\n"
            "<h1>"<<name<<"</center>\n"
            "<hr />\n"
            "<center>"
            <<describ<<
            "</center>\n"
            "</font>\n"
            "</body>\n"
            "</html>"<<endl;
    // closes the output file and informs the user where its been saved
    
           outputFile.close();
           cout<<"Your information has been transfered to a html"
                   "file titled jaw3.html, enjoy";
           break;
            }
             /*===============================================================
                                    CASE FOUR
             * ================================================================
             */
             case '4':{
                int rows;
                char symbol,again;
           
                do{
                cout<<"Which symbol would you like to use?\n";
                cin>>symbol;
                cout<<"How many rows in your pyramid would you like?\n";
                cin>>rows;
                
                //added this after my code blew up if someone entered anything 
                //but  number for rows.
                
                 if(cin.fail()){
    cin.clear();
    cin.ignore();
    cout<<"NUMBERS PLEASE! GOSH HOW CAN SOMTHING NOT A NUMBER BE A ROW \n";
                 }
                
                for(int junk = 1; junk <= rows; junk++)
                {
                    for(int junk2 = 1; junk2 <= junk; junk2++)
                    {
                        cout<<symbol;
                    }
                    cout<<"\n";
                }
                
                cout<<"Would you like to run the program again? press [Y] :)";
                cin>>again;
                
                
            }while(again=='y'||again=='Y');
          
            break;
             }
             
/*====================== ===============================================================
                                    CASE FIVE
 * 
 * Note: I discovered that i have if's spread out. I belive my code can be
 * improved by cleaning it up a bit and reorganzing the flow
 * currently though it does work and performs exactly how i want it to !!
 * this version will keep track of your Attempts and wont save false 
 * or wrong inputs as attempts. Only valid inputs get accounted for.
 ==============================================================================*/
             
            case '5':{
                
                                    srand(time(0));
   
                    int guess, 
                        computer,
                        zero=0,
                        gAttempt;
                   
                    char again;
        
    computer=rand()%101,1; //random number 1-100
    do{
        
    
   
   //User enters name which will be their guess
    cout<<"Enter number \n";
    cin>>guess;
   
    //Added so if someone cin's somthing weird they are prompted to enter 1-100

    
    
    //This is a serious of else if's to catch wrong user input
   
    if(guess>100){
        cout<<"OVER!!! your number must be 100 or less\n";
    }
    if(guess<zero){
            cout<<"UNDER!! number must be 1 or more\n";
    }
    if(guess==computer){
        cout<<"!!!!!!!!!!!!!!!!!!!YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!\n";
         cout<<"!!!!!!!!!!!!!!!!!!!YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!\n";
          cout<<"!!!!!!!!!!!!!!!!!!!YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!\n";
           cout<<"!!!!!!!!!!!!!!!!!!!YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            cout<<"!!!!!!!!!!!!!!!!!!!YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!\n";
             cout<<"!!!!!!!!!!!!!!!!!!!YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!\n";
              cout<<"!!!!!!!!!!!!!!!!!!!YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        cout<<"Congrats on winning! You had a 1-100 chance and it only took "
                <<(gAttempt+1)<<" For you to guess it! Nice"; 
/*=============================================================================        
        //gAttempt +1 because gattempt loops after this notice so if you win
        //it will print your attempts behind by 1
===============================================================================*/
         
        exit(EXIT_SUCCESS); 
           }
    /*This is super important, this will clear and ignore input thats not desired
     * such as anything thats not a number */
    if(cin.fail()){
    cin.clear();
    cin.ignore();
    cout<<"Numbers 1-100 ONLY please\n";
    
      /* a series of If statments to catch nunbers to large,small or not in range
     * had them as "IF ELSE" before but lol that was a bad idea, if works much
     * beter*/
  
    }
    if(guess!=computer&&guess<=100&&guess>=1){
        cout<<"Sorry you did not win, The winning number was " ""<<computer<<endl;
          }
     if(guess != computer&&guess<=100&&guess>=1){
    gAttempt++;
       }
    if(guess!=computer&&guess<=100&&guess>=1){
         cout<<"Attempts ["<<gAttempt<<"]"<<endl;
    }
       //After user is prompted if they would like to continue
  cout<<"\n\nWant to Play agin? Press [y]";
    cin>>again;
    
  //Prompted with a option to play again, if again gets the value y or Y it will reply
   //otherwise any other input will end program.
    }while(again=='y'||again=='Y');
    if(again != 'y'||again !='Y')
        cout<<"Ok bye!";
            exit(EXIT_SUCCESS);
                
            }
/*==============================================================================
                                CASE SIX!!
 This one was a pain in the ass. Not because it was hard but because i tryed/wanted
 * to do it in a differnt way where you wouldnt have to keep pressing [Y] to add more
 * and instead just type somthing like [stop] when you entered all the inputs
 * Im sure its possible but after 8 hours i gave up and just did it normally.
 * works fine.Could be made more bulletproof though for sure.                   
 ===============================================================================*/            
            
            case '6':{
                
                    float budget,exp,total,test;
    char choice;
    
    //Initialize Variables
   
    
    cout<<"This is a Budget Analysis tool to help you determine if"
            "Your spending exceeds your monthly budget!\n"
            "First, enter what your monthly Budget actuarlly is!\n";
   cin>>budget;
  
   
   do{
       cout<<"Enter your expense!\n";
       cin>>exp;
       
       total=total+exp;
       
       
              
       if(total >= budget  ){
           test=budget-total;
           cout<<" Man you blew past your budget! "
                   "You are "<<test<< " in debt of your budget :(";
           
       
                   test;
       }else if(budget > total);
       test = budget - total;
       if(test>0){
       cout<<"You have this much left in your budget "<< test<<endl;
       }
       
       
       
       cout<<" Add another expense? [Y]? You are currently at "<<test;
       cin>>choice;

       
   }while(choice == 'y' ||choice== 'y');
       if(choice != 'Y' || choice != 'y');
           cout<<"Ok end of program beepboop bop";

                
            }
            break;
        }
    }else{
        cout<<"Exiting Menu"<<endl;
    }
  
/* NOT SURE/DONT KNOW HOW TO GIVE ANOTHER OPTION SO THAT YOU CAN EXIT TO MENU? */
      
 
    //Exit stage right!
    return 0;
}