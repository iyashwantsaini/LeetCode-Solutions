/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.92%)
 * Likes:    3466
 * Dislikes: 2062
 * Total Accepted:    904.3K
 * Total Submissions: 2.5M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
 * 
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// we can solve this problem using a character trie
// but due to small size we'll just use simple O(n^2) method

// node for the trie
// class node{
//     public:
//         char data;
//         node *child;
//         node(){
//             data=NULL;
//             child=new node[26];
//         }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];
        
        string ans="";
        // for every char of the first find if next all are equal or not
        string first=strs[0];
        // for each char of first
        for(int i=0;i<first.length();i++){
            int flag=0;
            // go to that character of all others
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=first[i]){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                return ans;
            }else{
                ans+=first[i];
            }

        }
        return ans;
    }
};
// @lc code=end

