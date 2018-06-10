/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on May 31st, 2018, 10:35 AM
 * Purpose:  Specification for the 2-D Array Structure
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

struct Array2D{
    int row;    //# of rows
    int col;    //# of cols
    int **data;  //Pointer to the dynamic array
};

#endif /* ARRAY2D_H */

