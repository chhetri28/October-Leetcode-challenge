// Minimum Domino Rotations For Equal Row
/*
In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.


If it cannot be done, return -1.

Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.

 

Constraints:

    2 <= A.length == B.length <= 2 * 104
    1 <= A[i], B[i] <= 6


*/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        auto top = A[0], bot = B[0], top1 = 0, bot1 = 0, top2 = 0, bot2 = 0;
        for (auto i = 0; i < A.size(); ++i) {
        if (A[i] != top && B[i] != top) top = 0;
        if (A[i] != bot && B[i] != bot) bot = 0;
        top1 += A[i] == top;
        bot1 += B[i] == top;
        top2 += A[i] == bot;
        bot2 += B[i] == bot;
      }
     return top || bot ? min(A.size() - max(top1, bot1), A.size() - max(top2, bot2)) : -1;
    }
};
