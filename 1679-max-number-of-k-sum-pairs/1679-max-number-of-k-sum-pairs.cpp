class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //dont remove jst count pairs
        unordered_map<int, int> mp;
        for( int i = 0 ; i < nums.size() ; i++ ){
            mp[nums[i]]++;
        }
        int ans = 0;
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            int req = k - nums[i];
            if( nums[i] == req ){
                ans += (mp[req]/2);
                mp[req] = 0;
            }
            else{
                if( mp[nums[i]] < mp[req] ){
                    ans += mp[nums[i]];
                    mp[nums[i]] = 0;
                }
                else if( mp[nums[i]] == mp[req] ){
                    ans += mp[nums[i]];
                    mp[nums[i]] = 0;
                    mp[req] = 0;
                }
                else{
                    ans += mp[req];
                    mp[req] = 0;
                }
            }
        }
        
        return ans;
    }
};