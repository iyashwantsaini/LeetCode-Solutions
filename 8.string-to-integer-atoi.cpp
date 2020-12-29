/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s){
        int i=0;
        int sign=0;
        while(1){
            // if words found first
            if(s[i]=='+'||s[i]=='-'){
                if(s[i]=='+'){
                    sign=1;
                }else{
                    sign=-1;
                }
                i++;
                break;
            }
            else if((int(s[i])>=int('0'))&&(int(s[i])<=int('0')+9)){
                break;
            }
            else if(s[i]==' '){
                i++;
            }else{
                return 0;
            }
        }
        long long int ans=0;
        while(i<s.length()){
            if((int(s[i])>=int('0'))&&(int(s[i])<=int('0')+9)){
                ans=ans*10+(int(s[i])-'0');
                if(ans>INT_MAX){
                    if(sign==-1){
                        return INT_MIN;
                    }else{
                        return INT_MAX;
                    }
                }
            }else{
                break;
            }
            i++;
        }
        ans=(int)ans;
        return (sign==-1)?ans*-1:ans;
    }
};
// @lc code=end

