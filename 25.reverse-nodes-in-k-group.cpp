/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (43.94%)
 * Likes:    3111
 * Dislikes: 387
 * Total Accepted:    315.3K
 * Total Submissions: 714.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 * 
 * Follow up:
 * 
 * 
 * Could you solve the problem in O(1) extra memory space?
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [1], k = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1){
            return head;
        }

        // constant storage
        ListNode *temp=head;
        // pointers for reversal
        ListNode *prv=NULL;
        ListNode *curr=head;
        ListNode *nxt=head;
        int first=0;
        int flag=1;
        int count=0;

        // count total nodes
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        
        // STEPS:
        // find if there are k values next to current
        // if possible reverse it
        curr=head;
        while(count>=k){
            for(int i=0;i<k;i++){
                ListNode *nxt=curr->next;
                curr->next=prv;
                prv=curr;
                curr=nxt;
            }
            if(first==0){
                head=prv;
                first=1;
                temp->next=curr;
            }else{
                ListNode *nxt=temp->next;
                temp->next->next=curr;
                temp->next=prv;
                temp=nxt;
            }
            prv=NULL;
            count-=k;
        }
        // head will be the first kth value in the list
        return head;
    }
};
// @lc code=end

