#include <iostream>
using namespace std;
int arr[] = {1,2,2,2,3,4,4,4,5,5,5,6,6,6,6,7,7,7};
int main()
{
    int index = 4;
    int size = 18;
    for(int i = index;i<size-1;i++)
    {
        arr[i] = arr[i+1];
    }
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<",";
    }
}