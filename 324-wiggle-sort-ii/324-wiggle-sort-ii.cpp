class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size(), i=1, j = n-1;
        sort( nums.begin(), nums.end() );
        vector<int> ans(n, -1);
        
        while( i < n ){
            ans[i] = nums[j--];
            i += 2;
        }
        i=0;
        while( i < n && j >= 0 ){
            ans[i] = nums[j--];
            i += 2;
        }
        nums = ans;
        return;
    }
};