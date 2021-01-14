/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (33.28%)
 * Likes:    4957
 * Dislikes: 911
 * Total Accepted:    429.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums, find the smallest missing positive
 * integer.
 * 
 * Follow up: Could you implement an algorithm that runs in O(n) time and uses
 * constant extra space.?
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 300
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 1;
        }
        // find minmax
        map<int,int> m;
        int maxnum=INT_MIN;
        int minnum=INT_MAX;
        for(int i=0;i<n;i++){
            m[nums[i]]=1;
            if(nums[i]>maxnum){
                maxnum=nums[i];
            }
            if(nums[i]<minnum){
                minnum=nums[i];
            }
        }
        // find min positive
        if(maxnum<=0){
            return 1;
        }
        if(minnum<=0){
            minnum=1;
        }
        if(minnum>1){
            return 1;
        }
        for(int i=minnum;i<=maxnum;i++){
            if(m[i]==0){
                return i;
            }
        }
        return maxnum+1;
    }
};
// @lc code=end

