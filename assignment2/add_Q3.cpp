/*
WAP to String Anagrams  
Given two strings str1 and str2, determine if they form an anagram pair.  
Note: Two strings are considered anagrams if one string can be rearranged to form the other 
string. 
*/

#include <iostream>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if(s1.length() != s2.length()) return false;

    int freq[26] = {0}; // frequency array

    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i]-'a']++;  // count s1 characters
        freq[s2[i]-'a']--;  // subtract s2 characters
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) return false; // mismatch
    }

    return true;
}

int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    if(areAnagrams(s1, s2)) cout << "Anagrams" << endl;
    else cout << "Not anagrams" << endl;
}