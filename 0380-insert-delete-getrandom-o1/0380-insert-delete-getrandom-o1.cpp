class RandomizedSet {
public:
    
    vector<int> result;
    unordered_map<int,int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            cout<<result.size()<<endl;
            mp[val] = result.size();
            // cout<mp[val];
            result.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            int index = mp[val];
            result[index] = result[result.size()-1];
            mp[result[result.size()-1]] = index;
            result.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int p = rand() % result.size();
        return result[p];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */