/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // single digit
        if((x>=0&&x<=9)||(x<0&&x>=-9)){
            return x;
        }
        // if negative => make +ve
        int neg=(x<0)?1:0;
        x=abs(x);
        long long int ans=0;
        while(x>0){
            ans=(ans*10)+x%10;
            x=x/10;
            if(ans>=INT_MAX){
                return 0;
            }
        }
        return (neg==1)?ans*-1:ans;
    }
};
// @lc code=end

