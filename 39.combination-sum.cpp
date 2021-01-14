/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (58.47%)
 * Likes:    5194
 * Dislikes: 142
 * Total Accepted:    665.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * 
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    void get_soln(vector<int>& candidates,int curr, int target,int curr_sum,vector<int> temp,vector<vector<int>> &ans){
        // base cases
        if(curr_sum==target){
            ans.push_back(temp);
            return;
        }
        if(curr_sum>target){
            return;
        }
        if(curr==candidates.size()){
            return;
        }
        // recursive cases
        // include
        vector<int> a=temp;
        a.push_back(candidates[curr]);
        get_soln(candidates,curr,target,curr_sum+candidates[curr],a,ans);
        // exclude
        get_soln(candidates,curr+1,target,curr_sum,temp,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        get_soln(candidates,0,target,0,temp,ans);
        return ans;
    }
};
// @lc code=end

