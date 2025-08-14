//Bubble Sort
#include <iostream>
using namespace std;
int arr[] = {64,34,25,12,22,11,90};
int s = sizeof(arr)/sizeof(arr[0]);
int main() // Optimized Bubble Sort
{
    for (int i = 0; i < s - 1; i++)
    {
        int sw = 0;
        for (int j = 0; j < s - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sw = 1;
            }
        }
        if (!sw)
            break; 
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < s; i++) cout << arr[i] << " ";
    cout << endl;
}
