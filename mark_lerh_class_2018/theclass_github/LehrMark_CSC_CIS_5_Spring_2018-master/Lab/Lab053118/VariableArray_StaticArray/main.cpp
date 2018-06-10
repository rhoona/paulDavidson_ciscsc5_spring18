/*
 * Dr. Mark E. Lehr
 * Purpose:  Static 1-D Array Solution with different # of columns per row
 * Inputs-> n = Number of Rows
 *          q = Number of Queries
 *          k = Columns for that particular row
 */
#include <iostream>
using namespace std;


int main() {
    //Declare variables and arrays
    const int MAX=50000;//Expand array by 10 to solve for hacker rank
    const int ROW=30000;//Expand array by 10 to solve for hacker rank
    int a[MAX]={};//1-D Array
    int rc[ROW]={};//1-D Array where each row will start in the 1-D array above
    int n,q,cnt,k;
    //Read in the data
    cin>>n>>q;//#Rows and #Queries
    //Read in the entire array
    cnt=0;//Start the array count at 0
    //Store the entire array
    for(int i=0;i<n;i++){
        cin>>k;cin.ignore();
        rc[i]=cnt;//Key, where each row starts in the 1-D array
        a[cnt++]=k;
        for(int j=0;j<k;j++){
            cin>>a[cnt++];cin.ignore();
        }
    }
    //Now answer the queries
    int row,col;
    for(int i=0;i<q;i++){
        cin>>row>>col;
        //Given you have where each row starts and each row contains the size of the columns
        cout<<a[rc[row]+col+1]<<endl;
    }
    return 0;
}