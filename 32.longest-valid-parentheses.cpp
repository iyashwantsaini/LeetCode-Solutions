/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (29.02%)
 * Likes:    4340
 * Dislikes: 163
 * Total Accepted:    328.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        // maintain 2 stacks
        // 1=>charcter stack => ()
        // 2-> index stack to find max length valid ()
        int n=s.length();
        if(s.length()<=1){
            return 0;
        }
        stack<char> sc;
        stack<int> si;
        int maxlen=0;
        // keep -1 in index stack 
        si.push(-1);
        for(int i=0;i<n;i++){
            if(sc.empty()){
                if(s[i]=='('){
                    sc.push('(');
                    si.push(i);
                }else{
                    si.push(i);
                }
            }else{
                // time to pop
                if(s[i]==')'){
                    if(sc.top()=='('){
                        sc.pop();
                        si.pop();
                        int currmax=i-si.top();
                        if(currmax>maxlen){
                            maxlen=currmax;
                        }
                    }
                }else{
                    sc.push('(');
                    si.push(i);
                }
            }
        }
        return maxlen;
    }

    // some bugs
    // int longestValidParentheses(string s) {
    //     int maxlen=0;
    //     int n=s.length();
    //     stack<char> st;
    //     int templen=0;
    //     for(int i=0;i<n;i++){
    //         // if s empty
    //         if(st.empty()){
    //             if(s[i]==')'){
    //                 templen=0;
    //                 continue;
    //             }else{
    //                 st.push(s[i]);
    //             }
    //         }else{
    //             // if top
    //             if(s[i]==')'&&st.top()=='('){
    //                 templen+=2;
    //                 st.pop();
    //                 if((templen>maxlen)){
    //                     if(st.empty()||i!=n-1){
    //                         maxlen=templen;
    //                     }else{
    //                         maxlen=max(maxlen,templen-maxlen);
    //                     }
    //                 }
    //             }else{
    //                 st.push(s[i]);
    //             }
    //         }
    //     }
    //     return maxlen;
    // }
};
// @lc code=end

