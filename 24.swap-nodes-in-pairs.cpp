/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (52.34%)
 * Likes:    3141
 * Dislikes: 199
 * Total Accepted:    555K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 * 
 * 
 * 
 * Follow up: Can you solve the problem without modifying the values in the
 * list's nodes? (i.e., Only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *bakup=head;
        while(head!=NULL){
            if(head->next!=NULL){
                // swap
                int temp=head->val;
                head->val=head->next->val;
                head->next->val=temp;
                // move head 2 forward
                head=head->next->next;
            }else{
                head=head->next;
            }
        }
        return bakup;
    }
};
// @lc code=end

