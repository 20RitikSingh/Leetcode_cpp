
func rec(nums []int,idx int,dp []int) bool {
    if idx==len(nums)-1{
        return true
    }
    if dp[idx]!=0 {
        return (dp[idx]-1)==2
    }
    for i:=idx+1;i<idx+nums[idx]+1;i++{
        if rec(nums,i,dp) {
            dp[idx]=2
            return true
        }
    }
    dp[idx]=1
    return false
}
func canJump(nums []int) bool {
    dp:=make([]int,1e4)
    return rec(nums,0,dp)
}