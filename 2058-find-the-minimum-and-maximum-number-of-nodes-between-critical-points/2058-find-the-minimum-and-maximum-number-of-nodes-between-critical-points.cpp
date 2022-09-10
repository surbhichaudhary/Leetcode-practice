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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        int a1 = INT_MAX, a2 =INT_MIN, fr = -1, n=2, lp=-1;
        
        if( !head || !head->next || !head->next->next ){
            return ans;
        }
        
        ListNode* pr = head;
        ListNode* cr = head->next;
        ListNode* nx = head->next->next;
        
        while( nx ){
            if(( cr->val < pr->val && cr->val < nx->val) || 
              ( cr->val > pr->val && cr->val > nx->val )){
                if( fr == -1 ){
                    fr = n;
                    lp = n;
                }
                else{
                    a1 = min( a1, n-lp );
                    a2 = max( a2, n-fr );
                    lp = n;
                }
            }
            n++;
            pr = cr;
            cr = nx;
            nx = nx->next;
        }
        
        if( fr != -1 && lp != -1 && lp != fr ){
            ans[0] = a1;
            ans[1] = a2;
        }
        return ans;
    }
};