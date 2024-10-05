
class CustomStack {
    vector<int> v;
    int size,mx_size;
public:
    CustomStack(int maxSize) {
        size=0;
        mx_size=maxSize;
    }
    
    void push(int x) {
        if(size==mx_size) return;
        v.push_back(x);
        size++;
    }
    
    int pop() {
        if(!size) return -1;
        int x=v.back();
        v.pop_back();
        size--;
        return x;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,size);i++) v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */