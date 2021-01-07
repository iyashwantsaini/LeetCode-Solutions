/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (34.96%)
 * Likes:    2066
 * Dislikes: 2183
 * Total Accepted:    792.2K
 * Total Submissions: 2.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * 
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Example 3:
 * Input: haystack = "", needle = ""
 * Output: 0
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= haystack.length, needle.length <= 5 * 10^4
 * haystack and needle consist of only lower-case English characters.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int nh=haystack.length();
        int nn=needle.length();
        if(nn==0){
            return 0;
        }
        if(nn==1){
            for(int i=0;i<nh;i++){
                if(haystack[i]==needle[0]){
                    return i;
                }
            }
            return -1;
        }
        // we only need to go upto (len of haystack - len of needle)
        for(int i=0;i<nh-nn+1;i++){
            // may be possible
            // check if (curr i + len of needle) == end char of needle
            int check=i+nn-1;
            if(haystack[i]==needle[0]&&haystack[check]==needle[nn-1]){
                int x=1;
                for(int j=i+1;j<check&&j<nh;j++){
                    if(haystack[j]!=needle[x]){
                        break;
                    }else{
                        x++;
                    }
                }
                if(x==nn-1){
                    return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

