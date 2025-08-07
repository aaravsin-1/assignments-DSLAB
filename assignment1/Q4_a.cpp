//Code to reverse an array

#include <iostream>
using namespace std;
int arr[] = {1,2,3,4,5,6,7,8,9,10};
int l = sizeof(arr)/sizeof(arr[0]);
int main()
{
    cout<<"Original Array"<<endl;
    for(int i = 0;i<l;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
    for(int i = 0;i<l/2;i++)
    {
        int temp = arr[i];
        arr[i] = arr[l-i-1];
        arr[l-i-1] = temp;
    }
    cout<<"Reversed Array"<<endl;
    for(int i = 0;i<l;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
