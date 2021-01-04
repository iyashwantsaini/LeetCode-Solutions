/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int romanToInt(string s) {
        map<string,int> m{
            {"M",1000},
            {"CM",900},
            {"D",500},
            {"CD",400},
            {"C",100},
            {"XC",90},
            {"L",50},
            {"XL",40},
            {"X",10},
            {"IX",9},
            {"V",5},
            {"IV",4},
            {"I",1}
        };

        int ans=0;
        int len=s.length();
        for(int i=0;i<len;){
            // get current string
            string st="";
            st+=s[i];
            
            // if specials possible make them
            // eg 4 =>IV
            int flag=0;
            if(i+1<len){
                if(m[st+s[i+1]]!=0){
                    flag=1;
                    ans+=m[st+s[i+1]];
                    i+=2;
                }
            }
            
            // if special not possible
            if(flag==0){
                if(m[st]!=0){
                    ans+=m[st];
                    i+=1;
                }
            }

        }
        return ans;
    }
};
// @lc code=end

