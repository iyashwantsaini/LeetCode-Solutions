/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (55.11%)
 * Likes:    5778
 * Dislikes: 698
 * Total Accepted:    1.3M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a sorted list. The list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [1,2,4], l2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [], l2 = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [], l2 = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both l1 and l2 are sorted in non-decreasing order.
 * 
 * 
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 1 or both NULL
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode *l3=new ListNode();
        ListNode *head=l3;
        while(l1!=NULL||l2!=NULL){
            // if one has become null
            if(l1==NULL){
                l3->val=l2->val;
                l2=l2->next;
                if(l1!=NULL||l2!=NULL){
                    l3->next=new ListNode();
                    l3=l3->next;
                }
            }
            else if(l2==NULL){
                l3->val=l1->val;
                l1=l1->next;     
                if(l1!=NULL||l2!=NULL){
                    l3->next=new ListNode();
                    l3=l3->next;
                }           
            }else{
                // select smaller
                if(l1->val<l2->val){
                    l3->val=l1->val;
                    l1=l1->next;
                    if(l1!=NULL||l2!=NULL){
                        l3->next=new ListNode();
                        l3=l3->next;
                    } 
                }else{
                    l3->val=l2->val;
                    l2=l2->next;
                    if(l1!=NULL||l2!=NULL){
                        l3->next=new ListNode();
                        l3=l3->next;
                    } 
                }
            }
        }
        return head;
    }
};
// @lc code=end

