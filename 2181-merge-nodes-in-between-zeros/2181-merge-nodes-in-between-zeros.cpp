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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* nh = NULL;
        ListNode* nt = NULL;
        ListNode* tmp = NULL;
        
        while( head ){
            if( head->val == 0 ){
                if( !nh ){
                    nh = head;
                }
                else {
                    nt->next = tmp;
                    nt = tmp;
                    tmp = tmp->next;
                    nt->next = head;
                }
                nt = head;
                head = head->next;
                nt->next = NULL;
            }
            else{
                if( !tmp ){
                    tmp = head;
                }
                else{
                    tmp->val += head->val;
                }
                head = head->next;
                tmp->next = NULL;
            }
        }
        while( nh && nh->val == 0 ){
            nh = nh->next;
        }
        nt = nh;
        while( nt && nt->next ){
            while( nt->next && nt->next->val == 0 ){
                nt->next = nt->next->next;
            }
            nt = nt->next;
        }
        
        return nh;
    }
};