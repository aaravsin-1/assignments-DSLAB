/*
WAP to  Find two numbers in an array whose difference equals K. Given an array arr[] and a positive 
integer k, the task is to count all pairs (i, j) such that i < j and absolute value of (arr[i] - arr[j]) 
is equal to k. 
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            int value = arr[i] - arr[j];
            value = value>=0?value:(value*-1);
            if(value == k)
            {
                count++;
                cout<<arr[j]<<","<<arr[i]<<endl;
            }
        }
    }
    return 0;
}