/*

 Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 
*/

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
    ListNode* merge(ListNode* a,ListNode* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* c;
        if(a->val<b->val){
            c=a;
            c->next=merge(a->next,b);
        }else{
            c=b;
            c->next=merge(a,b->next);
        }
        return c;
    }
    ListNode* midpoint(ListNode* head){
        auto fast=head->next;
        auto slow=head;
        while(fast and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        // base case
        if(head==NULL || head->next==NULL){
            return head;
        }
        //1. break
        auto mid=midpoint(head);
        auto a=head;
        auto b=mid->next;
        mid->next=NULL;
        //2. rec sort
        a=sortList(a);
        b=sortList(b);
        //3. merge
        auto c=merge(a,b);
        return c;
    }
};