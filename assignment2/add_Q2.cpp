/*
WAP to String Split Challenge 
You are given a string consisting of lowercase English alphabets. Your task is to determine if 
it's possible to split this string into three non-empty parts (substrings) where one of these 
parts is a substring of both remaining parts 
*/

//basically check for duplicate characters if exist then yes string can be split
#include <iostream>
using namespace std;

int main()
{
    string s;
    cout<<"Enter a string:";
    cin>>s;
    int n = s.length();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(s[i] == s[j])
            {
                cout<<"possible to split"<<endl;
                return 0;
            }
        }
    }
    cout<<"impossible to split"<<endl;
    return 0;
}