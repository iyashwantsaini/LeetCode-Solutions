/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (35.53%)
 * Likes:    4451
 * Dislikes: 270
 * Total Accepted:    757.6K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 * 
 * Follow up: Could you do this in one pass?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we'll use 2 pointers
        // 1=> fast 2=> slow
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *back=dummy;
        ListNode *front=dummy;
        // advance front pointer to n steps in front
        for(int i=1;i<=n+1;i++){
            front=front->next;
        }
        while(front!=NULL){
                front=front->next;
                back=back->next;
        }
        back->next=back->next->next;
        return dummy->next;
    }
};
// @lc code=end

