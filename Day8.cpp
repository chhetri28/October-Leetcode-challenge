// Binary Search
/*

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

*/
class Solution {
  public:
  int search(vector<int>& nums, int target) {
      int mid,s=0,e=nums.size();
      while(s<=e){
          mid=s+(e-s)/2;
          if(nums[mid]==target)return mid;
          if(target<nums[mid])e=mid-1;
          else s=mid+1;
      }
      return -1;
  }
};
//Problem 2
// Two Sum III - Data structure design
/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
Example

Example 1:

add(1); add(3); add(5);
find(4) // return true
find(7) // return false


*/
class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    vector<int>res;
    bool issorted=true;
    void add(int number) {
        // write your code here
        res.push_back(number);
        issorted=false;
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
       if(!issorted){
           sort(res.begin(),res.end());
       }
       int s=0,e=res.size()-1;
       while(s<e){
           int sum=res[s]+res[e];
           if(sum==value){
               return true;
           }else if(sum<value){
               s++;
           }else{
               e--;
           }
       }
       return false;
    }
};