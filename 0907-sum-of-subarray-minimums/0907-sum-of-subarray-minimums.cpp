#define m 1000000007
typedef pair<int, int> pi;
typedef long long ll;

class Solution {
public:
    
    vector<ll> nsl( vector<int>& arr ){
        stack<pi> s;
        int n = arr.size();
        vector<ll> ans;
        
        for( int i = 0; i < n ;i++ ){
            int curr = arr[i], cnt = 1;
            
            while( (!s.empty()) && (s.top().first > curr) ){
                cnt += s.top().second;
                s.pop();
            }
            
            ans.push_back(cnt);
            s.push({ curr, cnt });
        }
        
        return ans;
    }
    
    vector<ll> nsr( vector<int>& arr ){
        stack<pi> s;
        int n = arr.size();
        vector<ll> ans(n,1);
        
        for( int i = n - 1 ; i >= 0 ; i-- ){
            int curr = arr[i], cnt = 1;
            
            while( !s.empty() && ( s.top().first >= curr ) ){
                cnt += s.top().second;
                s.pop();
            }
            
            s.push({ curr, cnt });
            ans[i] = cnt;
        }
        
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<ll> left = nsl( arr );
        vector<ll> right = nsr( arr );
        
        ll n = arr.size(), s = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            ll p = ( left[i]%m * right[i]%m )%m;
            //cout<<left[i]<<" "<<right[i]<<"\n";
            s = (s%m + ( p * (arr[i]%m) )%m )%m ;
        }
        
        return s;
    }
};