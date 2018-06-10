/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 17th, 2018, 11:30 AM
 * Purpose:  Blackjack
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <cstdlib>  //Random Number
#include <ctime>    //Time
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
void filDeck(char [],char);
char suit(char);
char face(char);
void shuffle(char [],char);
void prtDeck(char [],char,char);
void selSort(char [],char);
void deal(char [],char, char [],char);
char numVal(char);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Seeding the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const char DECKSZ=52;
    char deck[DECKSZ];
    const char HNDSZ=5;
    char hand[HNDSZ];
 
    //Initial Variables
    filDeck(deck,DECKSZ);
    shuffle(deck,DECKSZ);
    selSort(deck,DECKSZ);
    prtDeck(deck,DECKSZ,13);
    for(int tryit=1;tryit<=11;tryit++){
        deal(deck,DECKSZ,hand,HNDSZ);
        prtDeck(hand,HNDSZ,HNDSZ);
    }
    prtDeck(deck,DECKSZ,13);
    
    //Map/Process Inputs to Outputs
 
    
    //Output the results

    
    //Exit program!
    return 0;
}

void deal(char deck[],char nDkCrds, 
             char hand[],char nHdCrds){
    static char current=0;
    if(current>nDkCrds-nHdCrds){
        shuffle(deck,nDkCrds);
        current=0;
    }
    for(int card=0;card<nHdCrds;card++){
        hand[card]=deck[current++];
    }
}

void selSort(char deck[],char dkSize){
    for(int lstSize=0;lstSize<dkSize-1;lstSize++){
        char idxSml=lstSize;
        for(int fndSml=lstSize+1;fndSml<dkSize;fndSml++){
            if(deck[idxSml]>deck[fndSml]){
                idxSml=fndSml;
            }
        }
        char temp=deck[lstSize];
        deck[lstSize]=deck[idxSml];
        deck[idxSml]=temp;
    }
}

void filDeck(char c[],char n){
    for(int eachCrd=0;eachCrd<n;eachCrd++){
        c[eachCrd]=eachCrd;
    }
}

char numVal(char card){
    int val=card%13+1;
    if(val==1)return 11;//Ace
    if(val>10)return 10;//face cards
    return val;
}

char suit(char card){
    string suitVal="SDCH";
    return suitVal[card/13];
}

char face(char card ){
    string faceVal="A23456789TJQK";
    return faceVal[card%13];
}

void shuffle(char c[],char nCard){
    for(int shfl=1;shfl<=7;shfl++){
        for(int card=0;card<nCard;card++){
            int random=rand()%nCard;
            char temp=c[card];
            c[card]=c[random];
            c[random]=temp;
        }
    }
}

void prtDeck(char deck[],char nCard,char perLine){
    cout<<endl;
    for(int card=0;card<nCard;card++){
        cout<<face(deck[card])<<suit(deck[card])<<" ";
        if(card%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}