/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.57%)
 * Likes:    1484
 * Dislikes: 6102
 * Total Accepted:    325.1K
 * Total Submissions: 2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Note:
 * 
 * 
 * Assume we are dealing with an environment that could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For this
 * problem, assume that your function returns 2^31 − 1 when the division result
 * overflows.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: dividend = 0, divisor = 1
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: dividend = 1, divisor = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// @lc code=start
typedef long long ll;
class Solution {
public:
    
    // TLE - all cases passing
    // int divide(int dividend, int divisor) {
    //     if(dividend==divisor){
    //         return 1;
    //     }
    //     if(divisor>0&&dividend>=0&&divisor>dividend){
    //         return 0;
    //     }
    //     if(divisor==1){
    //         return dividend;
    //     }
    //     if(divisor==-1){
    //         if(dividend==INT_MIN){
    //             dividend+=1;
    //         }
    //         return -1*dividend;
    //     }
    //     int count=0;
    //     ll a=abs((ll)dividend);
    //     ll b=abs((ll)divisor);
    //     while(a>=b){
    //         count++;
    //         a-=b;
    //     }
    //     if(dividend<=0&&divisor>0||dividend>=0&&divisor<0){
    //         return -1*count;
    //     }
    //     return count;
    // }

    // BIT-Manipulation method
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        if(divisor>0&&dividend>=0&&divisor>dividend){
            return 0;
        }   
        if(divisor==1){
            return dividend;
        }
        if(divisor==-1){
            if(dividend==INT_MIN){
                dividend+=1;
            }
            return -1*dividend;
        }
        ll n=abs((ll)dividend);
        ll m=abs((ll)divisor);
        ll t=m; //used for shifting
        ll count=0;
        // multiply divisor by 2 till no more possible
        for(int i=31;i>=0;i--){
            if((t<<i)<=n){
                t=t<<i;
                count=1<<i;
                break;
            }
        }
        while(t+m<=n){
            t+=m;
            count++;
        }
        if(dividend<=0&&divisor>0||dividend>=0&&divisor<0){
            return -1*count;
        }
        return (int)count;
    }

};
// @lc code=end

