/*
 * Dr. Mark E. Lehr
 * Purpose:  Dynamic 2-D Array Solution with different # of columns per row
 * Inputs-> n = Number of Rows
 *          q = Number of Queries
 *          k = Columns for that particular row
 */
#include <iostream>
#include <vector>
using namespace std;


int main() {
    //Declare the 2-D Vector and read in #rows and #queries
    vector< vector<int> > a;
    int n,q;
    cin>>n>>q;
    //Allocate Vector for each row and read in the # columns for that row
    for(int i=0;i<n;i++){
        a.push_back(vector<int>());
        int k;
        cin>>k;cin.ignore();
        //Read in data for each column
        for(int j=0;j<k;j++){
            int z;
            cin>>z;cin.ignore();
            a[i].push_back(z);
        }
    }
    //Output Query results
    for(int i=0;i<q;i++){
        int row,col;
        cin>>row>>col;
        cout<<a[row][col]<<endl;
    }

    return 0;
}