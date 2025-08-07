//Code for matrix multiplication

#include <iostream>
using namespace std;

int main()
{
    int arr1[3][3];
    int arr2[3][3];

    int nrows_1 = sizeof(arr1) / sizeof(arr1[0]);       
    int ncols_1 = sizeof(arr1[0]) / sizeof(arr1[0][0]); 
    int nrows_2 = sizeof(arr2) / sizeof(arr2[0]);       
    int ncols_2 = sizeof(arr2[0]) / sizeof(arr2[0][0]); 

    int arr3[nrows_1][ncols_2];
    if (ncols_1 == nrows_2)
    {
        // Set values
        int val = 1;
        for (int i = 0; i < nrows_1; i++)
            for (int j = 0; j < ncols_1; j++)
                arr1[i][j] = val++;

        val = 1;
        for (int i = 0; i < nrows_2; i++)
            for (int j = 0; j < ncols_2; j++)
                arr2[i][j] = val++;

        // Matrix multiplication
        for (int i = 0; i < nrows_1; i++)
        {
            for (int j = 0; j < ncols_2; j++)
            {
                arr3[i][j] = 0;
                for (int k = 0; k < ncols_1; k++)
                {
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        cout << "Resulting Matrix"<<endl;
        for (int i = 0; i < nrows_1; i++)
        {
            for (int j = 0; j < ncols_2; j++)
            {
                cout << arr3[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "MULTIPLICATION NOT POSSIBLE";
    }
    return 0;
}
