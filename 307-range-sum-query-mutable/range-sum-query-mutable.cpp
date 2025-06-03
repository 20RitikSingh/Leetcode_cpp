class NumArray {
    int tree[100000];
    int n;
    int build(vector<int> &nums,int low,int high,int idx){
        int mid=low+(high-low)/2;
        if(high-low==1) tree[idx]=nums[low];
        else tree[idx]=build(nums,low,mid,2*idx+1)+build(nums,mid,high,2*idx+2);
        return tree[idx];
    }
    int query(int low,int high,int b,int e,int idx){
        int mid=b+(e-b)/2;
        if (high <= b || low >= e) return 0;
        if(b>=low && e<=high) return tree[idx];
        return query(low,high,b,mid,2*idx+1)+query(low,high,mid,e,2*idx+2);
    }
    int update(int low,int high,int idx,int i,int val){
        int mid=low+(high-low)/2;
        if(high-low==1) tree[idx]=val;
        else if(i>=mid) tree[idx]=tree[2*idx+1]+update(mid,high,2*idx+2,i,val);
        else tree[idx]=tree[2*idx+2]+update(low,mid,2*idx+1,i,val);
        return tree[idx];
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        build(nums,0,n,0);
    }
    
    void update(int index, int val) {
        update(0,n,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(left,right+1,0,n,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */