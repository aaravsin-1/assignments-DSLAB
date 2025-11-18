#include <iostream>
using namespace std;
void max_heapify(int heap[], int i, int n)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= n && heap[left] > heap[largest])
        largest = left;

    if (right <= n && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        max_heapify(heap, largest, n);
    }
}
int main()
{
    int arr[] = {0, 4, 14, 7, 2, 8, 1};       // 1-indexed heap
    int n = sizeof(arr) / sizeof(arr[0]); // subtract 1 for index 0

    max_heapify(arr, 1, n-1);

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
