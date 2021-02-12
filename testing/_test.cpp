#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// @lc code=start
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         // vector for answers
//         vector<int> ans;
//         // step 1 => save array in hashmap
//         unordered_map<string,int> m;
//         for(int i=0;i<words.size();i++){
//             m[words[i]]++;
//         }
//         // length of all words in array are same => given
//         int totlen=words[0].size()*words.size();
//         for(int i=0;i+totlen<=s.size();i++){
//             string curr=s.substr(i,totlen);
//             unordered_map<string,int> n;
//             int j=0;
//             while(j+words[0].size()<=curr.size()){
//                 n[curr.substr(j,words[0].size())]++;
//                 j=j+words[0].size();
//             }
//             if(n==m){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };
// // @lc code=end

// int main(){
//     Solution s;
//     vector<string> v;
//     v.push_back("foo");
//     v.push_back("bar");
//     s.findSubstring("barfoothefoobarman",v);
// }

//head is the head of you linked list
// Following is the node structure
/******
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
*****/
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
bool check_palindrome(node* head)
{
        int l =0;
        node *t=head;
        while(t){
            l++;
            t=t->next;
        }
        node* t1 = head;
        int mid= l/2;
        bool isPalindrome= true; 
        
        for(int i = 0;i<=mid;i++) {
            t1= t1->next;
        }
        node* t2 = NULL;
         t2= t1->next;
         t1->next= NULL;
         while(t2->next!=NULL) {
             if(t2->data == t1->data) {
                 isPalindrome=true;
             }
             else {
                 isPalindrome=false;
             }
             t1=t1->next;
             t2=t2->next;
         }
         return isPalindrome;
}
