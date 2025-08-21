/*
Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the 
remaining elements to the right.  
Note that elements beyond the length of the original array are not written. Do the above 
modifications to the input array in place and do not return anything.
*/

#include <iostream>
using namespace std;
int arr[] = {1,2,3,4,5,6,2,8,9,10};
int n = sizeof(arr)/sizeof(arr[0]);
void shift_right(int index)
{
    for(int j = n-2;j>=index;j--)
    {
        arr[j+1] = arr[j];
    }
}
int main()
{
    int in = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==2)
        {
            if(i==n-1)
            {
                break;
            }
            shift_right(i+1);
            arr[i+1] = 2;
            i++;
        }
    }
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
}