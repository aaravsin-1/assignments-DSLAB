#include <iostream>
using namespace std;
char a[] = "one";
char b[]  = "two";
char c[sizeof(a)+ sizeof(b)-1];

void concat()
{
    int i = 0;
    int j = 0;
    for(i = 0;i<sizeof(a);i++)
    {
        c[i] = a[i];
    }
    int k = 0;
    for(j = i;j<sizeof(c);j++)
    {
        c[j] = b[k];
        k++;
    }
    c[j] = '\0';
}
int main()
{
    concat();
    for(int i = 0;i<sizeof(c);i++)
    {
        cout<<c[i];
    }
}