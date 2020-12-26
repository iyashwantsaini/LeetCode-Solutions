/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // basic
        int len=s.length();
        if(len<=1){
            return len;
        }
        // keep 2 pointers
        int p1=0; // back
        int p2=0; // front
        unordered_map<char,int> m;
        int maxlength=INT_MIN;
        while(p2<len){
            // if previously exists
            if(m.find(s[p2])!=m.end()){
                // update p1's position
                // p1=m[s[p2]]+1;
                // // clear map
                // m.clear();
                // // add all from p1 to p2-1 to map
                // for(int i=p1;i<p2;i++){
                //     m[s[i]]=i;
                // }
                m.erase(s[p1]);
                p1++;
            }else{
                m[s[p2]]=p2;
                maxlength=max(maxlength,p2-p1+1);
                p2++;
            }
        }
        return maxlength;
    }
};
// @lc code=end

