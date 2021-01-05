/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.46%)
 * Likes:    6384
 * Dislikes: 262
 * Total Accepted:    1.2M
 * Total Submissions: 3.1M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "{[]}"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// we'll do this using stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                if(s[i]==')'){
                    if(top=='('){
                        st.pop();
                    }else{
                        return false;
                    }
                }else if(s[i]==']'){
                    if(top=='['){
                        st.pop();
                    }else{
                        return false;
                    }
                }else if(s[i]=='}'){
                    if(top=='{'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
// @lc code=end

