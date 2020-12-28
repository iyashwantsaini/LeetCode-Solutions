/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int expand_out(string s, int left, int right, int lens)
    {
        int l=left;
        int r=right;
        while(l>=0&&r<lens&&s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s)
    {
        int lens = s.length();
        if(lens<1){
            return "";
        }

        int start=0;
        int end=0;
        // expand outwards from every element's index
        for (int i = 0; i < lens; i++)
        {
            int forodd_ = expand_out(s, i, i, lens);
            int foreven_ = expand_out(s, i, i + 1, lens);
            int len=max(forodd_,foreven_);
            if(len>(end-start)){
                start=i-(len-1)/2;
                end=i+(len/2);
            }
        }
        return s.substr(start,end+1);
    }
};
// @lc code=end
