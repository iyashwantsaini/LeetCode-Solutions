/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (35.49%)
 * Likes:    6650
 * Dislikes: 584
 * Total Accepted:    885.6K
 * Total Submissions: 2.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * You are given an integer array nums sorted in ascending order (with distinct
 * values), and an integer target.
 * 
 * Suppose that nums is rotated at some pivot unknown to you beforehand (i.e.,
 * [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * If target is found in the array return its index, otherwise, return -1.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is guaranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return -1;
        }
        if(n==1){
            if(nums[0]==target){
                return 0;
            }
            return -1;
        }
        // our modified binary search function
        return binary_srch(nums,target,n,0,n-1);
    }
    int binary_srch(vector<int>& nums,int target,int n,int start,int end){
        if(start>end){
            return -1;
        }
        if(nums[start]==target) return start;
        if(nums[end]==target) return end;

        int mid=(start+end)/2;
        // if sorted
        if(nums[start]<nums[end]){
            // simple logic
            if(nums[mid]<target){
                return binary_srch(nums,target,n,mid+1,end);
            }else if(nums[mid]==target){
                return mid;
            }else{
                return binary_srch(nums,target,n,start,mid-1);
            }
        }

        // not sorted
        // may move right
        if(nums[mid]>nums[start]&&nums[end]>target){
            return binary_srch(nums,target,n,mid+1,end);
        }else if(nums[mid]<nums[end]&&nums[start]<target){
            return binary_srch(nums,target,n,start,mid-1);
        }else{
            // simple logic
            if(nums[mid]<target){
                return binary_srch(nums,target,n,mid+1,end);
            }else if(nums[mid]==target){
                return mid;
            }else{
                return binary_srch(nums,target,n,start,mid-1);
            }
        }

    }
    
};
// @lc code=end

