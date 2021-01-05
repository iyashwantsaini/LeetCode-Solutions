/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (64.56%)
 * Likes:    6752
 * Dislikes: 307
 * Total Accepted:    660.1K
 * Total Submissions: 1M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// at each step => either open or close a bracket
// we cannot open more than n
// we cannot close a bracket unless some bracket is open

class Solution {
public:

    void generate_paran(string s,int open,int closed,int n,vector<string> &ans){
        // base case    
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        // recursive cases
        // put open
        if(open<n){
            generate_paran(s+"(",open+1,closed,n,ans);
        }
        // put closed
        if(open>closed){
            generate_paran(s+")",open,closed+1,n,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // base cases
        if(n==1){
            ans.push_back("()");
            return ans;
        }
        // currently_open=0;
        // currently_closed=0;
        // current string =""
        generate_paran("",0,0,n,ans);
        return ans;
    }
};
// @lc code=end

