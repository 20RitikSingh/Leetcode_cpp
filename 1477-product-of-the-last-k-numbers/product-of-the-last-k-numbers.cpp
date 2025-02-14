class ProductOfNumbers {
    vector<int> v;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(!num) v=vector<int>();
        else if(v.empty()) v.push_back(num);
        else v.push_back(num*v.back());
    }
    
    int getProduct(int k) {
        if(k>v.size()) return 0;
        else if(k==v.size()) return v.back();
        return v.back()/v[v.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */