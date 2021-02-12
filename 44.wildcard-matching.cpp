/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (25.20%)
 * Likes:    2688
 * Dislikes: 127
 * Total Accepted:    286.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*' where:
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "adceb", p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "acdcb", p = "a*c?b"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length, p.length <= 2000
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '?' or '*'.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// DP table
// ROWS=s
// COLS=p

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        int **dp=new int*[m+1];
        for(int i=0;i<=m;i++){
            dp[i]=new int[n+1]{};
        }
        
        // first fill last row
        dp[m][n]=1; //all others 0
        
        // the fill last col
        for(int i=m-1;i>=0;i--){
            if(p[i]=='*'){
                dp[i][n]=dp[i+1][n];
            }
            // all others 0
        }

        // fill rest from bottom right to left
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(p[i]=='*'){
                    dp[i][j]=dp[i+1][j]||dp[i][j+1];
                }else if(p[i]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    if(p[i]==s[j]){
                        dp[i][j]=dp[i+1][j+1];
                    }
                    // else 0
                }
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

