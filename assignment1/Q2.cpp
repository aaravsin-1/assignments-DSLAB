#include <iostream>
using namespace std;
int arr[] = {1,2,2,2,3,4,4,4,5,5,5,6,6,6,6,7,7,7};
int l = sizeof(arr)/sizeof(arr[0]);
void del(int index, int &len) {
    for (int i = index; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    len--;
}
int main() {
    int dup_ind[l];
    int count = 0;
    int unique = 0;
    int k = 0;
    for (int i = 0; i < l; i++) {
        unique++;
        int numb = arr[i];
        for (int j = i + 1; j < l; j++) {
            if (arr[j] == numb) {
                count++;
                dup_ind[k++] = j;
            }
        }
        i = i + count;
        count = 0;
    }
    cout << "Original array: ";
    for (int i = 0; i < l; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
    //reverse delete -- implemented because when we do direct deletion once we delete an element the next element goes into the current spot but we needed to delete the element before it.
    for (int i = l - unique - 1; i >= 0; i--) {
        del(dup_ind[i], l);
    }
    cout << "Final array: ";
    for (int i = 0; i < l; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
    return 0;
}
