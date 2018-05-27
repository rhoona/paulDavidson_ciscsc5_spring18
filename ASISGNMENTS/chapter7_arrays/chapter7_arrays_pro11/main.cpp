/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here

void readFile(ifstream &, char [], int &);
void writeFile(ofstream &, char [], char [], int);
int score(char [], char [], int);

int main(int argc, char** argv) {
    const int NQSTN = 50;
    int nqstns;
    char key[NQSTN],answers[NQSTN];
    char keyFile[] = "key.txt";
    string answerFile = "answer.txt";
    char scoreFile[]="score.txt";
    ifstream keyF, answerF;
    ofstream scoreF;
    
    
    
   
    
    keyF.open(keyFile);
    answerF.open(answerFile.c_str());
    scoreF.open(scoreFile);
    
    
      readFile(keyF,key,nqstns);
    readFile(answerF, answers, nqstns);
    writeFile(scoreF, key, answers, nqstns);
    int score1 = score(answers,key,nqstns);
    
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The graded score is: "<<100.0f*score1/nqstns<<"%";
    
    keyF.close();
    answerF.close();
    scoreF.close();
   
    
    return 0;
}
void readFile(ifstream & in, char keyAns[], int &count)
{
    count = 0;
    
    char keyAns1;
    while(in>>keyAns1)
    {
        keyAns[count++]=keyAns1;
    }
    }
  
void writeFile(ofstream & out, char key[], char ans[], int size)
{
    
    for(int i = 0; i<size;i++)
    {
        if(key[i]==ans[i])out<<i<<". Correct"<<endl;
        else out<<i<<". Incorrect"<<endl;
    }

}

int score(char ans[], char key[], int size)
{
    int correct = 0;
    for(int i = 0; i < size; i++)
    {
        if(key[i] == ans[i])correct++;
    }
    return correct;
}