/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

// method 1=>bruteforce
// merge 2 and sort => find median

// method 2
// https://www.youtube.com/watch?v=LPFhl65R7ww&feature=emb_title

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x=nums1.size();
        int y=nums2.size();
        // we are assuming x is less than y 
        // so we'll do binary search on the smaller array
        // if x>y recall function
        if(x>y){
            return findMedianSortedArrays(nums2,nums1);
        }

        int start=0;
        int end=x;

        while(start<=end){
            // markers on where to partition both
            int partitionx=(start+end)/2;
            int partitiony=((x+y+1)/2)-partitionx;
            
            // findind max and min on both sides
            // checking if left & right of x,y are empty
            int maxleftx=(partitionx==0)?INT_MIN:nums1[partitionx-1];
            int minrightx=(partitionx==x)?INT_MAX:nums1[partitionx];
            int maxlefty=(partitiony==0)?INT_MIN:nums2[partitiony-1];
            int minrighty=(partitiony==y)?INT_MAX:nums2[partitiony];

            // not satisfied
            if(maxleftx>minrighty){
                end=partitionx-1;
            }
            else if(maxlefty>minrightx){
                start=partitionx+1;
            }
            // if condition satisfied
            else{
                // check if number of el's even/odd
                if((x+y)%2==0){
                    return ((double)max((double)maxleftx,(double)maxlefty)+min((double)minrightx,(double)minrighty))/2;
                }else{
                    return (double)max((double)maxleftx,(double)maxlefty);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

