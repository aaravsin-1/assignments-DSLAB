#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int arr[5][5] = {
        {1,  2,  3,  4,  5},
        {2,  6,  7,  8,  9},
        {3,  7, 10, 11, 12},
        {4,  8, 11, 13, 14},
        {5,  9, 12, 14, 15}
    };

    //lower triangle
    int size = n * (n + 1) / 2;
    int comp[size];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            comp[k++] = arr[i][j];
        }
    }

    cout << "Compressed: ";
    for (int i = 0; i < size; i++) {
        cout << comp[i] << " ";
    }
    cout << endl;
    int uncomp[n][n];
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            uncomp[i][j] = comp[k];
            uncomp[j][i] = comp[k];
            k++;
        }
    }

    cout << "Uncompressed:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << uncomp[i][j] << "\t";
        }
        cout << endl;
    }
}
