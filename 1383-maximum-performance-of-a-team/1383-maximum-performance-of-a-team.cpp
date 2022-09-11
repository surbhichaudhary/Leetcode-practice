typedef long long ll;
#define m 1000000007

struct engg{
    ll sp;
    ll eff;
};

class Solution {
public:
    
    static bool comp( engg a, engg b ){
        return ( a.eff > b.eff );
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ll sm = 0, ans = 0;
        vector<engg> nums(n);
        
        for( int i = 0 ; i < n ; i++ ){
            nums[i].sp = speed[i];
            nums[i].eff = efficiency[i];
        }
        
        sort( nums.begin(), nums.end(), comp );
        priority_queue< ll, vector<ll>, greater<ll> > pq;
        
        for( int i = 0 ; i < n ; i++ ){
            pq.push(nums[i].sp);
            sm += nums[i].sp;
            
            if( pq.size() > k ){
                sm -= pq.top();
                pq.pop();
            }
            ans  = max( ans, sm * nums[i].eff );
        }
        return ans%m;
    }
};