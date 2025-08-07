// Code to transpose a matrix

#include <iostream>
using namespace std;
const int ROWS = 2;
const int COLS = 3;
int arr[ROWS][COLS] = {{1, 2, 3},{4, 5, 6}};
int transposed[COLS][ROWS];
void transpose()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            transposed[j][i] = arr[i][j];
        }
    }
}
void displayOriginal()
{
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void displayTransposed()
{
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            cout << transposed[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    displayOriginal();
    transpose();
    displayTransposed();
    return 0;
}