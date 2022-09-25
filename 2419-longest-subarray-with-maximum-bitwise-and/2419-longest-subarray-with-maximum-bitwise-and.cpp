class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0, n = nums.size(), l=0, ans=0;
        vector<int> pos;

        for( int i = 0 ; i < n ; i++ ){
            if( nums[i] > mx ){
                pos.clear();
                mx = nums[i];
                l=1;
                ans = 1;
                pos.push_back(i);
            }
            else if( nums[i] == mx ){
                if( i == pos[pos.size()-1] + 1 ){
                    l++;
                }
                else{
                    l = 1;
                }
                ans = max(ans, l);
                pos.push_back(i);
            }
        }
        return ans;
    }
};