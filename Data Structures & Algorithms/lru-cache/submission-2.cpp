class LRUCache {
public:
    vector<int> cache;
    map<int,pair<int,int>> cash;
    int start,sz,cp;
    LRUCache(int capacity) {
        cache = {};
        start=0;sz=0;
        cp = capacity;
        map<int,pair<int,int>> temp;
        cash=temp;
    }
    
    int get(int key) {
        if(cash.find(key) == cash.end())return -1;
        cache.push_back(key);
        int oldPos = cash[key].second;
        cache[oldPos] = -1;
        cash[key].second = cache.size()-1;
        return cash[key].first;
    }
    
    void put(int key, int value) {
        if(cash.find(key) != cash.end()){
            cache.push_back(key);
            int oldPos = cash[key].second;
            cache[oldPos] = -1;
            cash[key] = make_pair(value,cache.size()-1);
        }else{
            sz++;
            cache.push_back(key);
            cash[key] = make_pair(value,cache.size()-1);
        }
        while(sz>cp){
            if(cache[start] == -1){
                start++;
            }else{
                int k = cache[start];
                cash.erase(k);
                sz--;
                start++;
            }
        }
        return;
    }
};
