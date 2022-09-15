class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int , int> mp;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for( int i = 0 ; i < arr.size() ; i++ ){
            mp[arr[i]]++;
            pq.push(arr[i]);
        }
        
        while( !pq.empty() && mp.size() > 0 ){
            int tp = pq.top();
            pq.pop();
            
            if( !mp.count(tp) ){
                continue;
            }
            
            if( tp == 0 ){
                if( mp.count(0) && mp[0] >= 2 ){
                    mp[0]--;
                }
                else{
                    return false;
                }
            }
            else if( tp > 0 ){
                int dble = 2 * tp ;
                if( !mp.count(dble) ){
                    return false;
                }
                mp[dble]--;
                if( mp[dble] == 0 ) mp.erase(dble);
            }
            else{
                if( abs(tp) % 2 != 0 ){
                    return false;
                }
                int dble = (-1)*( abs(tp)/2.0 );
                if( !mp.count(dble) ){
                    return false;
                }
                mp[dble]--;
                if( mp[dble] == 0 ) mp.erase(dble);
            }
            
            mp[tp]--;
            if( mp[tp] == 0 ) mp.erase(tp);
        }
        return true;
    }
};

/**/