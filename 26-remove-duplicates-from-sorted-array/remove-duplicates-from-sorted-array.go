func removeDuplicates(nums []int) int {
    c,i,j,n:=1,1,1,len(nums)
    for i<n && j<n{
        for j<n && nums[j]==nums[i-1]{
            j++
        }
        if j==n {
            break
        }
        nums[i]=nums[j]
        c++
        i++
    }
    return c
}