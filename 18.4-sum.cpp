/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (34.47%)
 * Likes:    2762
 * Dislikes: 382
 * Total Accepted:    378.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Notice that the solution set must not contain duplicate quadruplets.
 * 
 * 
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Example 2:
 * Input: nums = [], target = 0
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// methos 1 => 3 pointers + binary search => O(n^3*log(n))
// method 2 => 2 pointers + (2 pointers on front & back)
//          => O(n^3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<vector<int>> ans;

        if(n<=3){
            return ans;
        }
        if(n==4){
            if((nums[0]+nums[1]+nums[2]+nums[3])==target){
                ans.push_back({nums[0],nums[1],nums[2],nums[3]});
                return ans;
            }
            return ans;
        }

        for(int i=0;i<n-3;i++){
            // avoid repetitions
            if(i==0||nums[i]>nums[i-1]){
                for(int j=i+1;j<n-2;j++){
                    // avoid repetitions
                    if(j==i+1||nums[j]>nums[j-1]){
                        int k=j+1;
                        int l=n-1;
                        while(k<l){
                            int val=nums[i]+nums[j]+nums[k]+nums[l];
                            if(val==target){
                                ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                            }
                            // avoid repetitions
                            if(val<target){
                                int k_val=nums[k];
                                while(k<l&&nums[k]==k_val){
                                    k++;
                                }
                            }else{
                                int l_val=nums[l];
                                while(k<l&&nums[l]==l_val){
                                    l--;
                                }
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

