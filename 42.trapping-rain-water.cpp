/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (50.50%)
 * Likes:    9548
 * Dislikes: 146
 * Total Accepted:    650.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 0 <= n <= 3 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    int trap(vector<int>& height) {
        // precompute for every index => max on left and right
        // curr ans=> min(left,right)-height[curr]

        int n=height.size();
        if(n<=2){
            return 0;
        }
        int l[n];
        int r[n];
        // fill left
        int maxtill=0;
        for(int i=0;i<n;i++){
            if(height[i]<maxtill){
                l[i]=maxtill;
            }else{
                l[i]=height[i];
                maxtill=height[i];
            }
        }
        // fill right
        maxtill=0;
        for(int i=n-1;i>=0;i--){
            if(height[i]<maxtill){
                r[i]=maxtill;
            }else{
                r[i]=height[i];
                maxtill=height[i];
            }
        }

        // for(int i=0;i<n;i++){
        //     cout<<l[i]<<" ";
        // }cout<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<r[i]<<" ";
        // }

        int cap=0;
        for(int i=0;i<n;i++){
            cap+=(min(l[i],r[i])-height[i]);
        }
        return cap;

    }

    // SOME TEST CASES DONT PASS DUE TO 1 SIDE COMPUTATION
    // int trap(vector<int>& height) {
    //     int totalsum=0;
    //     int n=height.size();
    //     if(n<=2){
    //         return totalsum;
    //     }
    //     int i=0;
    //     while(height[i]==0){
    //         i++;
    //     }
    //     for(;i<n;){
    //         int currsum=0;
    //         int flag=0;
    //         for(int j=i+1;j<n;j++){
    //             if(height[j]>=height[i]){
    //                 flag=1;
    //                 i=j;
    //                 break;
    //             }
    //             currsum+=(height[i]-height[j]);
    //         }
    //         // cout<<"currsum ="<<currsum<<"\n";
    //         if(flag==0){
    //             i++;
    //             // cout<<"i= "<<i<<"\n";                
    //         }else{
    //             totalsum+=currsum;
    //         }
    //         // cout<<"totsum ="<<totalsum<<"\n";
    //     }
    //     return totalsum;
    // }
};
// @lc code=end

