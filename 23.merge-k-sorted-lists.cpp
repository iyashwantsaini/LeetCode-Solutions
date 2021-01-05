/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (41.73%)
 * Likes:    6090
 * Dislikes: 326
 * Total Accepted:    775.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 * 
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: lists = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: lists = [[]]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length won't exceed 10^4.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        ListNode *l=new ListNode();
        ListNode *head=l;
        ListNode *prev;
        int _empty=1;
        while(1){
            int val=INT_MAX;
            int index=0;
            int possible=0;
            for(int i=0;i<n;i++){
                if(lists[i]!=NULL&&lists[i]->val<val){
                    val=lists[i]->val;
                    index=i;
                }
            }
            // now we have minimum in current
            if(val==INT_MAX){
                break;
            }else{
                // create new node
                _empty=0;
                l->val=val;
                prev=l;
                l->next=new ListNode();
                l=l->next;
                lists[index]=lists[index]->next;
            }
        }
        if(head->next!=NULL){
            prev->next=NULL;
        }
        if(_empty){
            head=NULL;
        }
        return head;
    }
};