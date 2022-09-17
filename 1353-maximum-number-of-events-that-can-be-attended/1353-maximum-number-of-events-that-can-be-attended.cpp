typedef long long ll;

class Solution {
public:
    
    static bool mycomp( vector<int> &a , vector<int> &b) {
        if(a[1]==b[1])     {
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end(),mycomp);
        
        set<int> s;
        
        for(int i=1;i<=100000;i++) {
            s.insert(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++) {
            int se=events[i][0],e=events[i][1];
            auto it=s.lower_bound(se);
            
            if(it==s.end() || *it>e){
                continue;
            }
            else {
                ans++;
                s.erase(it);
            }  
        }
        
        return ans;
    }
    
//     static bool comp( vector<int> a, vector<int> b ){
//         if( a[1] == b[1] ){
//             return a[0] < b[0] ;
//         }
//         return a[1] < b[1];
//     }
    
//     int maxEvents(vector<vector<int>>& events) {
//         int n = events.size(), md = events[0][1], ans =0;
//         for( int i = 1 ; i < n ; i++ ){
//             md = max( md, events[i][1] );
//         }
//         sort( events.begin(), events.end(), comp );
//         vector<int> slots( md+1, -1 );
        
//         for( int i = n-1 ; i >= 0 ; i-- ){
//             ll s = events[i][0], e = events[i][1], pos = -1;
//             while( s <= e ){
//                 ll mid = s + (e-s)/2;
//                 if( slots[mid] == -1 ){
//                     pos = mid;
//                     s = mid+1;
//                 }
//                 else{
//                     e = mid-1;
//                 }
//             }
//             if( pos != -1 ){
//                 slots[pos] = 1;
//                 ans++;
//             }
//         }
        
//         return ans;
//     }
};