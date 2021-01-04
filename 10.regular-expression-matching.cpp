/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // two pointers i=>s, j=>p
        int i=0,j=0;
        int slen=s.length(),plen=p.length();
        while(i<slen&&j<slen){
            // find nonpassing conditions
            // equal
            if(s[i]==p[i]){
                i++;
                j++;
            }
            // star
            
        }
        // if everything passed
        return true;
    }
};
// @lc code=end

