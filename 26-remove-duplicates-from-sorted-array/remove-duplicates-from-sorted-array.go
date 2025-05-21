func removeDuplicates(nums []int) int {
    c,i,j,n:=0,0,0,len(nums)
    for i<n && j<n{
        nums[i]=nums[j]
        c++
        i++
        for j<n && nums[j]==nums[i-1]{
            j++
        }
    }
    return c
}