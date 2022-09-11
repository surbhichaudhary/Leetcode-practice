class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        for( int i = 0 ; i < nums.size() ; i++ ){
            for( int j = i+1 ; j < nums.size() ; j++ ){
                string tmp = "";
                tmp += nums[i];
                tmp += nums[j];
                if( tmp == target ){
                    ans++;
                }
                
                tmp = "";
                tmp += nums[j];
                tmp += nums[i];
                if( tmp == target ){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};