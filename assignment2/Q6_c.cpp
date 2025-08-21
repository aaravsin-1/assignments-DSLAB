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

int multiplyTriplets(int trip1[][3], int size1, int trip2[][3], int size2, int result[][3])
{
    int k = 0;

    for (int i = 0; i < size1; i++)
    {
        int rowA = trip1[i][0];
        int colA = trip1[i][1];
        int valA = trip1[i][2];

        for (int j = 0; j < size2; j++)
        {
            int rowB = trip2[j][0];
            int colB = trip2[j][1];
            int valB = trip2[j][2];

            if (colA == rowB)
            {

                bool found = false;
                for (int r = 0; r < k; r++)//check if already exists
                {
                    if (result[r][0] == rowA && result[r][1] == colB)
                    {
                        result[r][2] += valA * valB;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    result[k][0] = rowA;
                    result[k][1] = colB;
                    result[k][2] = valA * valB;
                    k++;
                }
            }
        }
    }
    return k;
}

int main()
{
    int trip1[36][3], trip2[36][3];
    int size1 = convertToTriplet(sparse1, trip1);
    int size2 = convertToTriplet(sparse2, trip2);

    int result[36][3];
    int resultSize = multiplyTriplets(trip1, size1, trip2, size2, result);

    cout << "Resultant Triplet Array after Multiplication:\n";
    for (int i = 0; i < resultSize; i++)
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;

    return 0;
}
