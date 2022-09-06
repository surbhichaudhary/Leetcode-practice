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
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = nums.size(), ans =0;
        unordered_map<int,int> mp;
        
        for( int i=0 ; i < n ; i++ ){
            mp[nums[i]]++;
        }
        
        while( head ){
            if( mp.count(head->val) ){
                ans++;
                while( head && mp.count(head->val) ){
                    mp.erase(head->val);
                    head = head->next;
                }
            }
            else{
                head = head->next;
            }
        }
        
        return ans;
    }
};