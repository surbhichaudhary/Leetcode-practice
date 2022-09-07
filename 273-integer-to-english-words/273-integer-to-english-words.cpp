class Solution {
public:
    
    string ans;
    
    string ones[20] = { "","One","Two","Three","Four","Five","Six","Seven", "Eight","Nine",
                       "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                      "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy", 
                       "Eighty","Ninety" };
    
    void solve( int n ){
        if( n == 0 ){
            return;
        }
        
        else if( n >= 1000000000 ){
            ans += ( ones[n/1000000000] + " Billion" );
            solve( n%1000000000 );
        }
        
        else if( n >= 1000000 ){
            solve( n/1000000 );
            ans += " Million";
            solve( n%1000000 );
        }
        
        else if( n >= 1000 ){
            solve( n/1000 );
            ans += " Thousand";
            solve( n%1000 );
        }
        
        else if( n >= 100 ){
            if( isalpha(ans.back()) ){
                ans.push_back(' ');
            }
            ans += ( ones[n/100] + " Hundred" );
            solve( n%100 );
        }
        
        else if( n >= 20 ){
            ans += ( ' ' + tens[n/10] );
            solve( n%10 );
        }
        
        else {
            ans += ( ' ' + ones[n] );
        }
     
    }
    
    string numberToWords(int num) {
        
        if( num == 0 ){
            return "Zero";
        }
        
        ans = "";
        solve( num );
        
        int i =0;
        while( i<ans.length() && ans[i] == 32 ){
            i++;
        }
        ans = ans.substr(i);
        return ans;
    }
};
