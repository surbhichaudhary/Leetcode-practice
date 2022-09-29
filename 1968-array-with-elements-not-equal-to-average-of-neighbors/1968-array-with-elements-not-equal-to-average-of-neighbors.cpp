class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int i=0, n = nums.size(), j = n-1, k=0;
        vector<int> ans;
        
        while( i <= j && k < n ){
            if( k%2 == 0 ){
                ans.push_back(nums[j--]);
            }
            else{
                ans.push_back(nums[i++]);
            }
            k++;
        }
        
        return ans;
    }
};