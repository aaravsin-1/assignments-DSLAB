#include <iostream>
using namespace std;

char a[] = "aarav";
void reverse()
{
    int l = sizeof(a)-1;
    for(int i = 0;i<l/2;i++)
    {
        char temp = a[i];
        a[i] = a[l-i-1];
        a[l-i-1] = temp;
    }   
}
int main()
{
    reverse();
    cout<<a;
}