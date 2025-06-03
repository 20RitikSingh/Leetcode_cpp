struct NumberContainers {
    unordered_map<int,set<int>> set;
    unordered_map<int,int> mp;
    void change(int index, int number) {
        set[mp[index]].erase(index);
        mp[index]=number;
        set[mp[index]].insert(index);
    }
    int find(int number) {
        if(set[number].empty()) return -1;
        return *set[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */