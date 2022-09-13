class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0, i = num1.length()-1, j= num2.length() -1;
        string ans = "";
        
        while( i>=0 && j >=0 ){
            int v1 = num1[i] - '0' , v2 = num2[j] -'0';
            int s = v1+v2+c;
            c = s/10;
            s %= 10;
            
            char ch = s+'0';
            ans.push_back(ch);
            
            i--;
            j--;
        }
        while( i >= 0 ){
            int v1 = num1[i] - '0' ;
            int s = v1+c;
            c = s/10;
            s %= 10;
            
            char ch = s+'0';
            ans.push_back(ch);
            
            i--;
        }
        while( j >= 0 ){
            int v2 = num2[j] -'0';
            int s = v2+c;
            c = s/10;
            s %= 10;
            
            char ch = s+'0';
            ans.push_back(ch);
            
            j--;
        }
        if( c != 0 ){
            char ch = c+'0';
            ans.push_back(ch);
        }
        
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};