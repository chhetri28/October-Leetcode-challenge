// Repeated DNA Sequences
/*
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

 

Constraints:

    0 <= s.length <= 105
    s[i] is 'A', 'C', 'G', or 'T'.



*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        map<string,int>mp;
        if(s.length()<10){
            return res;
        }
        for(int i=0;i<=s.length()-10;i++){
            mp[s.substr(i,10)]++;
        }
        for(auto x:mp){
            if(x.second>1){
                res.push_back(x.first);
            }
        }
        return res;
    }
};