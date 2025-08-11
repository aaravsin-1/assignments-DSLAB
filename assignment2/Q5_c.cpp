#include <iostream>
using namespace std;
int main()
{
    int n = 3;
    int arr[n][n] = {{1,0,0},{1,1,0},{1,1,1}};
    int size = n*(n+1)/2;
    int comp[size];
    int k = 0;
    for(int i = 0;i<3;i++)//compressing.
    {
        for(int j = 0;j<=i;j++)
        {
            comp[k] = arr[i][j];
            k++;
        }
    }
    cout << "Compressed: ";
    for (int i = 0; i < size; i++) {
        cout << comp[i] << " ";
    }
    cout << endl;
}