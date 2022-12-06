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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oh = NULL ; ListNode* ot = NULL;
        ListNode* eh = NULL ; ListNode* et = NULL;
        int i = 1;
        
        while( head ){
            if( i % 2 != 0 ){
                if( !oh ){
                    oh = head;
                }
                else{
                    ot->next = head;
                }
                ot = head;
                head = head->next;
                ot->next = NULL;
            }
            else{
                if( !eh ){
                    eh = head;
                }
                else{
                    et->next = head;
                }
                et = head;
                head = head->next;
                et->next = NULL;
            }
            i++;
        }
        
        if( !oh ){
            return eh;
        }
        ot->next = eh;
        return oh;
    }
};