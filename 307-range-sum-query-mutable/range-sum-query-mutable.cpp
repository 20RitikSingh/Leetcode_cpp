struct SegmentTree{
    int Tree[100000];
    int build(vector<int> &nums,int low,int high,int idx){
        if(high==low) return Tree[idx]=nums[low];
        int mid=low+(high-low)/2;
        return Tree[idx]=build(nums,low,mid,2*idx+1)+build(nums,mid+1,high,2*idx+2);
    }
    int query(int low,int high,int l,int r,int idx=0){
        int m=l+(r-l)/2;
        if(low>r || high<l) return 0;
        if(low<=l && high>=r) return Tree[idx];
        return query(low,high,l,m,2*idx+1)+query(low,high,m+1,r,2*idx+2);
    }
    int update(int i,int val,int low,int high,int idx=0){
        if(low==high && low==i) return Tree[idx]=val;
        int mid=low+(high-low)/2;
        if(i<=mid) return Tree[idx]=update(i,val,low,mid,2*idx+1)+Tree[2*idx+2];
        else return Tree[idx]=Tree[2*idx+1]+update(i,val,mid+1,high,2*idx+2);
    }
};
class NumArray {
    int n;
    SegmentTree t;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        t.build(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        t.update(index,val,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return t.query(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */