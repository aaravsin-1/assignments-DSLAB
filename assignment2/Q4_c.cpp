#include <iostream>
using namespace std;

char a[] = "aarav";
int l = sizeof(a) - 1; 

void del(int index)
{
    for (int i = index; i < l - 1; i++)
    {
        a[i] = a[i + 1];
    }
    l--;
    a[l] = '\0';
}

int main()
{
    for (int i = 0; i < l; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            del(i);
            i--; 
        }
    }
    cout << a;
}
