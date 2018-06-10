/*
 * Dr. Mark E. Lehr
 * Purpose:  Dynamic 2-D Array Solution with different # of columns per row
 * Inputs-> n = Number of Rows
 *          q = Number of Queries
 *          k = Columns for that particular row
 */
#include <iostream>
using namespace std;


int main() {
    //Initialize the Array size by row, input the queries
    int n,q;
    cin>>n>>q;
    int **a=new int*[n];
    //Allocate column size by row, then read in data
    for(int i=0;i<n;i++){
        int k;
        cin>>k;cin.ignore();
        a[i]=new int[k];
        for(int j=0;j<k;j++){
            cin>>a[i][j];cin.ignore();
        }
    }
    //Answer the queries by output row-col cell data
    for(int i=0;i<q;i++){
        int row,col;
        cin>>row>>col;
        cout<<a[row][col]<<endl;
    }
    //Recover memory
    for(int i=0;i<n;i++){
        delete []a[i];
    }
    delete []a;
    //Exit the program
    return 0;
}