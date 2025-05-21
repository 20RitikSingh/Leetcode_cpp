var dp []int
func rec(nums []int,idx int) int {
    if idx==len(nums)-1{
        return 0
    }
    if dp[idx]!=0 {
        return dp[idx]
    }
    var ans int =1e9
    for i:=idx+1;i<idx+nums[idx]+1 && i<len(nums);i++{
        ans=min(ans,rec(nums,i))
    }
    dp[idx]=ans+1
    return ans+1
}
func jump(nums []int) int {
    if len(nums)==1{
        return 0
    }
    dp=make([]int,len(nums),len(nums))
    return rec(nums,0)
}