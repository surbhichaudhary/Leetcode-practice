class SmallestInfiniteSet {
public:
    
    map<int, int > mp;
    
    SmallestInfiniteSet() {
        mp.clear();
        for( int i = 1 ; i <= 1005 ; i++ ){
            mp[i]++;
        }
    }
    
    int popSmallest() {
        int ans ;
        
        for( auto i : mp ){
            ans = i.first;
            i.second--;
            if( i.second <= 0 ){
                mp.erase(i.first);
            }
            break;
        }
        
        return ans;
    }
    
    void addBack(int num) {
        if( mp.count(num) ){
            return;
        }
        mp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */