/*
Sort an array of 0s, 1s and 2s - Dutch National Flag Problem 
Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e., 
put all 0s first, then all 1s and all 2s in last. 
*/

#include <iostream>
using namespace std;

int arr[] = {0,1,1,1,2,2,2,0,0,0,0,1,1,1,2,2,2};

int main()
{
    int c_0 = 0, c_1 = 0, c_2 = 0;
    int n = sizeof(arr)/sizeof(int);
    int srted[n];
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) c_0++;
        else if(arr[i] == 1) c_1++;
        else c_2++;
    }
    int k = 0;
    for(int i = 0; i < c_0; i++) srted[k++] = 0;
    for(int i = 0; i < c_1; i++) srted[k++] = 1;
    for(int i = 0; i < c_2; i++) srted[k++] = 2;
    for(int i = 0; i < n; i++) cout << srted[i] << " ";
    cout << endl;
    return 0;
}