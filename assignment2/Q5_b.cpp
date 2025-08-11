#include <iostream>
using namespace std;
//compressing elements and keeping time complexity as O(3n)
int main()
{
    int n = 4;
    int a[n][n] = {{1,4,0,0},{3,4,1,0},{0,2,3,4},{0,0,1,3}};
    int comp_size = 3*n-2;
    int comp[comp_size] = {0};
    int k = 0;
    cout<<"compressed:"<<endl;
    for(int i = 0;i<n;i++)//diagonal elements
    {
        comp[k] = a[i][i];
        k++;
    }
    for(int i = 0;i<n-1;i++)//upper diagonal elements
    {
        comp[k] = a[i][i+1];
        k++;
    }
    for(int i = 1;i<n;i++)//lower diagonal elements
    {
        comp[k] = a[i][i-1];
        k++;
    }
    for(int i = 0;i<k;i++)//printing
    {
        cout<<comp[i]<<"\t";
    }
    cout<<endl;
    int uncomp[n][n];
    for (int i = 0; i < n; i++)//zeroing array
        for (int j = 0; j < n; j++)
            uncomp[i][j] = 0;
    k = 0;
    for(int i = 0;i<n;i++)//putting diagonal elements
    {
        uncomp[i][i] = comp[k];
        k++;
    }
    for(int i = 0;i<n-1;i++)//putting upper diagonal elements
    {
        uncomp[i][i+1] = comp[k];
        k++;
    }
    for(int i = 1;i<n;i++)//putting lower diagonal elements
    {
        uncomp[i][i-1] = comp[k];
        k++;
    }
    cout<<"uncompressed:"<<endl;
    for(int i = 0;i<n;i++)//printing
    {
        for(int j = 0;j<n;j++)
        {
            cout<<uncomp[i][j]<<"\t";
        }
        cout<<endl;
    }
}