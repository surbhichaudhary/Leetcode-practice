#define m 1000000007

class Solution {
public:
    
    int az, ao, l, h;
    unordered_map< int, int> mp;
    
    int solve( int len ){
        int ans = 0;
        if( len > h ){
            return 0;
        }
        if( mp.count(len) ){
            return mp[len];
        }
        if( ( len >= l ) && ( len <= h ) ){
            ans++;
        }
        
        ans = (ans%m + solve( len+az )%m)%m;
        ans = (ans%m + solve( len+ao )%m)%m;
        
        return mp[len] = ans;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        az = zero, ao = one, l = low, h = high;
        mp.clear();
        
        return solve( 0 );
        
    }
};