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
#include <cmath>
#include <iomanip>
#include <cmath>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
void readFile(ifstream &, char [], int &);
void writeFile(ofstream &, char [], char [], int);
int score(char [], char [], int);
void rainFall();
int function(int [], int, int);
int countF(int);
int linearSort(const int[], int, int);
int linearSearch(const int[], int, int);
int binarySearch(const int[], int, int);
void selectionSort(int[],int);
void swap(int &, int &);
int linearSor(const int[], int, int);



int main(int argc, char** argv) {

   char choice;

    
     cout<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Chapter 7, Question 1!"<<endl;
    cout<<"Type 2 for Chapter 7, Question 2!"<<endl;
    cout<<"Type 3 for Chapter 7, Question 4!"<<endl;   
    cout<<"Type 4 for Chapter 7, Question 7!"<<endl;
    cout<<"Type 5 for Chapter 8, Question 1!"<<endl;
    cout<<"Type 7 for Chapter 8, Question 1!"<<endl;
    cout<<"Type 8 for Chapter 8, Question 2!"<<endl;
    cout<<"Type 9 for Chapter 8, Question 3!"<<endl;
    cout<<"Type A for Chapter 8, Question 4!"<<endl;




   
    cin>>choice;
    
    
    switch (choice) {
        case '1':{
            
                const int SIZE =10;
    int numbers[SIZE];
    int count,highest,lowest;
    
    highest = numbers[0];
    for(int count = 0; count < SIZE; count++)
    {
        cout<<"enter ten numbers to sort! \n";
        cin>>numbers[count];
        
        if(numbers[count] > highest)
        
            highest = numbers[count];
        }
            cout<<"The highest number sorted was "<<highest<<endl;

           lowest = numbers[0];
           for(int count = 0; count < SIZE; count++)
               if(numbers[count] < lowest)
                   lowest = numbers[count];
                           cout<<"The lowest number sorted was "<<lowest<<endl;
        

   
                          
        }
        break;
    
    
    
    case '2':{
        
        rainFall();
        
    }
    break;
        
    
    case '3':{
        
         int arrNumb;
    int arrFill = 0;
    
    int results;
    int N;
    
   
    
    cout<<"Enter how many numbers in the array";
    cin>>arrNumb;
    int arr[arrNumb];
    
    for(int i = 0; i < arrNumb; i++)
    {
        cout<<"Enter "<<arrNumb<<" numbers to fill the array! "<<endl;
        cin>>arr[i];
        
    }
  
    cout<<"Enter a number for N "<<endl;
    cin>>N;
    
  function (arr,arrNumb,N);
    
    }
    break;
    
    
    case '4':{
         const int BIG = 100;
    const int ROWS = 3;
    const int COLMS = 5;
   int probArray[ROWS][COLMS];
   int test3[BIG];
   int test,test2;
   int x;
   int mCount = 1;
   int lol = 0;
  static int total1;
   string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
   
    //Initialize Variables

       
   for(int i = 0; i < ROWS; i++)
   {
       cout<<"Give me the data for monkey # "<<mCount++<<endl;
       lol =0;
       
     
     
       for(int x = 0; x < COLMS; x++)
       {
           for(int y = 0; y<x;y++)
           {
           cout<<days[lol]<<endl;
           cin>>test3[y];
           lol++;
           }   //total1=countF(test);

           test2+=test;
       
       }
   }
    }
          break;

    
    case '5':{
        
        srand(time(0));
             int ARRAY_SIZE;
             int count = 1;
             int total = 0;
             ofstream outputFile;
             ifstream inputFile;
             int x;
    
         cout<<"Enter how many numbers we gunna sort :)";
        cin>>ARRAY_SIZE;
        
        //chooses the array size also have lowest start here so it can be initiaslized 
        //with numbers chosen array size! works sweet oh also highest is here but could be
        //probably set to 0 or 1
         int numbers[ARRAY_SIZE];
   unsigned int lowest=numbers[0];
            for(count = 0; count < ARRAY_SIZE; count++)
             numbers[count]=rand()%99+1;
         
            outputFile.open("SavedNumbers.txt");
    
         for(count = 0; count < ARRAY_SIZE; count++)
         
         outputFile << numbers[count] <<'\n';
         outputFile.close();
         
         
        ///////////////////////////////////
         
         inputFile.open("SavedNumbers.txt");
         
         while(count < ARRAY_SIZE && inputFile >> numbers[count])
             count++;
         
         inputFile.close();
         cout<<"Here are all the numbers generated friend :)\n";
         for(int x = 0; x< ARRAY_SIZE; x++)
         {
             cout<<numbers[x]<<" ";
         }
            unsigned int highest=numbers[0];

         for(int x = 0; x < ARRAY_SIZE; x++)
         {
             if (numbers[x] > highest)
             highest = numbers[x];
         }
         {
             cout<<"\nThe highest number in the set is! "<<highest<<endl;
         }
         for(int x = 0; x < ARRAY_SIZE; x++)
         {
             if(numbers[x] < lowest)
                 lowest = numbers[x];
         }
         {
             cout<<"The lowest number in your set is! "<<lowest<<endl;
         }
         for(int x = 0; x < ARRAY_SIZE; x++)
         {
             total += numbers[x];
         
         } 
         {
             cout<<"The total sum is! "<<total<<endl;
         }
         float avg = total/ARRAY_SIZE;
         cout<<fixed<<showpoint<<setprecision(2);
         cout<<"The average of all these numbers is! "<<avg<<endl;
         cout<<"\n\n";
         cout<<"if you run this and see this i have two issues with this code\n"
                 "first, i had to make lowest a unsigned int otherwise it broke\n"
                 "than i had to make highest one also cause than that broke if now\n"
                 "than i wanted the average to be a float (last part of code)\n"
                 "but for some reason wont work strange...";
        
    }
    break;
        case '6':{
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
        }
        break;
    
    
    case '7':{
        
        int results;
    int number;
    const int SIZE = 18;
    int arr[SIZE] = {5658845,4520125,7895122,8777541,8451277,1302850,
                    8080152,4562555,5552012,5050552,7825877,1250255,
                    1005231,6546231,3852085,7576651,7881200,4581002};
    
    cout<<"Enter a number to search for!"<<endl;
    cin>>number;
    
    results = linearSort(arr,SIZE,number);
    
    if(results == -1)
        cout<<"No match was found! ";
    else 
    {
        cout<<"a match was located at number: "<<results+1;
    }
        
    }
    
    break;
    case '8':{
    
        const int SIZE =10;
    int tests[SIZE] = {13579,26791,33445,55555,62483,77777,79422,85647,93121};
    int results;
    int number;
    
    cout<<"Enter your number to see if you won! ";
    cin>>number;
    
    results = linearSearch(tests, SIZE,number);
    
    if(results == -1)
        cout<<"Aww sorry you did not win! ";
    else
    
        cout<<"YOU WON OMG!" ;
                
    }         
     break;
           
   
    case '9':{
        
        
         const int SIZE = 10;
    int numbers[SIZE]={13579,26791,26792,33445,55555,62483, 77777,79422,85647,93121};
    int numb;
    int results;

    
    cout<<"This is a binary search to see if you got the winning lotto numbers!\n";
    cout<<"Enter your numbers to see if you win!\t";
    cin>>numb;
    
    results = binarySearch(numbers, SIZE, numb);
    
    if(results == -1)
        cout<<"Sorry your numbers didnt match, LOSER!";
    else
        cout<<"OH MAN YOU WON WOW!!!";
    
    }
    break;
        case 'A':{
            
            
             int results;
    int number;
    const int SIZE = 18;
    int arr[SIZE] = {5658845,4520125,7895122,8777541,8451277,1302850,
                    8080152,4562555,5552012,5050552,7825877,1250255,
                    1005231,6546231,3852085,7576651,7881200,4581002};
    
    cout<<"Enter a number to search for!"<<endl;
    cin>>number;
    
    selectionSort(arr, SIZE);

    
    
    results = linearSor(arr,SIZE,number);
    
    if(results == -1)
        cout<<"No match was found! "<<endl;
    else 
    {
        cout<<"a match was located at number: "<<results+1<<endl;
    }
    
    cout<<"This is a output of all the numbers sorted to test/show sort is working\n";
        for(int i =0; i <SIZE; i++)
    {
        cout<<arr[i]<<" ";
    }
        }
}

  
    
    
    
    


                
    
           
               

               

    
     
    

    return 0;
}

