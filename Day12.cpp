//  Buddy Strings
/*
Given two strings A and B of lowercase letters, 
return true if you can swap two letters in A so the result is equal to B, 
otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such 
that i != j and swapping the characters at A[i] and A[j].
For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.

Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.

Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.

Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:

Input: A = "", B = "aa"
Output: false

*/

class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.length()!=b.length())return false;
        if(a==b){
            set<char>st;
            for(auto x:a){
                st.insert(x);
            }
            if(st.size()<a.size())return true;
            else return false;
        }
        vector<int>res;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i])res.push_back(i);
        }
        if(res.size()==2 and 
          a[res[0]]==b[res[1]] and 
          b[res[0]]==a[res[1]])return true;
        else return false;
    }
};
