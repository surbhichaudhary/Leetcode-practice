class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size(), num = n / k, j = 0, g=0;
        if( n%k != 0 ){
            return false;
        }
        
        unordered_map<int , int> mp;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for( int i = 0 ; i < n ; i++ ){
            mp[nums[i]]++;
            pq.push( nums[i] );
        }
        
        while( (!pq.empty()) && (mp.size() > 0) ){
            int tp = pq.top(), val = tp, s =0;
            pq.pop();
            
            if( mp.count( val ) ){
                while( mp.count(val) && ( s < k ) ){
                    mp[val]--;
                    if( mp[val] == 0 ){
                        mp.erase(val);
                    }
                    
                    val++;
                    s++;
                }
                if( s == k ){
                    g++;
                }
            }
            
        }
        
        return ( (g == num) && (mp.size() == 0) );
    }
};
