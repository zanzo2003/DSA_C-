#include<iostream>

using namespace std;

int main(){
    // This files contains 2D arrays and some of the basic operations on it.
    /* 2D array stands for 2 Dimentional array and has 2 dimentions unlike standard array which has 1D
     They are represented are matrics and are basically array inside another array egs:- 
     [ [ 1, 2, 3 ],
       [ 3, 4, 4 ],
       [ 6, 3, 5 ] ]. 
    This is a standard way of representing a 2D array.  */


    // this is one of the ways to initialize a 2D array. int - data type, arr - name of the array
    // followed by the [rows][coloumns]. Size is rows x coloumns. Indexing same as 1D array.

    int arr[3][3] = {{1,2,3},       
                     {5,7,2},
                     {9,6,3}};

    // to access a element in a 2D array we have to know its row no and coloumn no using which we can acccess
    // the element. egs :-
    
    cout<<arr[1][2]<<endl;   

    // to traverse in a 2D array we will use for loops. egs:-

    for (int rows = 0; rows < 3; rows++){ 
        for(int cols = 0; cols<3; cols++){  // this is row major traversing, in coloumn major we will start
            cout<<arr[rows][cols]<<" ";          // with the coloumns instead of rows.
        } 
        cout<<endl;
    }

    //Matrix addition

    int a1[2][2] = {{2,5},
                    {3,9}};
    int a2[2][2] = {{50,50},
                    {50,50}};

    int sum[2][2];

    for(int i=0; i<2; i++)
    {                                    // adding corresponding elements and storing it in another matrix.
        for(int j=0; j<2; j++){
            sum[i][j] = a1[i][j]+a2[i][j];
        }
    }

    for (int rows = 0; rows < 2; rows++){ 
        for(int cols = 0; cols<2; cols++){  // traversing through sum.
            cout<<sum[rows][cols]<<" ";          
        } 
        cout<<endl;
    }

    return 0;
}