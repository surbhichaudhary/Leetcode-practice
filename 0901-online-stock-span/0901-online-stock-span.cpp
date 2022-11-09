#include<stack> 

typedef pair<int,int> pi;

class StockSpanner {
public:
    stack<pi> s;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        int ans = 1;
        i++;
        
        if( !s.empty() && s.top().first > price ){
            ans = i-s.top().second ;
        }
        else if( !s.empty() && s.top().first <= price ){
            while( !s.empty() && s.top().first <= price ){
                s.pop();
            }
            if( s.empty() ){
                ans = i;
            }
            else if( !s.empty() ){
                ans = i-s.top().second;
            }
        }    
        s.push({price,i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */