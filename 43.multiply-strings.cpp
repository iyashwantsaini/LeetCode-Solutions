/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (34.61%)
 * Likes:    2183
 * Dislikes: 927
 * Total Accepted:    340.7K
 * Total Submissions: 980.6K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 * 
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // addition of string integers
    string add(string num1, string num2) {
        int carry=0;
        int i=num1.length()-1;
        int j=num2.length()-1;
        string ans;
        char a,b;
        int x,y;
        while(1){
            if(i<0&&j<0&&carry==0){
                break;
            }
            if(i<0){
                x=0;
            }else{
                a=num1[i];
                x=a-'0';
            }
            if(j<0){
                y=0;
            }else{
                b=num2[j];
                y=b-'0';
            }
            int result=x+y+carry;
            carry=result/10;
            result=result%10;
            ans.push_back(result+'0');
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        
    }
};
// @lc code=end

