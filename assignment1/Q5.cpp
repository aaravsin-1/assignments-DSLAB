// code to find sum of every row and every column in a two-dimensional array
#include <iostream>
using namespace std;
const int rows = 3;
const int cols = 4;
int main()
{
    int arr[rows][cols];
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = k;
            k++;
        }
    }
    // Sum of each row
    for (int i = 0; i < rows; i++)
    {
        int rSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rSum += arr[i][j];
        }
        cout << "Sum of row " << i << " " << rSum << endl;
    }

    // Sum of each column
    for (int j = 0; j < cols; j++)
    {
        int cSum = 0;
        for (int i = 0; i < rows; i++)
        {
            cSum += arr[i][j];
        }
        cout << "Sum of column " << j << " " <<cSum<<endl;
    }
    return 0;
}