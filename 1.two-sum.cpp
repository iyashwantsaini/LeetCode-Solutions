/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        // add to map
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            // if remaining requried already exists
            if(m[target-nums[i]]!=0){
                v.push_back(m[target-nums[i]]-1);
                v.push_back(i);
                break;
            }
            else{
                m[nums[i]]=i+1;
            }
        }
        return v;
    }
};
// @lc code=end

