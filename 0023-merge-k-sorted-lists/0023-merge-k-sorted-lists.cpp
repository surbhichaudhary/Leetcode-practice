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
    ListNode* mergeTwoLists( ListNode* l1, ListNode* l2) {
        ListNode* fh = NULL;
        ListNode* ft = NULL;
        while( l1 && l2 ){
            if( l1->val <= l2->val ){
                if( !fh ){
                    fh = l1;
                }
                else{
                    ft->next = l1;
                }
                ft = l1;
                l1 = l1->next;
            }
            else{
                if(!fh){
                    fh = l2;
                }
                else{
                    ft->next = l2;
                }
                ft = l2;
                l2 = l2->next;
            }
            
        }
        if( l1 ){
            if(!fh){
                return l1;
            }
            ft->next = l1;
        }
        if( l2 ){
            if(!fh ){
                return l2;
            }
            ft->next = l2;
        }
        return fh;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size() == 0 ){
            return NULL;
        }
        int n = lists.size();
        while( n > 1 ){
            ListNode* l1 = lists[n-2];
            ListNode* l2 = lists[n-1];
            lists[n-2] = mergeTwoLists( l1, l2);
            n--;
        }
        
        return lists[0];
    }
};