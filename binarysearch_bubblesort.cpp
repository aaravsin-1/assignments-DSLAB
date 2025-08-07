#include <iostream>
using namespace std;
int *arr;
int s = 0;
void input()
{
    cout<<"Please input the size:"<<endl;
    cin>>s;
    cout<<s<<endl;
    arr = new int[s];
    cout<<"Please enter the elements:"<<endl;
    for(int h = 0;h<s;h++)
    {
        cin>>arr[h];
    }
}
int binary_Search(int n)
{
int low = 0;
int high = s-1;

while(low<=high)
{
int mid = (low + high)/2;
if(arr[mid] == n)
{
return mid;
}
if(n>arr[mid])
{
low = mid+1;
}
if(n<arr[mid])
{
high = mid-1;
}
}
return -1;

}
void display()
{
for(int i =0;i<s;i++)
{
cout<<arr[i]<<",";
}
cout<<endl;
}
void b_sort(int n)//Bubble Sort
{
    int l = s;
    {
        for(int i = 0;i<l;i++)
   {
   for(int j = 0;j<l-1-i;j++)
   {
   if(arr[j]>arr[j+1])
   {
    n = 0;
    int temp = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
   }
   if(n==1)
   {
    return;
}
   }
   }
    }
}
int main()
{
    input();
    display();
b_sort(1);
cout<<"ARRAY :"<<endl;
display();
int numb = 0;
cout<<"Please enter the number you want to find:"<<endl;
cin>>numb ;

int index = binary_Search(numb);
if(index == -1)
{
cout<<"Element not found"<<endl;
}
else
{
cout<<"Element found at index: "<<index<<endl;
}
delete arr;
}