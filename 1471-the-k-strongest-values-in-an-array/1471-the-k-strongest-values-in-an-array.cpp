typedef long long ll;
typedef pair<int, int> pi;

class Solution {
public:
    
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort( arr.begin(), arr.end() );
        
        int n = arr.size(), m = (n-1)/2, med = arr[m];
        
        vector<pi> nums(n);
        for( int i = 0 ; i < n ; i++ ){
            nums[i].first = abs( arr[i] - med );
            nums[i].second = arr[i];
        }
        sort( nums.begin(), nums.end(), greater<pi>() );
        
        vector<int> ans;
        for( int i = 0 ; i < k && i < n ; i++ ){
            ans.push_back( nums[i].second );
        }
        return ans;
    }
};