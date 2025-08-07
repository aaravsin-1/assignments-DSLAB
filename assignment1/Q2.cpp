#include <iostream>
using namespace std;

int main()
{
    
    int arr[] = {1,2,2,2,3,4,4,4,5,5,5,6,6,6,6,7,7,7};
    
    int l = sizeof(arr)/sizeof(arr[0]);
    int dup_ind[l];
    int count = 0;
    int unique = 0;
    int k = 0;
    for(int i  = 0;i<l;i++)
    {
        unique++;
        int numb = arr[i];
        for(int j = i+1;j<l;j++)
        {
            if(arr[j]==numb)
            {
                count++;
                dup_ind[k] = j;
                k++;
            }
        }
        i = i+count;
        count = 0;
    }
    cout<<unique<<endl;
    for(int i = 0;i<l-unique;i++)
    {
        cout<<dup_ind[i]<<",";//duplicate indexes
    }
    return 0;
}