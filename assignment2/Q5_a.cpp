#include <iostream>
using namespace std;

//only diagonal matrix
int main()
{
    int arr[3][3] = {{2,0,0},{0,5,0},{0,0,8}};
    int comp[3];
    for(int i = 0;i<3;i++)
    {
        comp[i] = arr[i][i];
    }
    cout<<"compressed:"<<endl;
    for(int i = 0;i<3;i++)
    {
        cout<<comp[i]<<"\t";
    }
    cout<<endl;
    int uncomp[3][3] = {0};
    for(int i = 0;i<3;i++)
    {
        uncomp[i][i] = comp[i];
    }
    cout<<"uncompressed:"<<endl;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            cout<<uncomp[i][j]<<"\t";
        }
        cout<<endl;
    }
}