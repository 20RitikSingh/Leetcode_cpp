class NumArray {
    int seg[100001];
    int n;
    void build(vector<int> &nums,int l,int r,int idx){
        if(l==r){
            seg[idx]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(nums,l,mid,2*idx+1);
        build(nums,mid+1,r,2*idx+2);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int query(int idx,int l,int r,int ql,int qr){
        if(ql>r || qr<l) return 0; 
        if(l==ql && r==qr) return seg[idx];
        int mid=l+(r-l)/2;
        return query(2*idx+1,l,mid,ql,min(mid,qr))+query(2*idx+2,mid+1,r,max(ql,mid+1),qr);
    }
    int run(int idx,int l,int r,int pos,int val){
        if(l==r){
            if(l==pos) seg[idx]=val;
            return seg[idx];
        }
        int mid=l+(r-l)/2;
        if(pos<=mid){
            seg[idx]=run(2*idx+1,l,mid,pos,val)+seg[2*idx+2];
            return seg[idx];
        }
        seg[idx]=seg[2*idx+1]+run(2*idx+2,mid+1,r,pos,val);
        return seg[idx];
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        build(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        run(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */