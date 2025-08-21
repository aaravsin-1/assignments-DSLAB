#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "\nEnter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "\nEnter the elements of the array in a sorted manner:\n";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n-1; i++){
        int diff = arr[i+1]-arr[i];
        if(diff > 1) {
            for(int j=1; j<diff; j++){
                cout << "\nThe missing number is " << arr[i]+j << " between " << arr[i] << " and " << arr[i+1] <<".\n";
            }
        }
    }
    return 0;
}