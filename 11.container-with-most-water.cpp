/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxArea(vector<int>& height) {
        ll n=height.size();
        if(n<=1){
            return 0;
        }
        if(n==2){
            return 1*min(height[0],height[1]);
        }
        ll max_area=0;
        // go to every pole
        for(ll i=0;i<n;i++){
            // height of pole
            ll h=height[i];
            // max for current pole
            ll curr_max=0;
            // got to each pole from end to current
            for(ll j=n-1;j>=i;j--){

                // height of pole from last
                ll h_last=height[j];
                // distance between 2 poles
                ll dist=j-i;

                // if more can't be made from remaining distance
                if(h*dist<curr_max){
                    break;
                }
                
                if(h>h_last){
                    if((h_last*dist)>curr_max){
                        curr_max=h_last*dist;
                        if(curr_max>max_area){
                            max_area=curr_max;
                        }
                    }
                }else{
                    if((h*dist)>curr_max){
                        curr_max=h*dist;
                        if(curr_max>max_area){
                            max_area=curr_max;
                        }
                    }
                }                
            
            }
        }

        return max_area;
    }
};
// @lc code=end

