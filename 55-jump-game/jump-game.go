var dp []int
func rec(nums []int,idx int) bool {
    if dp[idx]!=0 {
        return dp[idx]==2
    }
    for i:=idx+1;i<idx+nums[idx]+1;i++{
        if rec(nums,i) {
            dp[idx]=2
            return true
        }
    }
    dp[idx]=1
    return false
}
func canJump(nums []int) bool {
    dp=make([]int,len(nums),len(nums))
    dp[len(nums)-1]=2
    return rec(nums,0)
}