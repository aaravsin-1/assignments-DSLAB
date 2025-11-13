#include <iostream>
using namespace std;

class HeapSorter
{
public:
    void heapify(int arr[], int n, int i, bool inc)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (inc)
        {
            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;
        }
        else
        {
            if (left < n && arr[left] < arr[largest])
                largest = left;
            if (right < n && arr[right] < arr[largest])
                largest = right;
        }
        if (largest != i)
        {
            int t = arr[i];
            arr[i] = arr[largest];
            arr[largest] = t;
            heapify(arr, n, largest, inc);
        }
    }
    void heapsort(int arr[], int n, bool inc)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, inc);
        for (int i = n - 1; i >= 0; i--)
        {
            int t = arr[0];
            arr[0] = arr[i];
            arr[i] = t;
            heapify(arr, i, 0, inc);
        }
    }
};

int main()
{
    int arr[] = {10, 5, 3, 7, 20};
    int n = 5;
    HeapSorter hs;
    hs.heapsort(arr, n, true);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    hs.heapsort(arr, n, false);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
