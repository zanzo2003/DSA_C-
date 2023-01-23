// In this file we will learn about binary search.
#include<iostream>
#include<bits/stdc++.h>
#include<array>

using namespace std;

/* Binary search is a searching techneque applied only on sorted arraylists. Time complexity is O(log N).
We repeatedly divide the the list into half until we find the object, if the list is undividable and the 
element is not found then we return -1. */

int binary_search(int n, int array[], int key){
    int s = 0;  // starting index of array
    int e = n-1;   // ending index of arrray
    while(e >= s){     //  will run only when ending > = starting
        int mid = (s+e)/2;     // middle index of array
        if( array[mid] == key){
            return array[mid];      
        }
        else if(key > mid){         // condtions.....
            s = mid + 1;         
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}


int main(){
    int arr[] = {1,2,4,8,9,11,45};
    int n = 7;
    cout<<binary_search(n, arr, 45)<<endl;     // searching last element
    cout<<binary_search(n, arr, 8)<<endl;     // searching middle element
    cout<<binary_search(n, arr, 98)<<endl;   // searching non exsistent element
    cout<<binary_search(n, arr, 1)<<endl;   // searching first element
    return 0;
}