class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(), num = n / groupSize, j = 0, g=0;
        if( n%groupSize != 0 ){
            return false;
        }
        
        unordered_map<int , int> mp;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for( int i = 0 ; i < n ; i++ ){
            mp[hand[i]]++;
            pq.push( hand[i] );
        }
        
        while( (!pq.empty()) && (mp.size() > 0) ){
            int tp = pq.top(), val = tp, s =0;
            pq.pop();
            
            if( mp.count( val ) ){
                while( mp.count(val) && ( s < groupSize ) ){
                    mp[val]--;
                    if( mp[val] == 0 ){
                        mp.erase(val);
                    }
                    
                    val++;
                    s++;
                }
                if( s == groupSize ){
                    g++;
                }
            }
            
        }
        
        return ( (g == num) && (mp.size() == 0) );
    }
};