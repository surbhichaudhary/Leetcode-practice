typedef long long ll;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll n = nums.size(), m = 1000000007, ans = 1;
        
        for( int i=0; i<n ;i++ ){
            pq.push(nums[i]);
        }
        while( k > 0 ){
            ll tp = pq.top();
            pq.pop();
            tp++;
            k--;
            pq.push(tp);
        }
        
        while( !pq.empty() ){
            ll t = pq.top();
            pq.pop();
            
            ans = (ans%m * t%m )%m;
        }
        return ans;
    }
};