/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map< ListNode*, int > mp;
        ListNode* t = head;
        
        while( t ){
            if( mp.count(t) ){
                return t;
            }
            mp[t]++;
            t = t->next;
        }
        return t;
    }
};