// Remove Duplicate Letters
/*

Given a string s, remove duplicate letters so that every letter appears once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        vector<bool> visited(26, false);
        vector<int> dict(26, 0);

        for(auto it: s)     dict[it-'a'] ++;

        for(int i=0; i<s.length(); i++) {
            dict[s[i]-'a'] --;
            if(visited[s[i]-'a']) continue;
            while ( res.size() and res.back() > s[i] and dict[res.back() -'a'] ) {
                visited[res.back()-'a'] = false;
                res.pop_back();
            }
            res += s[i];
            visited[s[i]-'a'] = true;
        }
        return res;
    }
};