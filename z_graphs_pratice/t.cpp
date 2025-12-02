#include <iostream>
using namespace std;

void parray(int *arr2)
{
    for(int i=0;i<sizeof(arr)/4;i++)
    {
        cout<<arr[i]<<",";
    }
    for(int i=0;i<sizeof(arr2[0])/4;i++)
    {
        for(int j = 0;j<sizeof(arr2[0][0])/4;j++)
        cout<<arr2[i]<<",";
    }
    cout<<endl;
}
int main()
{
    int B[2][3] = {0};
    parray(&B);

    return 0;
}