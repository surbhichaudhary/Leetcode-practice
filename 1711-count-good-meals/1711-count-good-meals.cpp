class Solution {
public:
    
    int countPairs(vector<int>& deliciousness) {
        long long p = 1, ans =0, m = 1000000007, n = deliciousness.size();
        sort( deliciousness.begin(), deliciousness.end() );
        
        for( int i = 1 ; i < 23 ; i++ ){
            int j = 0, k = n-1;
            while( j<k ){
                if( deliciousness[j] + deliciousness[k] == p ){
                    //handle duplicates
                    if( deliciousness[j] == deliciousness[k] ){
                        long long f = k-j+1;
                        f = ( f * (f-1) )/2;
                        ans = (ans%m + f%m )%m;
                        j = k;
                    }
                    else{
                        int a = j, b = k;
                        while( a<k && deliciousness[a] == deliciousness[j] ){
                            a++;
                        }
                        while( b>j && deliciousness[b] == deliciousness[k] ){
                            b--;
                        }
                        int c1 = a-j, c2 = k-b;
                        j = a, k = b;
                        ans = ( ans%m + ( c1%m * c2%m )%m )%m;
                    }
                }
                else if( deliciousness[j] + deliciousness[k] < p ){
                    j++;
                }
                else{
                    k--;
                }
            }
            p = p<<1;
        }
        
        return ans;
    }
};
