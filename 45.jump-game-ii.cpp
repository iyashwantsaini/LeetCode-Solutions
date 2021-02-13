/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (31.19%)
 * Likes:    3632
 * Dislikes: 168
 * Total Accepted:    312.9K
 * Total Submissions: 997.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * You can assume that you can always reach the last index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // DP O(n^2 approach)
    // int jump(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1){
    //         return 0;
    //     }
    //     int *dp=new int[n+1]{};

    //     dp[n-1]=0;
    //     for(int i=n-2;i>=0;i--){
    //         if(dp[i]==0){
    //             continue;
    //         }
    //         for(int j=i+1;j<n&&j<dp[i];j++){
    //             if(j==n-1){
    //                 dp[i]=1;
    //                 break;
    //             }else{
    //                 if(dp[j]==0){
    //                     continue;
    //                 }else{
    //                     if(dp[i]==0){
    //                         dp[i]=dp[j]+1;
    //                     }else{
    //                         dp[i]=min(dp[i],dp[j]);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     int ans=dp[0];
    //     delete dp;
    //     return ans;
    // }

    // greedy solution
    // O(n) => https://www.youtube.com/watch?v=a9r98S-pDvk
    int jump(vector<int>& nums) {
        int currReach=0;
        int currMax=0;
        int jumps=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(i+nums[i]>currMax){
                currMax=i+nums[i];
            }
            if(i==currReach){
                jumps++;
                currReach=currMax;
            }
        }
        return jumps;
    }
};
// @lc code=end

