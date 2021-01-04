/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (48.36%)
 * Likes:    5042
 * Dislikes: 474
 * Total Accepted:    727.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        int n=digits.length();
        if(n==0){
            return ans;
        }
        
        map<string,vector<string>> m;
        m["2"]={"a","b","c"};
        m["3"]={"d","e","f"};
        m["4"]={"g","h","i"};
        m["5"]={"j","k","l"};
        m["6"]={"m","n","o"};
        m["7"]={"p","q","r","s"};
        m["8"]={"t","u","v"};
        m["9"]={"w","x","y","z"};

        for(int i=0;i<digits.length();i++){
            if(i==0){
                string index;
                index+=digits[i];
                vector<string> curr=m[index];
                for(int j=0;j<curr.size();j++){
                    ans.push_back(curr[j]);
                }
            }else{
                string index;
                index+=digits[i];
                vector<string> curr=m[index];
                // add every char of current to every string of ans
                vector<string> curr_ans;
                for(int j=0;j<curr.size();j++){
                    string curr_char=curr[j];
                    for(int k=0;k<ans.size();k++){
                        string new_string=ans[k]+curr_char;
                        curr_ans.push_back(new_string);
                    }
                }
                ans=curr_ans;
            }
        }

        return ans;

    };

};
// @lc code=end

