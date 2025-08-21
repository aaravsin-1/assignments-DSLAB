/*
WAP to String Split Challenge 
You are given a string consisting of lowercase English alphabets. Your task is to determine if 
it's possible to split this string into three non-empty parts (substrings) where one of these 
parts is a substring of both remaining parts 
*/

//basically check for duplicate characters if exist then yes string can be split
#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string str1, string str2) {
    return str2.find(str1) != string::npos;
}

bool checkPossible(string s) {
    int n = s.length();
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, j - i);
            string s3 = s.substr(j);

            if (isSubstring(s1, s2) && isSubstring(s1, s3)) return true;
            if (isSubstring(s2, s1) && isSubstring(s2, s3)) return true;
            if (isSubstring(s3, s1) && isSubstring(s3, s2)) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (checkPossible(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}