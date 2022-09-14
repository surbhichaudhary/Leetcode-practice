class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        
        for( int i=0; i < nums.size() ; i++ ){
            if( nums[i] % 2 == 0 ){
                mp[nums[i]]++;
            }
        }
        
        int mx = 0, ans = -1;
        for( auto i : mp ){
            if( i.second > mx ){
                mx = i.second;
                ans = i.first;
            }
            else if( i.second == mx ){
                ans = min( ans, i.first);
            }
        }
        
        return ans;
    }
};