//Binary Search

#include <iostream>
using namespace std;

int *arr;
int s = 0;

void input()
{
    cout << "Please input the size:" << endl;
    cin >> s;
    arr = new int[s];
    cout << "Please enter the elements:" << endl;
    for (int h = 0; h < s; h++)
    {
        cin >> arr[h];
    }
}

void display()
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}

void b_sort() // Optimized Bubble Sort
{
    for (int i = 0; i < s - 1; i++)
    {
        int sw = 0;
        for (int j = 0; j < s - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sw = 1;
            }
        }
        if (!sw)
            break; 
    }
}

int binary_Search(int n)
{
    int low = 0;
    int high = s - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == n)
        {
            return mid;
        }
        else if (n > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    input();
    b_sort();
    cout << "ARRAY :" << endl;
    display();

    int numb = 0;
    cout << "Please enter the number you want to find:" << endl;
    cin >> numb;

    int index = binary_Search(numb);
    if (index == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index: " << index << endl;
    }

    delete[] arr; 
    return 0;
}
