#include <iostream>
using namespace std;

class PriorityQueue
{
    int arr[100];
    int n;

public:
    PriorityQueue() { n = 0; }
    void push(int x)
    {
        arr[n] = x;
        int i = n;
        n++;
        while (i > 0 && arr[(i - 1) / 2] < arr[i])
        {
            int t = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = t;
            i = (i - 1) / 2;
        }
    }
    int top()
    {
        if (n == 0)
            return -1;
        return arr[0];
    }
    void pop()
    {
        if (n == 0)
            return;
        arr[0] = arr[n - 1];
        n--;
        int i = 0;
        while (2 * i + 1 < n)
        {
            int j = 2 * i + 1;
            if (j + 1 < n && arr[j + 1] > arr[j])
                j++;
            if (arr[i] >= arr[j])
                break;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i = j;
        }
    }
};

int main()
{
    PriorityQueue q;
    q.push(5);
    q.push(15);
    q.push(10);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    return 0;
}
