/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // if negative => not same backwards due to '-' sign
        if(x<0){
            return false;
        }
        int bakupx=x;
        long long ans=0;
        int digits=0;
        int temp=x;
        while(temp>0){
            digits++;
            temp=temp/10;
        }
        long long pow10=pow(10,digits-1);
        while(digits>0){
            ans=ans+((x%10)*pow10);
            // ans=ans*10+(x/pow10)%10;
            // cout<<ans<<" ";
            x=x/10;
            pow10=pow10/10;
            digits--;
        }
        if(bakupx==(int)ans){
            return true;
        }else{
            return false;
        }
    }
};
// @lc code=end

