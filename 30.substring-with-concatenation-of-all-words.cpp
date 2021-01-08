/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (25.94%)
 * Likes:    1115
 * Dislikes: 1385
 * Total Accepted:    194.6K
 * Total Submissions: 748.2K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of
 * each word in words exactly once, in any order, and without any intervening
 * characters.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of lower-case English letters.
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] consists of lower-case English letters.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // vector for answers
        vector<int> ans;
        // step 1 => save array in hashmap
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        // length of all words in array are same => given
        int totlen=words[0].size()*words.size();
        for(int i=0;i+totlen<=s.size();i++){
            string curr=s.substr(i,totlen);
            unordered_map<string,int> n;
            int j=0;
            while(j+words[0].size()<=curr.size()){
                n[curr.substr(j,words[0].size())]++;
                j=j+words[0].size();
            }
            if(n==m){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> v;
    v.push_back("foo");
    v.push_back("bar");
    s.findSubstring("barfoothefoobarman",v);
}
