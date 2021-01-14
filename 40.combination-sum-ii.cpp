/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (49.65%)
 * Likes:    2374
 * Dislikes: 84
 * Total Accepted:    378K
 * Total Submissions: 758.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    void get_soln(vector<int>& candidates,int curr, int target,int curr_sum,vector<int> temp,set<vector<int>> &ans){
        // base cases
        if(curr_sum==target){
            ans.insert(temp);
            return;
        }
        if(curr_sum>target){
            return;
        }
        if(curr>=candidates.size()){
            return;
        }
        // recursive cases
        // include
        temp.push_back(candidates[curr]);
        get_soln(candidates,curr+1,target,curr_sum+candidates[curr],temp,ans);
        // exclude
        temp.pop_back();
        while(curr+1<candidates.size()&&candidates[curr]==candidates[curr+1]){
            curr=curr+1;
        }
        get_soln(candidates,curr+1,target,curr_sum,temp,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        vector<int> temp;
        get_soln(candidates,0,target,0,temp,ans);
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }

};
// @lc code=end

