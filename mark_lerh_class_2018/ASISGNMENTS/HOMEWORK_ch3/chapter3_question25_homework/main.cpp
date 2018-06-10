/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on March 10, 2018, 9:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    
    string
         name,
         city,
         college,
         profession,
         petName,
         animalType;
    int age;
    
    cout<<"What is your name?"<<endl;
    cin>>name;
    
    cout<<"How old are you?"<<endl;
    cin>>age;
    
    cout<<"What city are you from?"<<endl;
    cin>>city;
    
    cout<<"What college do you attend?"<<endl;
    cin>>college;
    
    cout<<"What is your profession?"<<endl;
    cin>>profession;
    
    cout<<"What type of animal do you have?"<<endl;
    cin>>animalType;
    
    cout<<"What is your pet's name?"<<endl;
    cin>>petName;
    
    
    cout<<"there once was a person named "<<name<<"who lived in "<<city<<endl;
    cout<<"At the age of "<<age<<", "<<name<<" went to college at "<<college<<"."<<endl;
    cout<<name<<" graduated and went to work as a "<<profession<<". "<<"Then, "<<endl;
    cout<<name<<" adopted a(n) "<<animalType<<" named "<<petName<<". They both lived happily ever after!"<<endl;

    return 0;
}

