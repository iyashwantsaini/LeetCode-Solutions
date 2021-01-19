// find all subsets in array whose sum is 15

#include<bits/stdc++.h>
using namespace std;

void find_all(vector<int> v,int target,int curr_sum,int index,vector<int> temp){
    // base cases
    if(target==curr_sum){
        // print
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }cout<<"\n";
    }
    if(target<curr_sum){
        return;
    }
    if(index==v.size()){
        return;
    }
    // recursive cases
    // include
    temp.push_back(v[index]);
    find_all(v,target,curr_sum+v[index],index+1,temp);
    // exclude
    temp.pop_back();
    find_all(v,target,curr_sum,index+1,temp);
}

int main(){
    vector<int> v={8,6,7,5,3,10,9};
    int sum=15;
    vector<int> temp; 
    find_all(v,sum,0,0,temp);
    return 0;
}