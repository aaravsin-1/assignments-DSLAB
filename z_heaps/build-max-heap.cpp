#include <iostream>
#include <array>
#include "pretty_tree_printer.hpp"
using namespace std;

void max_heapify(array<int,11> &heap, int i, int n)
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

void build_max_heap(array<int,11> &heap)
{
    int n = 10;  // heap elements are from index 1..10

    for (int i = n/2; i >= 1; i--)
    {
        max_heapify(heap, i, n);
    }
}

int main()
{
    array<int,11> arr = {0,4,1,3,2,16,9,10,14,8,7};

    build_max_heap(arr);

    for (int i = 1; i <= 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    print_pretty_heap(arr, 10);
    cout<<endl;
    return 0;
}
