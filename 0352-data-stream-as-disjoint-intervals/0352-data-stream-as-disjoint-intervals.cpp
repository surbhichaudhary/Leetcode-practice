typedef pair<int, int> pi;
typedef vector<int> vi;

class SummaryRanges {
public:
    
    set<vi> s;
    
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int value) {
        s.insert({ value, value });
    }

    vector<vector<int>> getIntervals() {
        vector<vi> ans;
        
        for( auto i : s ){
            if( ans.size() == 0 || ( (i[0] - ans.back()[1]) > 1 )){
                ans.push_back(i);
            }
            else {
                ans.back()[0] = min( ans.back()[0], i[0] );
                ans.back()[1] = max( ans.back()[1], i[1] );
            }
        }
        
        return ans;
    }
};
/*//////////////////////////////////////////////////////////////////
if( (value >= ans[i][0]) && (value <= ans[i][1]) ){
                break;
            }
            else if( value == (ans[i][0] - 1) ){
                ans[i][0] = value;
                break;
            }
            else if( value == ( ans[i][1] + 1 ) ){
                ans[i][1] = value;
                break;
            }
            else if(( i>0 ) && (value < ans[i][0]-1) && (value > ans[i-1][1] + 1) ){
                ans.insert( ans.begin() + i, tmp );
            }
            break;
///////////////////////////////////////////////////////////////////////
        
        //when ans vector is empty
        int n = ans.size(), ins = 0, cmin = mn, cmax = mx ;
        mn = min( mn, value );
        mx = max( mx, value );
        
        if( n == 0 ){
            ans.push_back({ value, value });
            return;
        }
        vector<int> tmp = { value, value };
        // if current value is smallest
        if( cmin > value ){
            ans.insert( ans.begin(), tmp );
            return;
        }
        //if current value is largest
        else if( cmax < value ){
            ans.push_back(tmp);
            return;
        }
        //if merging with first or last;
        else if( (ans[0][0] >= value && ans[0][1] >= value) || 
                ( ans[n-1][0] >= value && ans[n-1][1] >= value) ){
            return;
        } 
        //else insert interval
        int s = 0, e = ans.size() - 1;
        while( s <= e ){
            int m = s + ( e-s )/2;
            if( ans[m][0] < value )
        }
        
        for( int i = 1 ; i < ans.size() ; i++ ){
            if( ans[i][0] - ans[i-1][1] <= 1 ){
                ans[i-1][0] = min( ans[i-1][0], ans[i][0] );
                ans[i-1][1] = max( ans[i-1][1], ans[i][1] );
                ans.erase( ans.begin() + i );
                i--;
            }
        }
///////////////////////////////////////////////////////////////////*/