#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int arr[3][3] = {{1,2,3},{0,4,5},{0,0,6}};
    int size = n * (n + 1) / 2;
    int comp[size];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            comp[k++] = arr[i][j];
        }
    }

    cout << "Compressed: ";
    for (int i = 0; i < size; i++) {
        cout << comp[i] << " ";
    }
    cout << endl;
}
