// Maximize Distance to Closest Person
/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

Example 3:

Input: seats = [0,1]
Output: 1

*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int e=0,res=0;
        int idx1=-1,idx2=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                e=0;
                if(idx1==-1)idx1=i;
                idx2=i;
            }else{
                e++;
                res=max(res,(e+1)/2);
            }
        }
        res=max({res,idx1,n-1-idx2});
        return res;
    }
};