/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 17th, 2018, 9:40 AM
 * Purpose:  Setup for Dominion
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <cstdlib>  //Random Numbers
#include <ctime>    //Time to set the seed
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns
const char NCARDS=7;//Column Dimension for the Players 2-D array

//Function Prototypes
void filMny(char [],char);
void filPts(char [],char);
void filAct(char [],char);
void filPlry(char [][NCARDS],char);
void prntDck(char [],char,char);
void prntPly(char [][NCARDS],char);
void shuffle(char [],char);
void bubble(char [],char);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const char NPLYRS=2;
    const char NMNY=99-2*5;//2 Players start with 5 Bronze money cards
    const char NPTS=90-2*2;//2 Players start with 2 1 pt cards from point deck
    const char NACT=100;
    char mnyDeck[NMNY];
    char ptsDeck[NPTS];
    char actDeck[NACT];
    char cards[NPLYRS][NCARDS];
    
    //Initial Variables
    filMny(mnyDeck,NMNY);
    filPts(ptsDeck,NPTS);
    filAct(actDeck,NACT);
    filPlry(cards,NPLYRS);

    //Check the fills
    shuffle(mnyDeck,NMNY);
    shuffle(ptsDeck,NPTS);
    shuffle(actDeck,NACT);
    prntDck(mnyDeck,NMNY,10);
    prntDck(ptsDeck,NPTS,10);
    prntDck(actDeck,NACT,10);
    prntPly(cards,NPLYRS);
    
    //Make sure we didn't lose any cards
    bubble(mnyDeck,NMNY);
    prntDck(mnyDeck,NMNY,10);
    
    //Map/Process Inputs to Outputs
 
    
    //Output the results

    
    //Exit program!
    return 0;
}

void bubble(char d[],char n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(d[j]>d[j+1]){
                char temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
            }
        }
    }
}

void shuffle(char c[],char n){
    for(int shfl=1;shfl<7;shfl++){
        for(int card=0;card<n;card++){
            int random=rand()%n;
            char temp=c[card];
            c[card]=c[random];
            c[random]=temp;
        }
    }
}

void prntDck(char d[],char n,char perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntPly(char p[][NCARDS],char n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<NCARDS;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void filMny(char m[],char n){
    char cnt=0;
    //33 Silver
    for(int i=1;i<=33;i++){
        m[cnt++]='S';
    }
    //33 Gold
    for(int i=1;i<=33;i++){
        m[cnt++]='G';
    }
    //23 Bronze
    for(int i=1;i<=23;i++){
        m[cnt++]='B';
    }
    if(cnt!=n)cout<<"Error in filling the money deck";
}

void filPts(char p[],char n){
    char cnt=0;
    //30 3's
    for(int i=1;i<=30;i++){
        p[cnt++]='3';
    }
    //30 6's
    for(int i=1;i<=30;i++){
        p[cnt++]='6';
    }
    //30-4 1's
    for(int i=1;i<=26;i++){
        p[cnt++]='1';
    }
    if(cnt!=n)cout<<"Error in filling the point deck";
}

void filAct(char a[],char n){
    char cnt=0;
    for(int i=0;i<10;i++){
        for(int j=1;j<=10;j++){
            a[cnt++]='a'+i;
        }
    }
    if(cnt!=n)cout<<"Error in filling the action deck";
}

void filPlry(char c[][NCARDS],char n){
    //Loop for both players
    for(int ply=0;ply<n;ply++){
        //Each player gets 5 bronze cards
        for(int card=0;card<5;card++){
            c[ply][card]='B';
        }
        //Each player gets 2 1 pt cards
        for(int card=5;card<NCARDS;card++){
            c[ply][card]='1';
        }
    }
}