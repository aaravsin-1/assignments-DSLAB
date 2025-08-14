#include <iostream>
using namespace std;

int n = 6;

int sparse1[6][6] = {
    {0, 0, 5, 0, 0, 0},
    {0, 0, 0, 0, 8, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0}};

int sparse2[6][6] = {
    {0, 0, 0, 0, 0, 2},
    {0, 0, 0, 4, 0, 0},
    {0, 0, 7, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 9, 0, 0, 0, 0}};

int convertToTriplet(int mat[][6], int trip[][3])
{
    int size = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
            {
                trip[size][0] = i;
                trip[size][1] = j;
                trip[size][2] = mat[i][j];
                size++;
            }
    return size;
}

int addTriplets(int trip1[][3], int size1, int trip2[][3], int size2, int result[][3])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (trip1[i][0] < trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] < trip2[j][1]))
        {
            result[k][0] = trip1[i][0];
            result[k][1] = trip1[i][1];
            result[k][2] = trip1[i][2];
            i++;
            k++;
        }
        else if (trip1[i][0] > trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] > trip2[j][1]))
        {
            result[k][0] = trip2[j][0];
            result[k][1] = trip2[j][1];
            result[k][2] = trip2[j][2];
            j++;
            k++;
        }
        else
        {

            result[k][0] = trip1[i][0];
            result[k][1] = trip1[i][1];
            result[k][2] = trip1[i][2] + trip2[j][2];
            i++;
            j++;
            k++;
        }
    }

    while (i < size1)
    {
        result[k][0] = trip1[i][0];
        result[k][1] = trip1[i][1];
        result[k][2] = trip1[i][2];
        i++;
        k++;
    }

    while (j < size2)
    {
        result[k][0] = trip2[j][0];
        result[k][1] = trip2[j][1];
        result[k][2] = trip2[j][2];
        j++;
        k++;
    }

    return k;
}

int main()
{
    int trip1[36][3], trip2[36][3];
    int size1 = convertToTriplet(sparse1, trip1);
    int size2 = convertToTriplet(sparse2, trip2);

    int result[72][3];
    int resultSize = addTriplets(trip1, size1, trip2, size2, result);

    cout << "Resultant Triplet Array after Addition:\n";
    for (int i = 0; i < resultSize; i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }

    return 0;
}
