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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if( !head ){
            return nullptr;
        }
        if( !head->next ){
            TreeNode* root = new TreeNode( head->val );
            return root;
        }
        
        ListNode* s = head ; ListNode* f = head;
        ListNode* prev = NULL; 
        
        while( f && f->next ){
            prev = s;
            s = s->next;
            f = f->next->next;
            //cout<<prev->val<< " "<< prev->next->val<<endl;
        }
      
        TreeNode* root = new TreeNode(s->val);
        root->right = sortedListToBST( s->next );
        
        prev->next = NULL;
        root->left = sortedListToBST(head);
        
        return root;
    }
};