/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (27.61%)
 * Likes:    8954
 * Dislikes: 945
 * Total Accepted:    1.1M
 * Total Submissions: 4.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<=2){
            return ans;
        }

        for(int i=0;i<n-2;i++){

            // don't repeat a certain value in i
            // to avoid repetitions
            if(i==0||nums[i]>nums[i-1]){

                // 2 pointers => front,back
                int j=i+1;
                int k=n-1;

                while(j<k){
                    int val=nums[j]+nums[k]+nums[i];
                    if(val==0){
                        ans.push_back({nums[i],nums[j],nums[k]});
                    }

                    if(val<0){
                        int j_val=nums[j];
                        while(nums[j]==j_val&&j<k){
                            j++;
                        }
                    }else{
                        int k_val=nums[k];
                        while(nums[k]==k_val&&j<k){
                            k--;
                        }
                    }
                }

            }

        }
        return ans;
    }
};
// @lc code=end

