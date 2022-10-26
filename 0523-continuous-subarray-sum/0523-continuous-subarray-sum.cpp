class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int > mp;
        int s = 0, n = nums.size();
        mp[0] =0;
        
        for( int i=0 ; i< n ;i++ ){
            s += nums[i];
            int r = s%k;
            if( mp.count(r) ){
                if( mp[r]< i ){
                    return true;
                }
            }
            else{
                mp[r] = i+1;
            }
        }
        return false ;
    }
};