void rainFall()
{
    const int SIZE = 12;
    string months[SIZE] = { "January", "Feburary", "March", "April",
    "May","June","July","August","Septemeber", "October", " Novemeber", "Decemeber"};
    int rain[SIZE];
    int amount[SIZE];
    int total = 0;
    int highest;
    unsigned int lowest = rain[0];
   string wtf;
   string wtf2;
  
    
    for(int count = 0; count < SIZE; count++)
    {
        
        cout<<"Enter how much rain for "<<months[count]<<endl;
        cin>>amount[count];
        total += amount[count];
       
        if(amount[count] > highest)
        {
                    wtf = months[count];

            highest =  amount[count];        
            
        }
        
        if(amount[count]< lowest)
        {
            wtf2=months[count];
            lowest = amount[count];
        }

        
    }       
    cout<<"The highests rain fall was "<<wtf<<" "<<"with "<<highest<<" inches"<<endl;
    cout<<"The lowest rain fall was "<<wtf2<<" "<<"with "<<lowest<<" inches"<<endl;
    
        cout<<"The average rain fall is! "<<total/SIZE<<endl;

    }
int function(int arr[], int numb,   int N)
{
    for(int i = 0; i < numb; i++)
        if(i > N)
            cout<<i;
    
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
int linearSort(const int arr[], int size, int number)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        if(arr[index] == number)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
    
}
int linearSearch(const int arr[], int size, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        if(arr[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}
int binarySearch(const int arr[], int size, int value)
{
    int first = 0;
    int last = size;
    int middle;
    int position = -1;
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if (arr[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
           

           void selectionSort(int array[], int size)
{
    int minIndex, minValue;
    
    
    for(int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for(int index = start + 1; index <size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}



///////////
int linearSor(const int arr[], int size, int number)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        if(arr[index] == number)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
    
}



