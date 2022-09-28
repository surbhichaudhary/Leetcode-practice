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
        if( !head || n ==0 ){
            return head;
        }
        int l =0;
        ListNode* t = head;
        while( t ){
            l++;
            t = t->next;
        }
        if( n == l ){
            return head->next;
        }
        t = head;
        for( int i =1 ;i < l-n ;i++ ){
            t = t->next;
        }
        t->next = t->next->next;
        return head;
    }
};