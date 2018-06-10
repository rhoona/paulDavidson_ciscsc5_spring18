/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 13, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
float kineticEnergy(float, float, float &);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    //ke = kenetic energy
    // m = objects mass
    // v is velcoity in mp2
    //
    float mass,velocity,ke;
            
    
    cout<<"Enter (1) The objects Mass (2) The objects Velocity\n ";
    cin>>mass>>velocity;
    
    kineticEnergy( mass, velocity,ke);
    cout<<ke;
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}

float kineticEnergy(float getMass, float getVelocity, float & ke)
{
    cout<<"the results are: ";
    
    ke=0.5*(getMass*(getVelocity*getVelocity));
  
    
}