//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        sort( start, start + N );
        sort( end, end + N );
        
        int curr = 0, ans =0, i=0 , j =0 ;
        while( (i < N) && (j < N) ){
            if( start[i] < end[j] ){
                curr++;
                i++;
                ans = max( ans, curr );
            }
            else if( start[i] > end[j] ){
                curr--;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends