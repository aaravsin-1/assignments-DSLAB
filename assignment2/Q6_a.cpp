#include <iostream>
using namespace std;

int n = 6;
int sparse[6][6] = {
    {0, 0, 5, 0, 0, 0},
    {0, 0, 0, 0, 8, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0}
};

void transposeArray(int s, int arr[][3])
{
    int trans[3][100]; // 3 rows, s columns (max 100 non-zeros for safety)
    for (int i = 0; i < 3; i++) // 3 new rows
    {
        for (int j = 0; j < s; j++) // s new columns
        {
            trans[i][j] = arr[j][i]; // swap indices
        }
    }

    cout << "\nFull Transposed Array:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int size = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (sparse[i][j] != 0)
                size++;

    int trip[size][3];
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (sparse[i][j] != 0)
            {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = sparse[i][j];
                k++;
            }

    cout << "Original Triplet Array:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << trip[i][j] << " ";
        }
        cout << endl;
    }

    transposeArray(size, trip);
}
