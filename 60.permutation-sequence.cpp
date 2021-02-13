/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Hard (39.09%)
 * Likes:    2049
 * Dislikes: 355
 * Total Accepted:    219.3K
 * Total Submissions: 557.7K
 * Testcase Example:  '3\n3'
 *
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * 
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 * Example 3:
 * Input: n = 3, k = 1
 * Output: "123"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 1 <= k <= n!
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool solve(int n,int k,string &s,int index,int &leafnum,int *dp){
        if(leafnum==k&&index>=n){
            return true;
        }
        if(index>=n){
            // cout<<s<<" ";
            leafnum++;
            return false;
        }
        for(int i=1;i<=n;i++){
            if(dp[i]==0){
                s.push_back(char(i)+48);
                dp[i]=1;
                if(solve(n,k,s,index+1,leafnum,dp)){
                    return true;
                }
                s.pop_back();
                dp[i]=0;
            }
        }
        return false;
    }
    string getPermutation(int n, int k) {
        // in this we'll do a dfs and print the kth leaf from left to right
        string s;
        int leafnum=1;
        int *dp=new int[n+1]{};
        solve(n,k,s,0,leafnum,dp);
        return s;
    }
};
// @lc code=end

