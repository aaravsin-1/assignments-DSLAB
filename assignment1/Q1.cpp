// Code for menu driven program for arrays
#include <iostream>
using namespace std;

int main()
{
    int arr[100]; 
    int n = 0;   
    int choice;

    do
    {
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            break;

        case 2: 
            if (n == 0)
            {
                cout << "Array is empty.\n";
            }
            else
            {
                cout << "Array elements: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            break;

        case 3: 
            if (n >= 100)
            {
                cout << "Array is full, cannot insert.\n";
                break;
            }
            int pos, val;
            cout << "Enter position to insert (1 to " << n + 1 << "): ";
            cin >> pos;
            if (pos < 1 || pos > n + 1)
            {
                cout << "Invalid position.\n";
                break;
            }
            cout << "Enter value to insert: ";
            cin >> val;
            
            for (int i = n; i >= pos; i--)
                arr[i] = arr[i - 1];
            arr[pos - 1] = val;
            n++;
            cout << "Element inserted.\n";
            break;

        case 4: 
            if (n == 0)
            {
                cout << "Array is empty, cannot delete.\n";
                break;
            }
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;
            if (pos < 1 || pos > n)
            {
                cout << "Invalid position.\n";
                break;
            }
            
            for (int i = pos - 1; i < n - 1; i++)
                arr[i] = arr[i + 1];
            n--;
            cout << "Element deleted.\n";
            break;

        case 5: 
            if (n == 0)
            {
                cout << "Array is empty.\n";
                break;
            }
            cout << "Enter value to search: ";
            cin >> val;
            int found;
            found = -1;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == val)
                {
                    found = i + 1; 
                    break;
                }
            }
            if (found != -1)
                cout << "Element found at position " << found << ".\n";
            else
                cout << "Element not found.\n";
            break;

        case 6: 
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice, try again.\n";
        }

    } while (choice != 6);

    return 0;
}