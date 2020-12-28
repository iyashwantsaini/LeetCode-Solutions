/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // this is the simpler way to solve this prob
    // other way is to detect pattern and access elements in order without storing
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int start=0;
        if(numRows==1){
            return s;
        }
        for(int i=0;i<s.length();){
            // forward
            int j=(start==0)?0:1;
            for(;j<numRows&&i<s.length();i++,j++){
                v[j]+=s[i];
            }
            // backward
            for(int j=numRows-2;j>=0&&i<s.length();i++,j--){
                v[j]+=s[i];
            }
            start=1;
        }
        string ans;
        for(int i=0;i<numRows;i++){
            ans+=v[i];
        }
        return ans;
    }
};
// @lc code=end

