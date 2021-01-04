/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.20%)
 * Likes:    2748
 * Dislikes: 159
 * Total Accepted:    534.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            // we'll not repeat ith
            if(i==0||nums[i]>nums[i-1]){

                // two pointers
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int val=nums[i]+nums[j]+nums[k];
                    
                    if(val==target){
                        return val;
                    }
                    
                    if(abs(val-target)<abs(closest)){
                        closest=target-val;
                    }
                    
                    if(val<target){
                        int j_val=nums[j];
                        while(j<k&&nums[j]==j_val){
                            j++;
                        }
                    }else{
                        int k_val=nums[k];
                        while(j<k&&nums[k]==k_val){
                            k--;
                        }
                    }
                
                }
            }

        }

        return target-closest;
    }
};
// @lc code=end

