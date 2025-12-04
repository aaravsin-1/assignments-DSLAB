#include <iostream>
#include "pretty_tree_printer.hpp"
using namespace std;

void max_heapify(int *heap, int i, int n)
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

void build_max_heap(int *heap, int n)
{
    // heap is 1-indexed, elements at 1..n
    for (int i = n / 2; i >= 1; i--)
        max_heapify(heap, i, n);
}

int main()
{
    // Allocate heap array (11 elements: index 0 unused)
    int *heap = new int[11];

    // Store values (index 0 = unused)
    int temp[11] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for (int i = 0; i < 11; i++)
        heap[i] = temp[i];

    int n = 10;   // number of heap elements

    build_max_heap(heap, n);

    // Print the heap array
    for (int i = 1; i <= n; i++)
        cout << heap[i] << " ";
    cout << endl;

    print_pretty_heap(heap, n);  // note: must modify pretty printer if needed

    delete[] heap;  // free memory
    cout << endl;

    return 0;
}
