// C++ program to check if two strings
// are anagrams of each other
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
  
bool areAnagram(string str1, string str2)
{
    
    int count[256] = { 0 };
    int i;
  
    
    for (i = 0; str1[i] && str2[i]; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
  
    
    if (str1[i] || str2[i])
        return false;
  
    
    for (i = 0; i<256; i++)
        if (count[i])
            return false;
    return true;
}
  
int main()
{
    string str1 = "geeksforgeeks";
    string str2 = "forgeeksgeeks";
    
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";
  
    return 0;
}