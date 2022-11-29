class RandomizedSet {
public:
    
    set<int> s;
    int n;
    
    RandomizedSet() {
        n = 0;
        s.clear();
    }
    
    bool insert(int val) {
        if( s.find(val) == s.end() ){
            s.insert(val);
            n++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if( s.find(val) != s.end() ){
            s.erase(val);
            n--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r = rand()%n;
        
        set<int>::iterator st = s.begin();
        for( int i = 0 ; i < r ; i++ ){
            st++;
        }
        return *st;
    }
};

/**

 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */