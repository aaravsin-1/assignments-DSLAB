#include <iostream>
using namespace std;

int n = 6;
int m = 6;
int sparse[6][6] = {
    {0, 0, 5, 0, 0, 0},
    {0, 0, 0, 0, 8, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0}};

int main()
{
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sparse[i][j] != 0)
                size++;
        }
    }
    int triplet[size][3];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sparse[i][j] != 0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sparse[i][j];
                k++;
            }
        }
    }
    int transpose_triplet[size][3];
    for (int i = 0; i < size; i++)
    {
        transpose_triplet[i][0] = triplet[i][1];
        transpose_triplet[i][1] = triplet[i][0];
        transpose_triplet[i][2] = triplet[i][2];
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (transpose_triplet[j][0] > transpose_triplet[j + 1][0] ||
                (transpose_triplet[j][0] == transpose_triplet[j + 1][0] && transpose_triplet[j][1] > transpose_triplet[j + 1][1]))
            {
                for (int t = 0; t < 3; t++)
                {
                    int temp = transpose_triplet[j][t];
                    transpose_triplet[j][t] = transpose_triplet[j + 1][t];
                    transpose_triplet[j + 1][t] = temp;
                }
            }
        }
    }
    cout << "\nTransposed triplet (sorted):" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << transpose_triplet[i][0] << " "<< transpose_triplet[i][1] << " "<< transpose_triplet[i][2] << endl;
    }

    return 0;
}