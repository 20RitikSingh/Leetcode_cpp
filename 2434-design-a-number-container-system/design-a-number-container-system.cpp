class NumberContainers {
    set<pair<int,int>> set;
    unordered_map<int,int> mp;
public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        set.erase({mp[index],index});
        mp[index]=number;
        set.insert({mp[index],index});
    }
    
    int find(int number) {
        auto it=set.lower_bound({number,-1});
        if(it==set.end() || it->first!=number) return -1;
        return it->second;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */